#pragma once
#include <SDL2/SDL.h>

#include "Entity.hpp"
#include "Math.hpp"

class Player: public Entity
{
public:
    Player();
    Player(SDL_Texture *pTexture, int width = 16, int height = 16, int x = 0, int y = 0);
    Player(Vector2f position, SDL_Texture *pTexture, int width = 16, int height = 16, int x = 0, int y = 0);

    int getLives() const;
    void setLives(int lives);

private:
    int mLives;
};
