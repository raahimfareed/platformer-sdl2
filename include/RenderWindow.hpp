#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "World.hpp"
#include "Entity.hpp"

class RenderWindow
{
public:
    RenderWindow();
    RenderWindow(const char* cpTitle, const int cWidth, const int cHeight, SDL_Color backgroundColor = {0, 0, 0});
    void create(const char* pTitle, const int cWidth, const int cHeight, SDL_Color backgroundColor = {0, 0, 0});
    SDL_Texture* pLoadTexture(const char* cpPath);
    void render(World &rWorld);
    void render(SDL_Texture* pTexture, int dstX = 0, int dstY = 0, int srcX = 0, int srcY = 0);
    void render(Entity &rEntity);
    void render(Vector2f position, const char* pText, TTF_Font* pFont, SDL_Color color);
    void renderCenter(Vector2f position, const char* pText, TTF_Font* pFont, SDL_Color color);
    void clear();
    void display();
    void cleanUp();

private:
    SDL_Window* mpWindow;
    SDL_Renderer* mpRenderer;
    SDL_Color mBackgroundColor;
};
