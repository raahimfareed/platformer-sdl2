#include <SDL2/SDL.h>

#include "Config.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Math.hpp"

Player::Player()
    :mLives(3)
{}

Player::Player(SDL_Texture *pTexture, int width, int height, int x, int y)
    :mLives(3)
{
    mpTexture = pTexture;
    mCurrentFrame.x = x;
    mCurrentFrame.y = y;
    mCurrentFrame.w = width;
    mCurrentFrame.h = height;

    mPosition.mX = (Config::mScreenWidth / 2) - (width / 2);
    mPosition.mY = (Config::mScreenHeight / 2) - (height / 2);
}

Player::Player(Vector2f position, SDL_Texture *pTexture, int width, int height, int x, int y)
    :Entity(position, pTexture, width, height, x, y), mLives(3)
{}

int Player::getLives() const
{
    return mLives;
}

void Player::setLives(int lives)
{
    mLives = lives;
}
