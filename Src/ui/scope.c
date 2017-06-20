#include "scope.h"
scope_t scope;
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
float getMax(){return scope.max;}
float getMin(){return scope.min;}
float getP2P(){return scope.p2p;}
float getPK(){return scope.pk;}
float getRMS(){return scope.rms;}