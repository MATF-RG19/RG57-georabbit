#ifndef __IGRAC_H_
#define __IGRAC_H_

#include <GL/glut.h>
#include "callback_fje.h"

/*koordinate igraca*/
extern float x_player ;
extern float y_player ;
extern float z_player ;
/*moguci potezi igraca*/
extern int player_moves[2]; 
/*ubrzanje*/
extern float speed_player;

/*iscrtavanje*/
void draw_player();
/*kretanje*/
void go_player();


#endif
