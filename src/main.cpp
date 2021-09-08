#include "declaration.hpp"

int main(int argc , char **argv)
    {

    long long begin ;
    
    int end ;
    
        SDL_Init(SDL_INIT_VIDEO);

        g_window = SDL_CreateWindow("tirere",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                1280,
                                720,
                                SDL_WINDOW_FULLSCREEN);
        if (g_window == NULL)
            {
                SDL_Quit();
                return -1 ;
            }
        
        g_render = SDL_CreateRenderer(g_window , -1 , 0);

        if(g_render == NULL)
            {
                SDL_DestroyWindow(g_window);
                SDL_Quit();
                return -1 ;
            }
        init_texture();

        while(g_program_is_running)
            {
                begin = SDL_GetTicks();

                update_render();

                end = SDL_GetTicks() - begin ;
                if(end < 1000 / 30)
                    SDL_Delay(1000 / 30 - end);
            }
        clear_texture();
        SDL_DestroyRenderer(g_render);
        SDL_DestroyWindow(g_window);
        SDL_Quit();
        return 0 ;
    }