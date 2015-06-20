// Matthew Holmes
// main.cpp

#include "cGameEngine.h"
#include "cTitleState.h"

int main(int argc, char* argv[])
{
    cGameEngine game;

    game.Init("Test Project", 600, 800);
    game.ChangeState(cTitleState::Instance());

    while( game.Running() )
    {
        game.HandleEvents();
        game.Update();
        game.Draw();
        SDL_Delay(10);
    }

    game.Cleanup();
    
    return 0;
}
