#include <cstdio>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "Game.hpp"
#include "RenderWindow.hpp"
#include "World.hpp"
#include "Menu.hpp"
#include "InputHandler.hpp"

Game::Game()
    :mpMenu(nullptr), mpWorld(nullptr), mpWindow(nullptr), mQuit(false)
{}

Game::Game(RenderWindow *pWindow, World *pWorld, Menu *pMenu)
    :mpWindow(pWindow), mpMenu(pMenu), mpWorld(pWorld), mQuit(false)
{}

void Game::setMenu(Menu *pMenu)
{
    mpMenu = pMenu;
}

void Game::setWorld(World *pWorld)
{
    mpWorld = pWorld;
}

void Game::setWindow(RenderWindow *pWindow)
{
    mpWindow = pWindow;
}

void Game::setQuit(bool quit)
{
    mQuit = quit;
}

SDL_Event &Game::rGetEvent()
{
    return mEvent;
}

World *&Game::rpGetWorld()
{
    return mpWorld;
}

Menu *&Game::rpGetMenu()
{
    return mpMenu;
}

RenderWindow *&Game::rpGetWindow()
{
    return mpWindow;
}

bool Game::isQuit() const
{
    return mQuit;
}

void Game::addTexture(const char* key, SDL_Texture *pTexture)
{
    mTextures[key] = pTexture;
}

void Game::addSound(const char* key, Mix_Chunk *pSound)
{
    mSounds[key] = pSound;
}

void Game::addMusic(const char* key, Mix_Music *pMusic)
{
    mMusic[key] = pMusic;
}

void Game::addFont(const char* key, TTF_Font *pFont)
{
    mFonts[key] = pFont;
}

Mix_Chunk* Game::getSound(const char* key)
{
    return mSounds[key];
}

Mix_Music* Game::getMusic(const char* key)
{
    return mMusic[key];
}

void Game::logic()
{
    if (InputHandler::isPressed(SDLK_LSHIFT) && InputHandler::isPressed(SDLK_RSHIFT))
    {
        mQuit = true;
    }

    if (SDL_GetTicks() < 10000)
    {
        if (SDL_GetTicks() > 3000 && SDL_GetTicks() <= 6000)
        {
            mpMenu->setMenuLevel(MenuLevel::StartCredits);
        }

        if (SDL_GetTicks() > 6000)
        {
            mpMenu->setMenuLevel(MenuLevel::Main);
        }
    }

    if (mpMenu->getDisplay() && mpMenu->getMenuLevel() == MenuLevel::Main)
    {
        if (InputHandler::isClicked(SDL_BUTTON_LEFT))
        {
            mpMenu->disableMenu();
        }
    }
}

void Game::render()
{
    mpWindow->clear();
    if (mpMenu->getDisplay())
    {
        mpMenu->show(*mpWindow, mFonts);
    }
    else
    {
        mpWindow->render(*mpWorld);
    }
    mpWindow->display();
}
