#ifndef _STONE_H
#define _STONE_H

#include "texture.h"
#include <stdio.h>
#include "callback_fje.h"



#define NUMBER_OF_STONES 10
#define y_const 4


typedef struct stone_struct{
    int x;
    float z; 
    
    //y koordinata je konstanta i iznosi 4
    //x moze biti npr. 5 ili -5(random postavlja)
    //z se uvecava za speed_parametar
}stone;

extern stone stones[NUMBER_OF_STONES];
extern float speed_parametar;


void make_stone(int i); /* stvaranje jednog kamena na poziji i u nizu stones*/
void stone_initialize(); 
/*inicijalizuje pocetne koordinate*/
void draw_stones(); /* iscrtava kamenje po vrstama */

void generisi_prepreke();
/*kretanje prepreka*/

//rastojanje od igraca(udario ili nije)
int rastojanje(stone s);

#endif
