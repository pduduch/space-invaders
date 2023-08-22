#ifndef GAME_H_
#define GAME_H_

#include "Uncopyable.h"

class Game final: private Uncopyable
{
public:
    Game();
    ~Game();

    void Run();
        

private:
    struct SDL_Window* m_Window;
    struct SDL_Renderer* m_Renderer;
    const int m_ScreenHeight;
    const int m_ScreenWidth;
    bool m_IsRunning;
};

#endif // GAME_H_