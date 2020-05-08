#include "src/Application/GameWindowHandler.h"

#include "Arcomage/Arcomage.h"

#include "Engine/Engine.h"
#include "Engine/Graphics/IndoorCameraD3D.h"
#include "Engine/Graphics/Viewport.h"
#include "Engine/Graphics/Vis.h"
#include "Engine/IocContainer.h"
#include "Engine/Party.h"
#include "Engine/Time.h"

#include "GUI/GUIWindow.h"

#include "Io/InputAction.h"
#include "Io/KeyboardInputHandler.h"
#include "Io/Mouse.h"

#include "Media/Audio/AudioPlayer.h"
#include "Media/MediaPlayer.h"

#include "src/Application/IocContainer.h"


using EngineIoc = Engine_::IocContainer;
using ApplicationIoc = Application::IocContainer;
using Application::GameWindowHandler;
using Io::InputAction;


GameWindowHandler::GameWindowHandler() {
    this->mouse = EngineIoc::ResolveMouse();
}

void GameWindowHandler::OnScreenshot() {
    if (render) {
        render->SavePCXScreenshot();
    }
}

bool GameWindowHandler::OnChar(GameKey key, int c) {
    bool textInputHandled = false;

    // backspace, enter, esc (text input), controls binding
    textInputHandled |= keyboardInputHandler->ProcessTextInput(key, c);

    // regular text input
    textInputHandled |= keyboardInputHandler->ProcessTextInput(GameKey::Char, c);

    if (!textInputHandled && !viewparams->field_4C) {
        return GUI_HandleHotkey(key); // try other hotkeys
    }
    return false;
}

void GameWindowHandler::OnMouseLeftClick(int x, int y) {
    if (pArcomageGame->bGameInProgress) {
        pArcomageGame->stru1.am_input_type = 7;
        pArcomageGame->check_exit = 0;
        pArcomageGame->force_redraw_1 = 1;
        ArcomageGame::OnMouseClick(0, true);
    } else {
        pMediaPlayer->StopMovie();

        mouse->SetMouseClick(x, y);

        if (GetCurrentMenuID() == MENU_CREATEPARTY) {
            UI_OnKeyDown(GameKey::Select);
        }

        if (engine) {
            engine->PickMouse(512.0, x, y, false, &vis_sprite_filter_3, &vis_door_filter);
        }

        mouse->UI_OnMouseLeftClick();
    }
}

void GameWindowHandler::OnMouseRightClick(int x, int y) {
    if (pArcomageGame->bGameInProgress) {
        pArcomageGame->stru1.am_input_type = 8;
        pArcomageGame->check_exit = 0;
        pArcomageGame->force_redraw_1 = 1;
        ArcomageGame::OnMouseClick(1, true);
    } else {
        pMediaPlayer->StopMovie();

        mouse->SetMouseClick(x, y);

        if (engine) {
            engine->PickMouse(pIndoorCameraD3D->GetPickDepth(), x, y, 0, &vis_sprite_filter_2, &vis_door_filter);
        }

        UI_OnMouseRightClick(x, y);
    }
}

void GameWindowHandler::OnMouseLeftUp() {
    if (pArcomageGame->bGameInProgress) {
        pArcomageGame->stru1.am_input_type = 3;
        ArcomageGame::OnMouseClick(0, 0);
    } else {
        back_to_game();
    }
}

void GameWindowHandler::OnMouseRightUp() {
    if (pArcomageGame->bGameInProgress) {
        pArcomageGame->stru1.am_input_type = 4;
        ArcomageGame::OnMouseClick(1, false);
    } else {
        back_to_game();
    }
}

void GameWindowHandler::OnMouseLeftDoubleClick(int x, int y) {
    if (pArcomageGame->bGameInProgress) {
        pArcomageGame->stru1.am_input_type = 7;
    } else {
        OnMouseLeftClick(x, y);
    }
}

void GameWindowHandler::OnMouseRightDoubleClick(int x, int y) {
    if (pArcomageGame->bGameInProgress) {
        pArcomageGame->stru1.am_input_type = 8;
    } else {
        OnMouseRightClick(x, y);
    }
}

void GameWindowHandler::OnMouseMove(int x, int y, bool left_button, bool right_button) {
    if (pArcomageGame->bGameInProgress) {
        ArcomageGame::OnMouseMove(x, y);
        ArcomageGame::OnMouseClick(0, left_button);
        ArcomageGame::OnMouseClick(1, right_button);
    } else {
        if (mouse) {
            mouse->SetMouseClick(x, y);
        }
    }
}

