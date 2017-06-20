#ifndef __SCOPE_H
#define __SCOPE_H

#include "stm32f4xx_hal.h"
#define ADC_bufsize 320
typedef struct
{
	int buf[2][ADC_bufsize];
	float max;
	float min;
	float p2p;
	float pk;
	float rms;
	float avg;
	
}scope_t;

void updateMax();
void updateMin();
void updateP2P();
void updatePK();
void updateRMS();
void updateAVG();

float getMax();
float getMin();
float getP2P();
float getPK();
float getRMS();
float getAVG();

#endif
