#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "RenderWindow.hpp"

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

void RenderWindow::clear()
{
    SDL_SetRenderDrawColor(mpRenderer, mBackgroundColor.r, mBackgroundColor.g, mBackgroundColor.b, mBackgroundColor.a);
    SDL_RenderClear(mpRenderer);
}
