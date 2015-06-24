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

void cTitleState::HandleEvents(cGameEngine* game)
{
    SDL_Event e;
    while( SDL_PollEvent(&e) != 0)
    {
        if( e.type == SDL_QUIT )
        {
            game->Quit();
        }
    }
}

void cTitleState::Update(cGameEngine* game)
{
}

void cTitleState::Draw(cGameEngine* game)
{
    SDL_BlitSurface( background, NULL, SDL_GetWindowSurface(game->screen), NULL);
    SDL_UpdateWindowSurface(game->screen);

}
