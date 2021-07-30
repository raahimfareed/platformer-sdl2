#pragma once
#include <SDL2/SDL.h>

#include "Math.hpp"

class Entity
{
public:
    Entity();
    Entity(Vector2f position, SDL_Texture *pTexture, int width = 16, int height = 16, int x = 0, int y = 0);
    Vector2f &rGetPosition();
    SDL_Texture *&rpGetTexture();
    SDL_Rect &rGetCurrentFrame();

protected:
    Vector2f mPosition;
    SDL_Rect mCurrentFrame;
    SDL_Texture* mpTexture;
};
