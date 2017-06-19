
#include "stm32f4xx_hal.h"

#ifndef _SCOPE_H_
#define _SCOPE_H_

#define ADC_bufsize 320
uint16_t ADC_buffer[2][ADC_bufsize]={};
float adc_max;
float adc_min;
float adc_p2p;
float adc_min;
float adc_pk;
float adc_rms;
void updateMax();
void updateMin();
void updateP2P();
void updatePK();
void updateRMS();
float getMax(){return adc_max;};
float getMin(){return adc_min;};
float getP2P(){return adc_p2p;};
float getPK(){return adc_pk;};
float getRMS(){return adc_rms;};
inline void setADCbuf(int chnl,uint16_t i,uint16_t val){ADC_buffer[chnl][i] = val;};
void updateMax()
{
	int i;
	adc_max=0;
	for(i=0;i<ADC_bufsize;i++)
		adc_max = ((adc_max>ADC_buffer[0][i])?adc_max:ADC_buffer[0][i]);
}

void updateMin()
{
	int i;
	adc_min=4096;
	for(i=0;i<ADC_bufsize;i++)
		adc_min = ((adc_min<ADC_buffer[0][i])?adc_min:ADC_buffer[0][i]);
}
void updateP2P()
{
	adc_p2p =  adc_max-adc_min;
}
void updatePK()
{
	adc_pk = adc_p2p/2;
}

void updateRMS()
{
	int i;
	adc_rms=0;
	for(i=0;i<ADC_bufsize;i++)
		adc_rms += (ADC_buffer[0][i]*ADC_buffer[0][i]);
	adc_rms = sqrt(adc_rms/ADC_bufsize);
}



#endif