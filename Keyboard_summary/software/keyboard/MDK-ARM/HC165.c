#include "HC165.h"

void delay(uint8_t i)
{
	while(i--);
}
extern uint8_t value[13];
#define num 2
void read_couple(void)
{
	int  i=0;
	uint8_t  temp = 0;
	CLK_EN;
	CLK_L;
	SL_L;
	delay(10);
	SL_H;  
	for(i = 0; i <num; i ++) 
	{
		temp=0;
		for(int j=0;j<8;j++)
		{

			temp = temp << 1;
			if(DAT == 1)
				temp|=0x01;
			else 
				temp&=~0x01;
 
			
			CLK_L;
			delay(10);
			CLK_H;
		}

		value[i] = temp;
		
	}
	CLK_UEN;
	SL_L;
	CLK_L;
}
