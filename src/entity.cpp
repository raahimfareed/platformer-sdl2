#include <SDL2/SDL.h>

#include "Entity.hpp"
#include "Math.hpp"

Entity::Entity() = default;

Entity::Entity(Vector2f position, SDL_Texture *pTexture, int width, int height, int x, int y)
    :mPosition(position), mpTexture(pTexture)
{
    mCurrentFrame.x = x;
    mCurrentFrame.y = y;
    mCurrentFrame.w = width;
    mCurrentFrame.h = height;
}

Vector2f &Entity::rGetPosition()
{
    return mPosition;
}

SDL_Texture *&Entity::rpGetTexture()
{
    return mpTexture;
}

SDL_Rect &Entity::rGetCurrentFrame()
{
    return mCurrentFrame;
}
