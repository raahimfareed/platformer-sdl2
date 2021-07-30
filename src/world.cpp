#include "World.hpp"
#include "Player.hpp"

World::World()
    :mpPlayer(nullptr)
{}

World::World(Player *pPlayer)
    :mpPlayer(pPlayer)
{}

Player *&World::rpGetPlayer()
{
    return mpPlayer;
}
