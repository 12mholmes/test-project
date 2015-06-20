// Matthew Holmes
// cGameState.h

#ifndef GAME_STATE
#define GAME_STATE

#include "cGameEngine.h"

class cGameState
{
  public:
    virtual void Init();
    virtual void Cleanup();

    virtual void Pause();
    virtual void Resume();

    virtual void HandleEvents(cGameEngine* game);
    virtual void Update(cGameEngine* game);
    virtual void Draw(cGameEngine* game);

    void ChangeState(cGameEngine* game, cGameState* state)
    {
        game->ChangeState(state);
    }

  protected:
    cGameState() {}
};

#endif

