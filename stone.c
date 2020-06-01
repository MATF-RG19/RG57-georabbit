#include "stone.h"

float speed_parametar = 0.01;



typedef struct stone_struct{
    int x;
    float z; 
    //y koordinata je konstanta
    //x moze biti npr. 10 ili -10(random postavlja)
    //z se uvecava za speed_parametar
} stone;


/*
 * -niz koji sadrzi elemente strukture stone
 * -u jednom trenutku NUMBER_OF_STONES treba da 
 *  bude prikazano na ekranu
 * */
stone stones[NUMBER_OF_STONES];

/*prvih 10 inicijalizuje kada se pokrene animacija*/
void stone_initialize(){
   for(int i=0;i<NUMBER_OF_STONES;i++){
        stones[i].z = -50 - 15*i;
        make_stone(i);
        
   }
}


void generisi_prepreke(int value){

    if(!game_ongoing)
        return;
    
    if(value != TIMER_ID)
        return;
    else
        animation_parameter++;
    
    int k;
    int i = -1;
    for(k=0; k< NUMBER_OF_STONES;k++){
    
        /*pomeramo prepreke sve ka igracu*/
        stones[k].z +=0.1;
        
 
        if(stones[k].z >= 60){
        
            //pamtimo poziciju igraca 
            i = k;
            stones[i].z = -100;
            
        }
        
        
        if(stones[k].z >= 45 &&  stones[k].z <= 55){
                 game_ongoing = 0;
                 
                 glutPostRedisplay();
         }
         
        //POPRAVI
        /*Kada prepreka prodje igraca, pravimo novu prepreku.
         Mora da ih ima 10 u jednom trenutku.*/
        
//         if(i!=-1){
//         
//             stones[i].z = -100;
//         }
//         
        glutPostRedisplay();
        if(game_ongoing){
            glutTimerFunc(TIMER_INTERVAL, generisi_prepreke, TIMER_ID);
        }
        
    }
    
}


void draw_stones(){
    /* Iscrtava komete na pozicijama na kojima se trenutno nalaze u commet_array */
    stone c;
    int j;

    GLUquadricObj *quadric_object = gluNewQuadric();
    gluQuadricDrawStyle(quadric_object, GLU_FILL);
    gluQuadricTexture(quadric_object, GL_TRUE);
    
    
    glEnable(GL_TEXTURE_2D);


    for(j=0;j<NUMBER_OF_STONES;j++){
        c = stones[j];

        /* crta dve komete u jednoj liniji */
        glBindTexture(GL_TEXTURE_2D, id_tex[2]);
        glPushMatrix();
            glTranslatef(c.x,4,c.z);  
            gluDisk(quadric_object, 3, 7, 7,7);
        glPopMatrix();

    }
    
    glDisable(GL_TEXTURE_2D);
}

void make_stone(int i){
    int prazna_poz,x;
    
    //prazna_poz je 0 ili 1
    prazna_poz= rand() % 2;
    
    // printf("I: %d\tBR:%d\n\n",i,prazna_poz);

    //Promeni x ako nije ok 10
    switch(prazna_poz){
        case 0:
            x = 10;
            break;
        case 1:
            x = -10;
    }
    
    /*Pozicija kamena*/
    stones[i].x = x;

}

