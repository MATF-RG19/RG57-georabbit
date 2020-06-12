#ifndef _STONE_H
#define _STONE_H

#include "texture.h"
#include <stdio.h>
#include "callback_fje.h"



#define NUMBER_OF_STONES 10
#define y_const 2



typedef struct stone_struct{
    int x;
    float z; 
    
    //y koordinata je konstanta i iznosi 4
    //x moze biti npr. 5 ili -5(random postavlja)
    //z se uvecava za speed_parametar
}stone;

extern stone stones[NUMBER_OF_STONES];
extern float speed_parametar;
//poluprecnik lopte
extern float r;

//unutrasnji poluprecnik sedmougla
extern float r7;
//spoljasnji poluprecnik sedmougla
extern float R7;

//pozicija od 0 do 9 koja ce da bude sigurica da ne moze //u beskonacno da igra
//na toj poziciji nece biti probuseni sedmougao
//pa samim tim igrac ne moze da prodje kroz prepreku
extern int poz1;
//isto kao poz1
extern int poz2;


void make_stone(int i); /* stvaranje jednog kamena na poziji i u nizu stones*/
void stone_initialize(); 
/*inicijalizuje pocetne koordinate*/
void draw_stones(); /* iscrtava kamenje po vrstama */

void generisi_prepreke();
/*kretanje prepreka*/



//rastojanje od igraca(udario ili nije)
int rastojanje(stone s);

#endif
