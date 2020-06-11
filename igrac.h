#ifndef __IGRAC_H_
#define __IGRAC_H_

#include <GL/glut.h>

/*koordinate igraca*/
extern float x_player ;
extern float y_player ;
extern float z_player ;
extern int player_moves[2]; 

void draw_player();

void go_player();


#endif
