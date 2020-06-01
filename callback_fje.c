#include "callback_fje.h"

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
    

    //pozadina se crta
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, id_tex[0]);
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);

        glTexCoord2f(0,0);
        glVertex3f(-100,0,-200);

        glTexCoord2f(5,0);        
        glVertex3f(100,0,-200);

        glTexCoord2f(5,5);
        glVertex3f(100,0,200);
  
        glTexCoord2f(0,5);
        glVertex3f(-100,0,200);
    glEnd();    
    glDisable(GL_TEXTURE_2D);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,id_tex[1]);
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);

        glTexCoord2f(0,0);
        glVertex3f(-100,-100,-20);

        glTexCoord2f(5,0);        
        glVertex3f(100,-100,20);

        glTexCoord2f(5,5);
        glVertex3f(100,100,-20);

        glTexCoord2f(0,5);
        glVertex3f(-100,100,-20);
    glEnd();    
    glDisable(GL_TEXTURE_2D);
    
    /*Iscrtavamo prepreke*/
    draw_stones();

    glutSwapBuffers();
}



void on_keyboard(unsigned char key, int x, int y){

    switch(key){
        case 'r':
        case 'R':
            animation_parameter = 0;
    
        case 'a':
            //game_ongoing=0;
            /* Zavrsava se program. */
            exit(0);
        
            break;
        case 'S':
        case 's':
            /*Start-pokrecemo animaciju*/
            //Naravno, ako nije vec pokrenuta
            if(!game_ongoing){
                animation_parameter = 0;
                
                
                stone_initialize();
            
                glClearColor(0,0,0,0);
                glutDisplayFunc(on_display);
                
                game_ongoing = 1;
                
                glutTimerFunc(TIMER_INTERVAL, generisi_prepreke, TIMER_ID);
                
                glutPostRedisplay();
            }
            break;
        case 'p':
        case 'P':
            if(game_ongoing){
                game_ongoing = 0;
            }else{
            
                game_ongoing = 1;
                glutTimerFunc(TIMER_INTERVAL, generisi_prepreke, TIMER_ID);
                
            }
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
