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
}scope_t;

void updateMax();
void updateMin();
void updateP2P();
void updatePK();
void updateRMS();
float getMax();
float getMin();
float getP2P();
float getPK();
float getRMS();

/*
void updateMax()
{
	int i;
	scope.max=0;
	for(i=0;i<ADC_bufsize;i++)
		scope.max = ((scope.max>scope.buf[0][i])?scope.max:scope.buf[0][i]);
}

void updateMin()
{
	int i;
	scope.min=4096;
	for(i=0;i<ADC_bufsize;i++)
		scope.min = ((scope.min<scope.buf[0][i])?scope.min:scope.buf[0][i]);
}
void updateP2P()
{
	scope.p2p =  scope.max-scope.min;
}
void updatePK()
{
	scope.pk = scope.p2p/2;
}

void updateRMS()
{
	int i;
	scope.rms=0;
	for(i=0;i<ADC_bufsize;i++)
		scope.rms += (scope.buf[0][i]*scope.buf[0][i]);
	scope.rms = sqrt(scope.rms/ADC_bufsize);
}


*/
#endif
