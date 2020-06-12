#include "igrac.h"

float x_player = 0;
float y_player = 0.8;
float z_player = 40;
int player_moves[] = {0, 0};
float speed_player = 0;
    

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
    glutSolidSphere(1.7, 20, 20);
    
    glPushMatrix();
    glTranslatef(0,1.7,0);
    glutSolidSphere(1,10,20);
    glPopMatrix();
    
    GLfloat light_diffuse1[] = {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE,light_diffuse1 );
    
    glPushMatrix();
    glTranslatef(0,-0.5,2);
    glutSolidSphere(0.5,20,20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.5,2.9,0);
    glRotatef(90,1,0,0);
    glutSolidCone(0.4,1,10,20);
    
    glRotatef(180,1,0,0);
    glutSolidCone(0.4,0.6,10,20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5,2.9,0);
    glRotatef(90,1,0,0);
    glutSolidCone(0.4,1,10,20);
    
    glRotatef(180,1,0,0);
    glutSolidCone(0.4,0.6,10,20);
    glPopMatrix();
    
    
    glPopMatrix();
    

}

void go_player(){

    //11 - da bi mogao i sa strane da pobegne ako ne moze izmedju prepreka da prodje
    if( player_moves[0] && x_player > -11 ){
        x_player -= (0.4+speed_player);
            
    }
    
    if( player_moves[1] && x_player < 11 ){
        x_player += (0.4+speed_player);
    
    }
    
     //igrac se ubrzava u zavisnosti od scora
        if(score < 50)
            speed_player += 0.001;
        if(score > 50 && score < 100)
            speed_player += 0.002;
}
