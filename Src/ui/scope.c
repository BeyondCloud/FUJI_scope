#include "scope.h"
#include <math.h>

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

scope_t scope;
float ADC_to_V(int adc)
{
    return ((float)adc)*3.3/4096.0;
}
int clamp(int x, int lower, int upper)
{
    return min(upper, max(x, lower));
}
void updateMax()
{
	int i;
	int max=0;
	for(i=0;i<ADC_bufsize;i++)
		max = ((max>scope.adc_buf[0][i])?max:scope.adc_buf[0][i]);
	scope.max = ADC_to_V(max);
}

void updateMin()
{
	int i;
	int min=4096;
	for(i=0;i<ADC_bufsize;i++)
		min = ((min<scope.adc_buf[0][i])?min:scope.adc_buf[0][i]);
	scope.min = ADC_to_V(min);
}
void updateP2P()
{
	scope.p2p =  scope.max-scope.min;
}
void updatePK()
{
	scope.pk = scope.p2p/2.0;
}
void updateAVG()
{

	int i;
	int avg=0;
	for(i=0;i<ADC_bufsize;i++)
		avg += scope.adc_buf[0][i];
	scope.avg = ADC_to_V(avg/ADC_bufsize);
}
void updateRMS()
{
	int i;
	uint64_t rms=0;
	for(i=0;i<ADC_bufsize;i++)
		rms += (scope.adc_buf[0][i]*scope.adc_buf[0][i]);
	scope.rms = ADC_to_V(sqrt(rms/ADC_bufsize));
}
float getMax(){return scope.max;}
float getMin(){return scope.min;}
float getP2P(){return scope.p2p;}
float getPK(){return scope.pk;}
float getRMS(){return scope.rms;}
float getAVG(){return scope.avg;}
