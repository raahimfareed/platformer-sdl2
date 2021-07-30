#pragma once

#include "Player.hpp"

class World
{
public:
    World();
    World(Player *pPlayer);
    Player *&rpGetPlayer();

private:
    Player *mpPlayer;
};