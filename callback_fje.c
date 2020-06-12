#include "callback_fje.h"

int game_ongoing;
int animation_ind = 0;
int d;
int score = 0;

void on_display(void){

    /* Brise se prethodni sadrzaj prozora. */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
     /* Podesava se tacka pogleda. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            0, 10, 70,
            0, 0, 0,
            0, 1, 0
        );
    
    //prikaz skora trenutnog
    
    //podesavanje boje
    GLfloat light_diffuse2[] = {0.0, 0.0, 0.0, 1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse2);
    //podesavanje pozicije
    glRasterPos3f(-2, 13, 5);
    
    char score_string[40] = "SCORE: ";
    char score_int[40];
    
    sprintf(score_int, " %d ", score);
    strcat(score_string, score_int);
    
    int len = (int)strlen(score_string);
    
    for(int i = 0; i < len; i++){
        
    
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,score_string[i]);
        
    }   
    
     /*Odredjuje se pozicija svetla*/
    GLfloat light_position[] = {0,0,0,1};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);

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
    draw_player();
    
    if(animation_ind){
    
        //game over prikaz
            /**************************************/
            GLfloat light_diffuse3[] = {0.0, 0.0, 0.0, 1.0};
            glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse3);
            //podesavanje pozicije
            glRasterPos3f(-2, 10, 5);
            
            char game_over_string[40];
            sprintf(game_over_string, "GAME OVER!");
            
            
            int l = (int)strlen(game_over_string);
            
            for(int i = 0; i < l; i++){
                
            
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,game_over_string[i]);
                
            }
            glRasterPos3f(-3, 9, 5);
            char press_string[40];
            sprintf(press_string, "Press r/R to restart!");
            l = (int)strlen(press_string);
            
            for(int i = 0; i < l; i++){
                
            
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,press_string[i]);
                
            }
    }
    
    
  
    glutSwapBuffers();
}



void on_keyboard(unsigned char key, int x, int y){

    switch(key){
        case 'r':
        case 'R':
            game_ongoing = 0;
            animation_ind = 0;
            speed_parametar = 0;
            stone_initialize();
            speed_player = 0;
            x_player = 0;
            y_player = 0.8;
            z_player = 40;
            draw_player();
            score = 0;
            glutPostRedisplay();
            break;
    
        case 27:
            /* Zavrsava se program. */
            exit(0);
        
            break;
        case 'S':
        case 's':
            /*Start-pokrecemo animaciju*/
            //Naravno, ako nije vec pokrenuta
            //ili ako smo izgubili pa da ne bi samo nastavio
            //da igra
            if(!game_ongoing && animation_ind == 0){

                          
                glClearColor(0,0,0,0);
                glutDisplayFunc(on_display);
                animation_ind = 0;
                game_ongoing = 1;
                
                glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
                
                glutPostRedisplay();
            }
            break;
        case 'p':
        case 'P':
            if(game_ongoing){
                game_ongoing = 0;
            }else{
            
                game_ongoing = 1;
                glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
                
            }
            break;
        case 'a':
        case 'A':
            /*Igrac se pomera u levo.Postavlja se indikator
             za on_release funkciju*/
            player_moves[0] = 1;
            glutPostRedisplay();
            break;
        case 'D':
        case 'd':
            /*Pomeranje u desno,analogno kao i za levo*/
            player_moves[1] = 1;
            glutPostRedisplay();
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

void on_release(unsigned char key, int x, int y){

    switch(key){
    
        case 'a':
        case 'A':
            player_moves[0] -= 1;
            break;
        case 'd':
        case 'D':
            player_moves[1] -=1;
            break;
    }
}

void on_timer(int value){

    if(!game_ongoing)
        return;
    
    if(value != TIMER_ID)
        return;
    
    //stone.h
    generisi_prepreke();
    
    //igrac.h
    go_player();
    
    //callback_fje.h
    check_collision();
    
    glutPostRedisplay();
    if(game_ongoing){
            glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
        }
}



void check_collision(){

    
    //proverava razdaljinu sa svakom preprekom
    
    for(int i=0;i<NUMBER_OF_STONES;i++){
   
        d= rastojanje(stones[i]);
        //printf("kamen : %d    d : %d\n",i,d);

        if(d){
            printf("GAME OVER!\n");
            //postavlja se indikator da je izgubio 
            //zbog prikaza "GAME OVER!" poruke
            animation_ind = 1;
            
            /***************************************/
            game_ongoing = 0;
            glutPostRedisplay();
        }
        
        /*ako je igrac nije udario u prepreku i zaobisao je onda povecavamo score*/
        
        if((stones[i].z >=38 && stones[i].z <= 42) && 
            (x_player + 1.7 < stones[i].x + 3) &&
            (x_player - 1.7 > stones[i].x - 3)
        ){
            score += 1;
            if(score % 10 == 0)
                speed_parametar += 0.02;
        }
    }

}
