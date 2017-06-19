#ifndef _SCOPE_H_
#define _SCOPE_H_
#include "stm32f4xx_hal.h"
uint16_t ADC_buffer[2][320]={};
float getMax(void);
float getMin(void);
float getP2P(void);
float getPk(void);
float getRMS(void);


#endif