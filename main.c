#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h> 
#include "callback_fje.h"
#include "texture.h"




int main(int argc, char **argv){

    /* Inicijalizuje se GLUT.*/
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    
   
    /*Inicijalizacija prozora*/
    glutInitWindowPosition(0,0);
    glutCreateWindow("GeoRabbit");
  //  glutFullScreen();
    
    
    /*Registruju se callback funkcije.*/
    glutDisplayFunc(on_display);
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    
    /* Obavlja se OpenGL inicijalizacija. */
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    
    /*Inicijalizacija tekstura*/
    initialize_t();
    
    glutMainLoop();
    
    return 0;
    
}



