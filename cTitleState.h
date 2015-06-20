// Matthew Holmes
// cTitleState.h

#ifndef TITLE_STATE
#define TITLE_STATE

#include "SDL.h"
#include "cGameState.h"

class cTitleState : public cGameState
{
  public:
    void Init();
    void Cleanup();
    
    void Pause();
    void Resume();

    void HandleEvents(cGameEngine* game);
    void Update(cGameEngine* game);
    void Draw(cGameEngine* game);

    static cTitleState* Instance()
    {
        return &m_TitleState;
    }
    
  protected:
    cTitleState() {}

  private:
    static cTitleState m_TitleState;

    SDL_Surface* background;
};

#endif

