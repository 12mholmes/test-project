// Matthew Holmes
// cGameEngine.cpp

#include <stdio.h>
#include <SDL.h>
#include "cGameEngine.h"
#include "cGameState.h"

void cGameEngine::Init(const char* title, unsigned int width, unsigned int height)
{
    SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_CreateWindow("Test Project", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, width, height, 0);

    m_running = true;
    printf("Engine Init\n");
}

void cGameEngine::Cleanup()
{
    while( !states.empty() )
    {
        states.top()->Cleanup();
        states.pop();
    }

    printf("Engine Cleanup\n");
    SDL_Quit();
}

void cGameEngine::ChangeState(cGameState* state)
{
    if( !states.empty() )
    {
        states.top()->Cleanup();
        states.pop();
    }
    states.push(state);
    states.top()->Init();
}

void cGameEngine::PushState(cGameState* state)
{
    if( !states.empty() )
    {
        states.top()->Pause();
    }

    states.push(state);
    states.top()->Init();
}

void cGameEngine::PopState()
{
    if( !states.empty() )
    {
        states.top()->Cleanup();
        states.pop();
    }

    if( !states.empty() )
    {
        states.top()->Resume();
    }
}

void cGameEngine::HandleEvents()
{
    states.top()->HandleEvents(this);
}

void cGameEngine::Update()
{
    states.top()->Update(this);
}

void cGameEngine::Draw()
{
    states.top()->Draw(this);
}
