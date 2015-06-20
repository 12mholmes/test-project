// Matthew Holmes
// cTitleState.cpp

#include <stdio.h>
#include "SDL.h"
#include "cGameEngine.h"
#include "cGameState.h"
#include "cTitleState.h"

cTitleState cTitleState::m_TitleState;

void cTitleState::Init()
{
    background = SDL_LoadBMP("resources/title.bmp");
    printf("cTitleState Init\n");
}

void cTitleState::Cleanup()
{
    SDL_FreeSurface(background);
    background = NULL;

    printf("cTitleState Cleanup\n");
}

void cTitleState::Pause()
{
    printf("cTitleState Pause\n");
}

void cTitleState::Resume()
{
    printf("cTitleState Resume\n");
}

void cIntroState::HandleEvents(cGameEngine* game)
{
}

void cIntroState::Update(cGameEngine* game)
{
}

void cIntroState::Draw(cGameEngine* game)
{
    SDL_BlitSurface( background, NULL, game->screen, NULL);
    SDL_UpdateWindowSurface(game->screen);

}
