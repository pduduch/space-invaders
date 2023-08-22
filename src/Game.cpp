#include "../include/Game.h"

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

Game::Game()
    : m_Window(nullptr),
      m_Renderer(nullptr),
      m_ScreenHeight(480),
      m_ScreenWidth(640),
      m_IsRunning(false)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "Failed to initialize SDL! Error: " << SDL_GetError() << std::endl;
        return;
    }

    if (IMG_Init(IMG_INIT_PNG) < 0)
    {
        std::cerr << "Failed to initialize SDL_IMG! Error: " << IMG_GetError() << std::endl;
        return;
    }

    m_Window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_ScreenWidth, m_ScreenHeight, SDL_WINDOW_SHOWN);
    if (m_Window == nullptr)
    {
        std::cerr << "Failed to create window! Error: " << SDL_GetError() << std::endl;
        return;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_Renderer == nullptr)
    {
        std::cerr << "Failed to create renderer! Error: " << SDL_GetError() << std::endl;
        return;
    }
}

Game::~Game()
{
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    m_Renderer = nullptr;
    m_Window = nullptr;

    IMG_Quit();
    SDL_Quit();
}

void Game::Run()
{
    m_IsRunning = true;
    SDL_Event event;

    while (m_IsRunning)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            // TODO: Handle other inputs
            switch (event.type)
            {
            case SDL_QUIT:
                m_IsRunning = false;
                std::cout << "Game quitted!" << std::endl;
                break;
            default:
                break;
            }

            // Update game and stuff

            // Render stuff

            // profit
        }
    }
}
