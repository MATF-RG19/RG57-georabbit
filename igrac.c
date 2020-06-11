#include "igrac.h"

float x_player = 0;
float y_player = 0.8;
float z_player = 40;
int player_moves[] = {0, 0};
    

void draw_player(){
    
    
    
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
    glutSolidSphere(2, 20, 20);
    glPopMatrix();
    

}

void go_player(){

    //18 - da bi mogao i sa strane da pobegne ako ne moze izmedju prepreka da prodje
    if( player_moves[0] && x_player > -18 )
        x_player -= 0.4;
    
    if( player_moves[1] && x_player < 18 )
        x_player += 0.4;
}
