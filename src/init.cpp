#include "init.hpp"

bool g_program_is_running = true ;

SDL_Window *g_window = NULL;

SDL_Renderer *g_render = NULL ;

Ball_and_raquette g_ball_and_raquette ;

Texture score0 ;

Texture score1 ;

Texture score2 ;

Texture score3 ;

Texture score4 ;

Texture score5 ;

Texture score6 ;

Texture score7 ;

Texture score8 ;

Texture score9 ;

void init_texture()
    {
        g_ball_and_raquette.init_ball_and_raquette();

        score0.new_texture("picture/0.bmp" , 0 , 0);
        score1.new_texture("picture/1.bmp" , 0 , 0);
        score2.new_texture("picture/2.bmp" , 0 , 0);
        score3.new_texture("picture/3.bmp" , 0 , 0);
        score4.new_texture("picture/4.bmp" , 0 , 0);
        score5.new_texture("picture/5.bmp" , 0 , 0);
        score6.new_texture("picture/6.bmp" , 0 , 0);
        score7.new_texture("picture/7.bmp" , 0 , 0);
        score8.new_texture("picture/8.bmp" , 0 , 0);
        score9.new_texture("picture/9.bmp" , 0 , 0);
    }

void clear_texture()
    {
        g_ball_and_raquette.clear();
    }