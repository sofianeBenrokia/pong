#include "entyti.hpp"
#include <random>

void Texture::new_texture(const char *path , int x , int y)
    {
        set_xy( x , y );
        
        SDL_Surface *surface = NULL ;

        surface = SDL_LoadBMP( path );
        
        if(surface == NULL)
            g_program_is_running = false ;

        m_texture = SDL_CreateTextureFromSurface(g_render , surface);

        SDL_FreeSurface(surface);

        if(m_texture == NULL)
            g_program_is_running = false ;

        if(SDL_QueryTexture(m_texture , NULL , NULL , &m_rect.w , &m_rect.h) != 0)
            {
                clear();
                g_program_is_running = false ;
            }
        
    }

void Texture::print_texture()
    {
        if(SDL_RenderCopy(g_render , m_texture , NULL , &m_rect) != 0)
            {
                clear();
                g_program_is_running = false ;
            }
    }

//ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ

void Ball_and_raquette::update_ball_and_raquette()
    {
        
        // raquette hitboxe
        if(m_ball.get_x() + m_direction_x < 41 && m_ball.get_y() + m_direction_y + 52 > m_raquette1.get_y() && m_ball.get_y() + m_direction_y < m_raquette1.get_y() + 160)
            {
                m_ball.set_x(41);
                if(m_ball.get_y() - m_raquette1.get_y() < 55)
                    {
                        m_direction_x = m_ball.get_y() - m_raquette1.get_y() ;
                        m_direction_x += 52 + 53 ;
                        m_direction_x = SPEED * m_direction_x / 159 ;
                        m_direction_y = 0 ;
                        m_direction_y -= SPEED - m_direction_x ;
                    }
                    else
                        {
                            m_direction_y = m_ball.get_y() - m_raquette1.get_y() ;
                            m_direction_y += 52 + 53 - 159 ;
                            m_direction_y = SPEED * m_direction_y / 159 ;
                            m_direction_x = 0 ;
                            m_direction_x += SPEED - m_direction_y ;
                        }
            }
        
        if(m_ball.get_x() + m_direction_x > 1280 - 41 - 52 && m_ball.get_y() + m_direction_y + 52 > m_raquette2.get_y() && m_ball.get_y() + m_direction_y < m_raquette2.get_y() + 160)
            {
                m_ball.set_x(1280 - 52 - 41);
                if(m_ball.get_y() - m_raquette2.get_y() < 55)
                    {
                        m_direction_x = m_ball.get_y() - m_raquette2.get_y() ;
                        m_direction_x += 52 + 53 ;
                        m_direction_x = SPEED * m_direction_x / 159 ;
                        m_direction_y = 0 ;
                        m_direction_y -= SPEED - m_direction_x ;
                        m_direction_x *= -1 ;
                    }
                    else
                        {
                            m_direction_y = m_ball.get_y() - m_raquette2.get_y() ;
                            m_direction_y += 52 + 53 - 159 ;
                            m_direction_y = SPEED * m_direction_y / 159 ;
                            m_direction_x = 0 ;
                            m_direction_x += SPEED - m_direction_y ;
                            m_direction_x *= -1 ;
                        }
            }
        
        // right and left side hitboxe
        if(m_ball.get_x() + m_direction_x < 0)
            {
                m_ball.set_x( (1280 - 52) / 2);
                m_ball.set_y( (720 - 52) / 2);
                m_direction_x = -15 ;
                m_direction_y = 0 ;
                m_score_rite ++ ;
            }
            else if(m_ball.get_x() + m_direction_x > 1280 - 52)
                    {
                        m_ball.set_x( (1280 - 52) / 2);
                        m_ball.set_y( (720 - 52) / 2);
                        m_direction_x = 15 ;
                        m_direction_y = 0 ;
                        m_score_left ++ ;
                    }
                    else m_ball.set_x(m_ball.get_x() + m_direction_x);
        
        // bot and up side hitboxe
        if(m_ball.get_y() + m_direction_y < 0)
            {
                m_ball.set_y(0);
                m_direction_y *= -1 ;
            }
            else if(m_ball.get_y() + m_direction_y > 720 - 52)
                    {
                        m_ball.set_y(720 - 52);
                        m_direction_y *= -1 ;
                    }
                    else m_ball.set_y(m_ball.get_y() + m_direction_y);
        
        m_ball.print_ball();
        m_raquette1.print_raquette();
        m_raquette2.print_raquette();
    }

//ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ

void draw_rect(int red , int green , int blue , int opaciter , int x , int y , int w , int h)
    {
        SDL_Rect rect ;
        SDL_SetRenderDrawColor(g_render , red , green , blue , opaciter);
        rect.x = x ;
        rect.y = y ;
        rect.w = w ;
        rect.h = h ;
        SDL_RenderFillRect(g_render , &rect);
    }