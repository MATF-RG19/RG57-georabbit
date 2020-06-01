#ifndef _STONE_H
#define _STONE_H

#include "texture.h"
#include <stdio.h>



#define NUMBER_OF_STONES 10
#define TIMER_ID 1
#define TIMER_INTERVAL 20

int game_ongoing;
float animation_parameter;


void make_stone(int i); /* stvaranje jednog kamena na poziji i u nizu stones*/
void stone_initialize(); 
/*inicijalizuje pocetne koordinate*/
void draw_stones(); /* iscrtava kamenje po vrstama */

void generisi_prepreke(int);
/*generise i pokrece prepreke*/

#endif
