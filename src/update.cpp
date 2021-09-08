#include "update.hpp"

SDL_Event event ;

extern Ball_and_raquette g_ball_and_raquette ;

extern Texture score0 ;

extern Texture score1 ;

extern Texture score2 ;

extern Texture score3 ;

extern Texture score4 ;

extern Texture score5 ;

extern Texture score6 ;

extern Texture score7 ;

extern Texture score8 ;

extern Texture score9 ;

void update_render()
    {
        update_event();
        
        g_ball_and_raquette.update_ball_and_raquette();

        draw_rect(255,255,255,255,1280/2,0,1,720);

        if(g_ball_and_raquette.get_score_left() == 0)
            {
                score0.set_xy(320 - 19 , 30);
                score0.print_texture();
            }
        if(g_ball_and_raquette.get_score_left() == 1)
            {
                score1.set_xy(320 - 19 , 30);
                score1.print_texture();
            }
        if(g_ball_and_raquette.get_score_left() == 2)
            {
                score2.set_xy(320 - 19 , 30);
                score2.print_texture();
            }
        if(g_ball_and_raquette.get_score_left() == 3)
            {
                score3.set_xy(320 - 19 , 30);
                score3.print_texture();
            }
        if(g_ball_and_raquette.get_score_left() == 4)
            {
                score4.set_xy(320 - 19 , 30);
                score4.print_texture();
            }
        if(g_ball_and_raquette.get_score_left() == 5)
            {
                score5.set_xy(320 - 19 , 30);
                score5.print_texture();
            }
        if(g_ball_and_raquette.get_score_left() == 6)
            {
                score6.set_xy(320 - 19 , 30);
                score6.print_texture();
            }
        if(g_ball_and_raquette.get_score_left() == 7)
            {
                score7.set_xy(320 - 19 , 30);
                score7.print_texture();
            }
        if(g_ball_and_raquette.get_score_left() == 8)
            {
                score8.set_xy(320 - 19 , 30);
                score8.print_texture();
            }
        if(g_ball_and_raquette.get_score_left() == 9)
            {
                score9.set_xy(320 - 19 , 30);
                score9.print_texture();
            }
        if(g_ball_and_raquette.get_score_left() == 10)
            g_program_is_running = false ;




        if(g_ball_and_raquette.get_score_rite() == 0)
            {
                score0.set_xy(960 - 19 , 30);
                score0.print_texture();
            }
        if(g_ball_and_raquette.get_score_rite() == 1)
            {
                score1.set_xy(960 - 19 , 30);
                score1.print_texture();
            }
        if(g_ball_and_raquette.get_score_rite() == 2)
            {
                score2.set_xy(960 - 19 , 30);
                score2.print_texture();
            }
        if(g_ball_and_raquette.get_score_rite() == 3)
            {
                score3.set_xy(960 - 19 , 30);
                score3.print_texture();
            }
        if(g_ball_and_raquette.get_score_rite() == 4)
            {
                score4.set_xy(960 - 19 , 30);
                score4.print_texture();
            }
        if(g_ball_and_raquette.get_score_rite() == 5)
            {
                score5.set_xy(960 - 19 , 30);
                score5.print_texture();
            }
        if(g_ball_and_raquette.get_score_rite() == 6)
            {
                score6.set_xy(960 - 19 , 30);
                score6.print_texture();
            }
        if(g_ball_and_raquette.get_score_rite() == 7)
            {
                score7.set_xy(960 - 19 , 30);
                score7.print_texture();
            }
        if(g_ball_and_raquette.get_score_rite() == 8)
            {
                score8.set_xy(960 - 19 , 30);
                score8.print_texture();
            }
        if(g_ball_and_raquette.get_score_rite() == 9)
            {
                score9.set_xy(960 - 19 , 30);
                score9.print_texture();
            }
        if(g_ball_and_raquette.get_score_rite() == 10)
            g_program_is_running = false ;

        SDL_RenderPresent(g_render);
        SDL_SetRenderDrawColor(g_render , 0 , 0 , 0 , 255);
        SDL_RenderClear(g_render);
    }

void update_event()
    {
        if(SDL_PollEvent(&event))
            {
                if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                    g_program_is_running = false ;

                if(g_ball_and_raquette.get_ball_x() > (1280 - 26) / 2)
                    {
                        if(event.key.keysym.sym == SDLK_UP)
                            if(g_ball_and_raquette.get_raquette2_y() > 0)
                                g_ball_and_raquette.set_raquette2_y(g_ball_and_raquette.get_raquette2_y() - 20);
                                else g_ball_and_raquette.set_raquette2_y(0);
                        if(event.key.keysym.sym == SDLK_DOWN)
                            if(g_ball_and_raquette.get_raquette2_y() < 720 - 160)
                                g_ball_and_raquette.set_raquette2_y(g_ball_and_raquette.get_raquette2_y() + 20);
                                else g_ball_and_raquette.set_raquette2_y(720 - 160);
                    }
                    else
                        {
                            if(event.key.keysym.sym == SDLK_w)
                                if(g_ball_and_raquette.get_raquette1_y() > 0)
                                    g_ball_and_raquette.set_raquette1_y(g_ball_and_raquette.get_raquette1_y() - 20);
                                    else g_ball_and_raquette.set_raquette1_y(0);
                            if(event.key.keysym.sym == SDLK_s)
                                if(g_ball_and_raquette.get_raquette1_y() < 720 - 160)
                                    g_ball_and_raquette.set_raquette1_y(g_ball_and_raquette.get_raquette1_y() + 20);
                                    else g_ball_and_raquette.set_raquette1_y(720 - 160);
                        }
            }
    }