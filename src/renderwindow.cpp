#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <cstdio>

#include "Config.hpp"
#include "RenderWindow.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow()
    :mpWindow(nullptr), mpRenderer(nullptr), mBackgroundColor({0, 0, 0})
{}

RenderWindow::RenderWindow(const char* cpTitle, const int cWidth, const int cHeight, SDL_Color backgroundColor)
    :mpWindow(nullptr), mpRenderer(nullptr), mBackgroundColor(backgroundColor)
{
    mpWindow = SDL_CreateWindow(cpTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, cWidth, cHeight, SDL_WINDOW_SHOWN);

    if (mpWindow == nullptr)
    {
        printf("[Error]: Failed to create a window\n[SDL Error]: %s\n", SDL_GetError());
        return;
    }

    mpRenderer = SDL_CreateRenderer(mpWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (mpRenderer == nullptr)
    {
        printf("[Error]: Failed to create a renderer\n[SDL Error]: %s\n", SDL_GetError());
    }
}

void RenderWindow::create(const char* cpTitle, const int cWidth, const int cHeight, SDL_Color backgroundColor)
{
    mBackgroundColor = backgroundColor;
    mpWindow = SDL_CreateWindow(cpTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, cWidth, cHeight, SDL_WINDOW_SHOWN);

    if (mpWindow == nullptr)
    {
        printf("[Error]: Failed to create a window\n[SDL Error]: %s\n", SDL_GetError());
        return;
    }

    mpRenderer = SDL_CreateRenderer(mpWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (mpRenderer == nullptr)
    {
        printf("[Error]: Failed to create a renderer\n[SDL Error]: %s\n", SDL_GetError());
    }
}

SDL_Texture* RenderWindow::pLoadTexture(const char* cpPath)
{
    SDL_Texture* pTexture = nullptr;

    pTexture = IMG_LoadTexture(mpRenderer, cpPath);

    if (pTexture == nullptr)
    {
        printf("[Error]: Failed to load texture\n[SDL Error]: %s\n", SDL_GetError());
    }

    return pTexture;
}

void RenderWindow::render(World &rWorld)
{
    render(*rWorld.rpGetPlayer());
}

void RenderWindow::render(SDL_Texture* pTexture, int srcX, int srcY, int dstX, int dstY)
{
    SDL_Rect source;
    source.x = srcX;
    source.y = srcY;
    source.w = 64;
    source.h = 64;

    SDL_Rect destination;
    destination.x = dstX;
    destination.y = dstY;
    destination.w = 64;
    destination.h = 64;

    SDL_RenderCopy(mpRenderer, pTexture, &source, &destination);
}

void RenderWindow::render(Entity &rEntity)
{
    SDL_Rect source;
    source.x = rEntity.rGetCurrentFrame().x;
    source.y = rEntity.rGetCurrentFrame().y;
    source.w = rEntity.rGetCurrentFrame().w;
    source.h = rEntity.rGetCurrentFrame().h;
    
    SDL_Rect destination;
    destination.x = rEntity.rGetPosition().mX;
    destination.y = rEntity.rGetPosition().mY;
    destination.w = rEntity.rGetCurrentFrame().w;
    destination.h = rEntity.rGetCurrentFrame().h;

    SDL_RenderCopy(mpRenderer, rEntity.rpGetTexture(), &source, &destination);
}

void RenderWindow::render(Vector2f position, const char* pText, TTF_Font* pFont, SDL_Color color)
{
    SDL_Surface* pSurfaceMessage = TTF_RenderText_Blended(pFont, pText, color);
    SDL_Texture* pMessage = SDL_CreateTextureFromSurface(mpRenderer,  pSurfaceMessage);

    SDL_Rect source;
    source.x = 0;
    source.y = 0;
    source.w = pSurfaceMessage->w;
    source.h = pSurfaceMessage->h;

    SDL_Rect destination;
    destination.x = position.mX;
    destination.y = position.mY;
    destination.w = source.w;
    destination.h = source.h;

    SDL_RenderCopy(mpRenderer, pMessage, &source, &destination);
    SDL_FreeSurface(pSurfaceMessage);
}

void RenderWindow::renderCenter(Vector2f position, const char* pText, TTF_Font* pFont, SDL_Color color)
{
    SDL_Surface* pSurfaceMessage = TTF_RenderText_Blended(pFont, pText, color);
    SDL_Texture* pMessage = SDL_CreateTextureFromSurface(mpRenderer, pSurfaceMessage);

    SDL_Rect source;
    source.x = 0;
    source.y = 0;
    source.w = pSurfaceMessage->w;
    source.h = pSurfaceMessage->h;

    SDL_Rect destination;
    destination.x = Config::mScreenWidth/2 - source.w/2 + position.mX;
    destination.y = Config::mScreenHeight/2 - source.h/2 + position.mY;
    destination.w = source.w;
    destination.h = source.h;

    SDL_RenderCopy(mpRenderer, pMessage, &source, &destination);
    SDL_FreeSurface(pSurfaceMessage);
}

void RenderWindow::display()
{
    SDL_RenderPresent(mpRenderer);
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(mpWindow);
}

void RenderWindow::clear()
{
    SDL_SetRenderDrawColor(mpRenderer, mBackgroundColor.r, mBackgroundColor.g, mBackgroundColor.b, mBackgroundColor.a);
    SDL_RenderClear(mpRenderer);
}
