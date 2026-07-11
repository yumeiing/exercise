#include <SDL2/SDL.h>

#define WIDTH 480
#define HEIGHT 320
#define FPS 30

int main(int argc,char* argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("SDL init failed: %s",SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("sdl-window",
        SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
        WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
    
    if(!window)
    {
        SDL_Log("window init failed: %s",SDL_GetError());
        return 1;
    }

    SDL_Renderer* render = SDL_CreateRenderer(window,-1,0);

    if(!render)
    {
        SDL_Log("render init failed: %s",SDL_GetError());
        return 1;
    }

    bool running = 1;
    SDL_Event event;
    while(running)
    {
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running=0;
                continue;
            
            //handle events
            
            default:
                break;
            }
        }

        //update

        SDL_SetRenderDrawColor(render,0x00,0x00,0x00,0xff);
        SDL_RenderClear(render);

        //render

        SDL_RenderPresent(render);
    }
    
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}