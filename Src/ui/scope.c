#include "scope.h"
float getMax()
{
	int i;
	float max=0;
	for(i=0;i<319;i++)
		max = ((max<ADC_buffer[0][i])?ADC_buffer[0][i]:max);
	return max;
}

float getMin()
{
	int i;
	float min=4096;
	for(i=0;i<319;i++)
		min = ((min>ADC_buffer[0][i])?ADC_buffer[0][i]:min);
	return min;
}

float getP2P()
{
	return getMax()-getMin();
}

float getPk()
{
	return getP2P()/2;
}

float getRMS()
{
	int i;
	float RMS=0;
	for(i=0;i<319;i++)
		RMS += (ADC_buffer[0][i]*ADC_buffer[0][i]);
	RMS = sqrt(RMS/319);
	return RMS;
}

