#include "stone.h"

//ubrzanje prepreka
float speed_parametar = 0;

/*
 * -niz koji sadrzi elemente strukture stone
 * -u jednom trenutku NUMBER_OF_STONES treba da 
 *  bude prikazano na ekranu
 * */
stone stones[NUMBER_OF_STONES];

/*prvih 10 inicijalizuje kada se pokrene animacija*/
void stone_initialize(){
   for(int i=0;i<NUMBER_OF_STONES;i++){
        stones[i].z = 25 - 23*i;
        make_stone(i);
        
   }
}

void generisi_prepreke(){

    int k;
    int i = -1;
    for(k=0; k< NUMBER_OF_STONES;k++){
    
        /*pomeramo prepreke sve ka igracu*/
        stones[k].z=stones[k].z+0.4+speed_parametar;
        
        
        if(stones[k].z >= 60){
        
             //pamtimo poziciju igraca 
             i = k;
            //saljemo stone na kraj staze
            stones[i].z = -100;
            /*opet random da izabere x koordinatu da ne bi stalno vrteo jedan te isti niz
             */
            make_stone(i);
            
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

        glBindTexture(GL_TEXTURE_2D, id_tex[2]);
        glPushMatrix();
            /*pozicija prepreke
             */
            glTranslatef(c.x,y_const,c.z);  
            /*unitrasnji poluprecnik 3
             * spoljasnji poluprecnik 6
             * vrsta mnogougla sedmougao
            */
            gluDisk(quadric_object, 3, 6, 7,7);
        glPopMatrix();

    }
    
    glDisable(GL_TEXTURE_2D);
}

void make_stone(int i){
    int prazna_poz,x;
    
    //prazna_poz je 0 ili 1
    prazna_poz= rand() % 2;
    
    switch(prazna_poz){
        case 0:
            x = 5;
            break;
        case 1:
            x = -5;
    }
    
    /*Pozicija kamena*/
    stones[i].x = x;

}

int rastojanje(stone s){
        
    if(s.x + 6 >= x_player && s.x -6 <= x_player && s.z >=38 && s.z <= 42)
        return 1;
    
    return 0;
    
}

