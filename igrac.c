#include "igrac.h"


void draw_player(){
    x_player = 0;
    y_player = 0.8;
    z_player = 40;
    player_moves[0] = 0;
    player_moves[1] = 0;
    
    
    GLfloat material_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    /*Pozicija svetla-infinite*/
    GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
    
    GLfloat light_diffuse[] = {0.0, 1.0, 1.0, 1.0}; 
    
    /*Postavljamo svetlo */
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
   
    /*head*/
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
    glPushMatrix();
    glTranslatef(x_player, y_player + 1.5, z_player);
    glutSolidSphere(1, 20, 20);
    glPopMatrix();
    

}

void go_player(){

    if( player_moves[0] && x_player < 4.5 )
        x_player += 0.2;
    
    if( player_moves[1] && x_player > -4.5 )
        x_player -= 0.2;
}
