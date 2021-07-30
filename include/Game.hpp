#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <map>

#include "RenderWindow.hpp"
#include "World.hpp"
#include "Menu.hpp"

class Game
{
public:
    Game();
    Game(RenderWindow *pWindow, World *pWorld, Menu *pMenu);
    void setMenu(Menu *pMenu);
    void setWorld(World *pWorld);
    void setWindow(RenderWindow *pWindow);
    void setQuit(bool quit);

    World *&rpGetWorld();
    Menu *&rpGetMenu();
    RenderWindow *&rpGetWindow();
    SDL_Event &rGetEvent();
    bool isQuit() const;


    void addTexture(const char* key, SDL_Texture *pTexture);
    void addSound(const char* key, Mix_Chunk *pSound);
    void addMusic(const char* key, Mix_Music *pMusic);
    void addFont(const char* key, TTF_Font *pFont);

    Mix_Chunk* getSound(const char* key);
    Mix_Music* getMusic(const char* key);

    void logic();
    void render();


private:
    SDL_Event mEvent;
    Menu *mpMenu;
    World *mpWorld;
    RenderWindow *mpWindow;
    std::map<char const*, SDL_Texture*> mTextures;
    std::map<char const*, Mix_Chunk*> mSounds;
    std::map<char const*, Mix_Music*> mMusic;
    std::map<char const*, TTF_Font*> mFonts;
    bool mQuit;
};
