// Matthew Holmes
// cGameState.h

#ifndef GAME_STATE
#define GAME_STATE

#include "cGameEngine.h"

class cGameState
{
  public:
    virtual void Init() = 0;
    virtual void Cleanup() = 0;

    virtual void Pause() = 0;
    virtual void Resume() = 0;

    virtual void HandleEvents(cGameEngine* game) = 0;
    virtual void Update(cGameEngine* game) = 0;
    virtual void Draw(cGameEngine* game) = 0;

    void ChangeState(cGameEngine* game, cGameState* state)
    {
        game->ChangeState(state);
    }

  protected:
    cGameState() {}
};

#endif

