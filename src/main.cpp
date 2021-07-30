#include <cstdio>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Config.hpp"
#include "RenderWindow.hpp"
#include "Player.hpp"
#include "Menu.hpp"
#include "Game.hpp"
#include "World.hpp"
#include "InputHandler.hpp"

RenderWindow gWindow;
Menu gMenu;
World gWorld;
Player gPlayer;
Game *gpGame;

bool init();
void mainLoop();
void cleanUp();
double hireTimeInSeconds();
bool gInit = init();

static const double gcDeltaTime = 0.01f;
static double gAccumulator = 0.0f;
static double gCurrentTime = hireTimeInSeconds();
static double gOneSecond = 0;
static int gFramesRenderedInOneSecond = 0;


int main(int argc, char* args[])
{
    if (!gInit)
    {
        printf("Program failed to initialize!\n");
        cleanUp();
        return EXIT_FAILURE;
    }

    mainLoop();

    cleanUp();
    return 0;
}

bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) > 0)
    {
        printf("[Error]: SDL Init failed\n[SDL Error]: %s\n", SDL_GetError());
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        printf("[Error]: IMG Init failed\n[SDL Error]: %s\n", SDL_GetError());
        return false;
    }

    if (TTF_Init() == -1)
    {
        printf("[Error]: TTF Init failed\n[SDL Error]: %s\n", SDL_GetError());
    }

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    gWindow = RenderWindow(Config::mTitle, Config::mScreenWidth, Config::mScreenHeight);
    
    SDL_Texture *pPlayerTexture = gWindow.pLoadTexture("res/player/p1.png");
    gPlayer = Player(pPlayerTexture);
    gWorld = World(&gPlayer);

    gMenu = Menu();

    gpGame = new Game(&gWindow, &gWorld, &gMenu);
    gpGame->addTexture("player", pPlayerTexture);
    gpGame->addFont("special-elite-32", TTF_OpenFont("res/fonts/SpecialElite-Regular.ttf", 32));
    gpGame->addFont("special-elite-16", TTF_OpenFont("res/fonts/SpecialElite-Regular.ttf", 16));
    gpGame->addMusic("a-bit-of-hope", Mix_LoadMUS("res/sounds/ABitOfHope-DavidFesliyan.wav"));

    // SDL_ShowCursor(SDL_DISABLE);

    return true;
}

void mainLoop()
{
    Mix_PlayMusic(gpGame->getMusic("a-bit-of-hope"), -1);
    while (!gpGame->isQuit())
    {
        double newTime = hireTimeInSeconds();
        double frameTime = newTime - gCurrentTime;

        if (frameTime > 0.25f)
        {
            frameTime = 0.0f;
        }

        gCurrentTime = newTime;

        gAccumulator += frameTime;
        gOneSecond += frameTime;

        while (gAccumulator >= gcDeltaTime)
        {
            while (SDL_PollEvent(&gpGame->rGetEvent()))
            {
                switch(gpGame->rGetEvent().type)
                {
                    case SDL_QUIT:
                        gpGame->setQuit(true);
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        InputHandler::handleMouseClick(gpGame->rGetEvent());
                        break;
                    case SDL_MOUSEBUTTONUP:
                        InputHandler::handleMouseRelease(gpGame->rGetEvent());
                        break;
                    case SDL_KEYDOWN:
                        InputHandler::handleKeyPress(gpGame->rGetEvent());
                        break;
                    case SDL_KEYUP:
                        InputHandler::handleKeyRelease(gpGame->rGetEvent());
                        break;
                }
            }
            gAccumulator -= gcDeltaTime;
            gpGame->logic();
        }

        gpGame->render();

        const double alpha = gAccumulator / gcDeltaTime;

        gFramesRenderedInOneSecond++;
    }
}

void cleanUp()
{
    delete gpGame;
    IMG_Quit();
    SDL_Quit();
}

double hireTimeInSeconds()
{
    double time = SDL_GetTicks();
    time *= 0.001f;
    return time;
}
