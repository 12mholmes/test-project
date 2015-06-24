// Matthew Holmes
// cGameEngine.h

#ifndef GAME_ENG
#define GAME_ENG

#include "SDL.h"
#include <stack>

class cGameState;

class cGameEngine
{
public:
    void Init(const char* title, unsigned int width, unsigned int height);
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
    std::stack<cGameState*> states;

    bool m_running;
};

#endif