void GameWindowHandler::OnKey(GameKey key) {
    extern InputAction currently_selected_action_for_binding;
    if (currently_selected_action_for_binding != InputAction::Invalid) {
        // we're setting a key binding in options
        keyboardInputHandler->ProcessTextInput(key, -1);
    } else if (pArcomageGame->bGameInProgress) {
        pArcomageGame->stru1.am_input_type = 1;

        set_stru1_field_8_InArcomage(0);
        if (key == GameKey::Escape) {
            pArcomageGame->stru1.am_input_type = 10;
        } else if (pArcomageGame->check_exit) {
           pArcomageGame->check_exit = 0;
           pArcomageGame->force_redraw_1 = 1;
        }

        if (key == GameKey::F3) {
            OnScreenshot();
        } else if (key == GameKey::F4 && !pMovie_Track) {
            OnToggleFullscreen();
            pArcomageGame->stru1.am_input_type = 9;
        }
    } else {
        pMediaPlayer->StopMovie();
        if (key == GameKey::Return) {
            if (!viewparams->field_4C) UI_OnKeyDown(key);
        } else if (key == GameKey::Control) {
            extern bool _507B98_ctrl_pressed;
            _507B98_ctrl_pressed = true;
        } else if (key == GameKey::Escape) {
            pMessageQueue_50CBD0->AddGUIMessage(UIMSG_Escape, window_SpeakInHouse != 0, 0);
        } else if (key == GameKey::F4 && !pMovie_Track) {
            OnToggleFullscreen();
        } else if (key == GameKey::Numpad0) {
            pMessageQueue_50CBD0->AddGUIMessage(UIMSG_OpenDebugMenu, window_SpeakInHouse != 0, 0);
        } else if (key == GameKey::Left || key == GameKey::Right || key == GameKey::Up || key == GameKey::Down) {
            if (current_screen_type != CURRENT_SCREEN::SCREEN_GAME &&
                current_screen_type != CURRENT_SCREEN::SCREEN_MODAL_WINDOW) {
                if (!viewparams->field_4C) {
                    UI_OnKeyDown(key);
                }
            }
        }
    }
}

void GameWindowHandler::OnFocus() {
    __debugbreak();
}

void GameWindowHandler::OnFocusLost() {
    __debugbreak();
}

void GameWindowHandler::OnPaint() {
    if (pArcomageGame->bGameInProgress) {
        pArcomageGame->force_redraw_1 = 1;
    }
    if (render && render->AreRenderSurfacesOk()) {
        render->Present();
    }
}

void GameWindowHandler::OnActivated() {
    if (dword_6BE364_game_settings_1 & GAME_SETTINGS_APP_INACTIVE) {
        // dword_4E98BC_bApplicationActive = 1;
        //        Resume video playback
        //          pMediaPlayer->
        //          if (pMovie_Track)
        //            pMediaPlayer->bPlaying_Movie = true;

        dword_6BE364_game_settings_1 &= ~GAME_SETTINGS_APP_INACTIVE;

        if (pArcomageGame->bGameInProgress) {
            pArcomageGame->force_redraw_1 = 1;
        } else {
            if (dword_6BE364_game_settings_1 & GAME_SETTINGS_0200_EVENT_TIMER)
                dword_6BE364_game_settings_1 &= ~GAME_SETTINGS_0200_EVENT_TIMER;
            else
                pEventTimer->Resume();
            if (dword_6BE364_game_settings_1 & GAME_SETTINGS_0400_MISC_TIMER)
                dword_6BE364_game_settings_1 &= ~GAME_SETTINGS_0400_MISC_TIMER;
            else
                pMiscTimer->Resume();

            viewparams->bRedrawGameUI = true;
            if (pMovie_Track) {  // pVideoPlayer->pSmackerMovie )
                render->RestoreFrontBuffer();
                render->RestoreBackBuffer();
                // BackToHouseMenu();
            }
        }

        if (!bGameoverLoop && !pMovie_Track) {  // continue an audio track
            pAudioPlayer->MusicResume();
        }
    }
}

void GameWindowHandler::OnDeactivated() {
    if (!(dword_6BE364_game_settings_1 & GAME_SETTINGS_APP_INACTIVE)) {
        // dword_4E98BC_bApplicationActive = 0;

        dword_6BE364_game_settings_1 |= GAME_SETTINGS_APP_INACTIVE;
        if (pEventTimer != nullptr) {
            if (pEventTimer->bPaused)
                dword_6BE364_game_settings_1 |= GAME_SETTINGS_0200_EVENT_TIMER;
            else
                pEventTimer->Pause();
        }

        if (pMiscTimer != nullptr) {
            if (pMiscTimer->bPaused)
                dword_6BE364_game_settings_1 |= GAME_SETTINGS_0400_MISC_TIMER;
            else
                pMiscTimer->Pause();
        }

        if (pAudioPlayer != nullptr) {
            pAudioPlayer->StopChannels(-1, -1);
            pAudioPlayer->MusicPause();
        }
    }
}

void GameWindowHandler::OnToggleFullscreen() {
    __debugbreak();
}
