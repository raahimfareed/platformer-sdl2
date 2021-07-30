#include <SDL2/SDL.h>
#include <map>

#include "InputHandler.hpp"

std::map<SDL_Keycode, bool> InputHandler::mpKeyState;
std::map<Uint8, bool> InputHandler::mpMouseState;

void InputHandler::handleKeyPress(SDL_Event &rEvent)
{
    mpKeyState[rEvent.key.keysym.sym] = true;
}

void InputHandler::handleKeyRelease(SDL_Event &rEvent)
{
    mpKeyState[rEvent.key.keysym.sym] = false;
}

void InputHandler::handleMouseClick(SDL_Event &rEvent)
{
    mpMouseState[rEvent.button.button] = true;
}

void InputHandler::handleMouseRelease(SDL_Event &rEvent)
{
    mpMouseState[rEvent.button.button] = false;
}

bool InputHandler::isPressed(const SDL_Keycode key)
{
    if (mpKeyState.count(key))
    {
        return mpKeyState[key];
    }

    return false;
}

bool InputHandler::isClicked(const Uint8 key)
{
    if (mpMouseState.count(key))
    {
        return mpMouseState[key];
    }

    return false;
}
