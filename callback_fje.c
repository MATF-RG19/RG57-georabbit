#include "callback_fje.h"

float x_plane = 10;
float y_plane = 1;
float z_plane = 50;


float x_plane2 = 10;
float y_plane2 = 1;
float z_plane2 = 150;


float lenght = 100;


void on_display(void){

    /* Brise se prethodni sadrzaj prozora. */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  
     /*Odredjuje se pozicija svetla*/
    GLfloat light_position[] = {0,0,0,1};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);
    
     /* Podesava se tacka pogleda. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            0, 10, 70,
            0, 0, 0,
            0, 1, 0
        );

    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, id_tex[0]);
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);

        glTexCoord2f(0,0);
        glVertex3f(-100,0,-100);

        glTexCoord2f(5,0);        
        glVertex3f(100,0,-100);

        glTexCoord2f(5,5);
        glVertex3f(100,0,100);
  
        glTexCoord2f(0,5);
        glVertex3f(-100,0,100);
    glEnd();    
    glDisable(GL_TEXTURE_2D);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,id_tex[1]);
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);

        glTexCoord2f(0,0);
        glVertex3f(-100,-100,-20);

        glTexCoord2f(5,0);        
        glVertex3f(100,-100,-20);

        glTexCoord2f(5,5);
        glVertex3f(100,100,-20);

        glTexCoord2f(0,5);
        glVertex3f(-100,100,-20);
    glEnd();    
    glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();
}



void on_keyboard(unsigned char key, int x, int y){

    switch(key){
    
        case 27:
            /* Zavrsava se program. */
            exit(0);
            break;
    }
}



void on_reshape(int width, int height)
{
    /* Podesava se viewport. */
    glViewport(0, 0, width, height);

    /* Podesava se projekcija. */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (float) width / height, 0.1, 100);
}
