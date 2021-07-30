#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


#include <map>

#include "RenderWindow.hpp"

enum class MenuLevel
{
    Title,
    StartCredits,
    Main,
    Pause,
    Death
};

class Menu
{
public:
    Menu();

    void enableMenu();
    void disableMenu();
    void toggleMenu();

    bool getDisplay() const;

    void setMenuLevel(MenuLevel level);
    MenuLevel getMenuLevel() const;

    void show(RenderWindow &rWindow, std::map<const char*, TTF_Font*> &rpFonts);

private:
    bool mDisplay;
    MenuLevel mLevel;
};
