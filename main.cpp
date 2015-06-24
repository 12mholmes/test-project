// Matthew Holmes
// main.cpp

#include "cGameEngine.h"
#include "cTitleState.h"

int main(int argc, char* argv[])
{
    cGameEngine game;

    game.Init("Test Project", 800, 600);
    game.ChangeState(cTitleState::Instance());

    while( game.Running() )
    {
        game.HandleEvents();
        game.Update();
        game.Draw();
        SDL_Delay(30);
    }

    game.Cleanup();
    
    return 0;
}
