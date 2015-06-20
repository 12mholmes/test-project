// Matthew Holmes
// cGameEngine.h

#ifndef GAME_ENG
#define GAME_ENG

#include "SDL.h"
#include <stack>

class CGameState;

class cGameEngine
{
public:
    void Init();
    void Cleanup();

    void ChangeState(cGameState* state);
    void PushState(cGameState* state);
    void PopState();

    void HandleEvents();
    void Update();
    void Draw();

    bool Running() { return m_running; }
    void Quit() { m_running = false; }

    SDL_Window* screen;

private:
    std::stackr<cGameState*> states;

    bool m_running;
};

#endif
