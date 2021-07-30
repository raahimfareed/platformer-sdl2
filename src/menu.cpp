#include <cmath>

#include "Menu.hpp"
#include "RenderWindow.hpp"

Menu::Menu()
    :mDisplay(true), mLevel(MenuLevel::Title)
{}

void Menu::enableMenu()
{
    mDisplay = true;
}

void Menu::disableMenu()
{
    mDisplay = false;
}

void Menu::toggleMenu()
{
    mDisplay = !mDisplay;
}

bool Menu::getDisplay() const
{
    return mDisplay;
}

void Menu::setMenuLevel(MenuLevel level)
{
    mLevel = level;
}

MenuLevel Menu::getMenuLevel() const
{
    return mLevel;
}

void Menu::show(RenderWindow &rWindow, std::map<const char*, TTF_Font*> &rpFonts)
{
    switch (mLevel)
    {
    case MenuLevel::Title:
        rWindow.renderCenter(Vector2f(0, std::sin(SDL_GetTicks() / 100)), "TEH GAYM", rpFonts["special-elite-32"], {255, 255, 255});
        break;
    case MenuLevel::StartCredits:
        rWindow.renderCenter(Vector2f(0, std::sin(SDL_GetTicks() / 100)), "Made By Raahim", rpFonts["special-elite-16"], {255, 255, 255});
        break;
    case MenuLevel::Main:
        rWindow.renderCenter(Vector2f(0, std::sin(SDL_GetTicks() / 100)), "Click to continue", rpFonts["special-elite-16"], {255, 255, 255});
        break;
    }
}

