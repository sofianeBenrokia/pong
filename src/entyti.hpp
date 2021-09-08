#ifndef __ENTYTI_HPP__
#define __ENTYTI_HPP__

#define SPEED 25

#include "declaration.hpp"

void draw_rect(int red , int green , int blue , int opaciter , int x , int y , int w , int h);

class Texture
    {
        public:

            ~Texture() /*metode*/ {clear() ;} ;

            void clear() /*metode*/ {SDL_DestroyTexture(m_texture) ; m_texture = NULL ;} ;
            
            void new_texture(const char *path , int x , int y);

            void set_xy(int x , int y)  /*metode*/ {m_rect.x = x ; m_rect.y = y ;} ;

            int get_x()  /*metode*/ {return m_rect.x ;} ;
            int get_y()  /*metode*/ {return m_rect.y ;} ;

            void set_x(int x)  /*metode*/ {m_rect.x = x ;} ;
            void set_y(int y) /*metode*/ {m_rect.y = y ;} ;

            void print_texture();

        private:
            
            SDL_Texture *m_texture ;
            SDL_Rect m_rect ;
    };

class Ball
    {
        public:
            
            void init_ball() /*metode*/ {m_texture.new_texture("picture/ball.bmp",(1280 - 52) /2 ,(720 - 52) /2) ;} ;

            void print_ball() /*metode*/ {m_texture.print_texture() ;} ;

            void clear() /*metode*/ {m_texture.clear() ;} ;

            int get_x() /*metode*/ {return m_texture.get_x() ;} ;
            int get_y() /*metode*/ {return m_texture.get_y() ;} ;

            void set_x(int x) /*metode*/ {m_texture.set_x(x) ;} ;
            void set_y(int y) /*metode*/ {m_texture.set_y(y) ;} ;
        private:
            
            Texture m_texture ;
    };

class Raquette
    {
        public:
            
            int get_y() /*metode*/ {return m_y ;} ;
            void set_y(int y) /*metode*/ {m_y = y ;} ;

            int get_x() /*metode*/ {return m_x ;} ;
            void set_x(int x) /*metode*/ {m_x = x ;} ;

            void print_raquette() /*metode*/ {draw_rect(255,255,255,255,m_x,m_y,30,160) ;} ;

        private:

            int m_x = 0 ;
            int m_y = (720 -160) /2;

    };

class Ball_and_raquette
    {
        public:

            void clear() /*metode*/ {m_ball.clear() ;} ;
            
            void init_ball_and_raquette() /*metode*/ {m_ball.init_ball() ; m_raquette1.set_x(10) ; m_raquette2.set_x(1240) ;} ;
            void update_ball_and_raquette();

            int get_raquette1_y() /*metode*/ {return m_raquette1.get_y() ;} ;
            void set_raquette1_y(int y) /*metode*/ {m_raquette1.set_y(y) ;} ;

            int get_raquette2_y() /*metode*/ {return m_raquette2.get_y() ;} ;
            void set_raquette2_y(int y) /*metode*/ {m_raquette2.set_y(y) ;} ;

            int get_ball_x() /*metode*/ {return m_ball.get_x() ;} ;

            int get_score_left() /*metode*/ {return m_score_left ;} ;
            int get_score_rite() /*metode*/ {return m_score_rite ;} ;
            
        private:
            Ball m_ball ;
            Raquette m_raquette1 ;
            Raquette m_raquette2 ;
            int m_direction_x = 15 ;
            int m_direction_y = 0 ;
            int m_score_left = 0 ;
            int m_score_rite = 0 ;
    };

#endif