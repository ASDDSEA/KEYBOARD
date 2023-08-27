/*** 74hc165.h ***/
#ifndef _74HC165_H
#define _74HC165_H
 
#include "main.h"
 
sbit HC165_PL = P2^5; //PL ????????,?????
sbit HC165_CLK = P2^7;//CP ??,?????
sbit HC165_OUT = P2^4; //Q7 ??????
sbit HC165_CE = P2^6;//CE ????,?????
 
void _74hc165_init(void);
void _74hc165_read_2byte(uchar date[2]);
 
#endif