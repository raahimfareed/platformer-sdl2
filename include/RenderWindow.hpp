#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
public:
    RenderWindow() = default;

    RenderWindow(const char* cpTitle, const int cWidth, const int cHeight, SDL_Color backgroundColor = {0, 0, 0});
    void create(const char* pTitle, const int cWidth, const int cHeight, SDL_Color backgroundColor = {0, 0, 0});
    SDL_Texture* pLoadTexture(const char* cpPath);
    void clear();
    void display();
    void cleanUp();

private:
    SDL_Window* mpWindow;
    SDL_Renderer* mpRenderer;
    SDL_Color mBackgroundColor;
};
