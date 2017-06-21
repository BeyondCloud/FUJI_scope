#ifndef __SCOPE_H
#define __SCOPE_H

#include "stm32f4xx_hal.h"
#define ADC_bufsize 320

typedef struct
{
	int adc_buf[2][ADC_bufsize];
	float max;
	float min;
	float p2p;
	float pk;
	float rms;
	float avg;
	
}scope_t;
extern float screen_Vscale;
extern scope_t scope;
extern float ADC_Vmax;
static inline float ADC_to_V(int adc)
{
    return ((float)adc)*ADC_Vmax/4096.0;
}
static inline void updateMax()
{
	int i;
	int max=0;
	for(i=0;i<ADC_bufsize;i++)
		max = ((max>scope.adc_buf[0][i])?max:scope.adc_buf[0][i]);
	scope.max = ADC_to_V(max);
}

 static inline void updateMin()
{
	int i;
	int min=4096;
	for(i=0;i<ADC_bufsize;i++)
		min = ((min<scope.adc_buf[0][i])?min:scope.adc_buf[0][i]);
	scope.min = ADC_to_V(min);
}
 static inline void updateP2P()
{
	scope.p2p =  scope.max-scope.min;
}
 static inline void updatePK()
{
	scope.pk = scope.p2p/2.0;
}
 static inline void updateAVG()
{

	int i;
	int avg=0;
	for(i=0;i<ADC_bufsize;i++)
		avg += scope.adc_buf[0][i];
	scope.avg = ADC_to_V(avg/ADC_bufsize);
}
 static inline void updateRMS()
{
	int i;
	uint64_t rms=0;
	for(i=0;i<ADC_bufsize;i++)
		rms += (scope.adc_buf[0][i]*scope.adc_buf[0][i]);
	scope.rms = ADC_to_V(sqrt(rms/ADC_bufsize));
}


 static inline float getMax(){return scope.max;}
 static inline float getMin(){return scope.min;}
 static inline float getP2P(){return scope.p2p;}
 static inline float getPK(){return scope.pk;}
 static inline float getRMS(){return scope.rms;}
 static inline float getAVG(){return scope.avg;}

#endif
