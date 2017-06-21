/*********************************************************************************************************
*
* File                : LCD.h
* Hardware Environment:
* Build Environment   : RealView MDK-ARM  Version: 4.20
* Version             : V1.0
* By                  :
*
*                                  (c) Copyright 2005-2011, WaveShare
*                                       http://www.waveshare.net
*                                          All Rights Reserved
*
*********************************************************************************************************/

#ifndef __GLCD_H
#define __GLCD_H


#define max(a,b) a>b?a:b;
#define min(a,b) a<b?a:b;
#define int_swap(a, b) \
    { \
        (a) ^= (b); \
        (b) ^= (a); \
        (a) ^= (b); \
    }
typedef enum  bool
{
   false = 0,
   true = 1
}bool;

/* Includes ------------------------------------------------------------------*/
#include <math.h>
#include "AsciiLib.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

//#include "stm32f10x.h"

/* Private define ------------------------------------------------------------*/
#define USE_16BIT_PMP

/*********************************************************************
* Overview: Horizontal and vertical display resolution
*                  (from the glass datasheet).
*********************************************************************/
//#define DISP_HOR_RESOLUTION				320
//#define DISP_VER_RESOLUTION				240


#define DISP_ORIENTATION				 90  // 0 90 180 270


/* Private define ------------------------------------------------------------*/

#if  ( DISP_ORIENTATION == 90 ) || ( DISP_ORIENTATION == 270 )

#define  MAX_X  320
#define  MAX_Y  240

#elif  ( DISP_ORIENTATION == 0 ) || ( DISP_ORIENTATION == 180 )

#define  MAX_X  240
#define  MAX_Y  320

#endif

/*********************************************************************
* Overview: Horizontal synchronization timing in pixels
*                  (from the glass datasheet).
*********************************************************************/
//#define DISP_HOR_PULSE_WIDTH		20    /* 20 */
//#define DISP_HOR_BACK_PORCH			51	  /* 48	*/
//#define DISP_HOR_FRONT_PORCH		20	  /* 20 */

/*********************************************************************
* Overview: Vertical synchronization timing in lines
*                  (from the glass datasheet).
*********************************************************************/
//#define DISP_VER_PULSE_WIDTH		2	  /* 2 */
//#define DISP_VER_BACK_PORCH			12	  /* 16 */
//#define DISP_VER_FRONT_PORCH		4	  /* 4 */

	/*  PC0.8(RST) PC.1(WR), PC.2(RD) , PC.6(CS), PC.7(RS)*/
		/* PA.3(BL_PWM),*/
typedef enum line_type{Horiz =1,Verti,Slash}line_type;


#define ILI9325_CTRL_PORT			GPIOD
#define ILI9325_DATA_PORT			GPIOE
#define ILI9325_BACKLIGHT_PORT		GPIOA

#define ILI9325_CS_PIN				GPIO_PIN_14
#define ILI9325_RS_PIN				GPIO_PIN_15
#define ILI9325_nWR_PIN				GPIO_PIN_12
#define ILI9325_nRD_PIN				GPIO_PIN_13
#define ILI9325_RESET_PIN			GPIO_PIN_11
#define ILI9325_BACKLIGHT_PIN		GPIO_PIN_0



#define Set_Cs        			HAL_GPIO_WritePin(ILI9325_CTRL_PORT, ILI9325_CS_PIN,GPIO_PIN_SET)
#define Clr_Cs        			HAL_GPIO_WritePin(ILI9325_CTRL_PORT, ILI9325_CS_PIN,GPIO_PIN_RESET)

#define Set_Rs        			HAL_GPIO_WritePin(ILI9325_CTRL_PORT, ILI9325_RS_PIN,GPIO_PIN_SET)
#define Clr_Rs        			HAL_GPIO_WritePin(ILI9325_CTRL_PORT, ILI9325_RS_PIN,GPIO_PIN_RESET)

#define Set_nWr       			HAL_GPIO_WritePin(ILI9325_CTRL_PORT, ILI9325_nWR_PIN,GPIO_PIN_SET)
#define Clr_nWr       			HAL_GPIO_WritePin(ILI9325_CTRL_PORT, ILI9325_nWR_PIN,GPIO_PIN_RESET)

#define Set_nRd       			HAL_GPIO_WritePin(ILI9325_CTRL_PORT, ILI9325_nRD_PIN,GPIO_PIN_SET)
#define Clr_nRd       			HAL_GPIO_WritePin(ILI9325_CTRL_PORT, ILI9325_nRD_PIN,GPIO_PIN_RESET)

#define Set_Reset       		HAL_GPIO_WritePin(ILI9325_CTRL_PORT, ILI9325_RESET_PIN,GPIO_PIN_SET)
#define Clr_Reset       		HAL_GPIO_WritePin(ILI9325_CTRL_PORT, ILI9325_RESET_PIN,GPIO_PIN_RESET)

#define Set_Backlight       	HAL_GPIO_WritePin(ILI9325_BACKLIGHT_PORT, ILI9325_BACKLIGHT_PIN,GPIO_PIN_SET)
#define Clr_Backlight       	HAL_GPIO_WritePin(ILI9325_BACKLIGHT_PORT, ILI9325_BACKLIGHT_PIN,GPIO_PIN_RESET)



/* LCD color */
#define Default_Color  Green
#define Default_Font  MS_GOTHIC_8x16

#define White          0xFFFF
#define Black          0x0000
#define Grey           0xF7DE
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

#define RGB565CONVERT(red, green, blue) (int) (((red >> 3) << 11) | ((green >> 2) << 5) | (blue >> 3))

/* Private function prototypes -----------------------------------------------*/
void LCD_Initializtion(void);
void LCD_Clear(uint16_t Color);
//void LCD_SetBacklight(uint8_t intensity);
uint16_t LCD_GetPoint(uint16_t Xpos,uint16_t Ypos);
void LCD_SetPoint(uint16_t Xpos,uint16_t Ypos,uint16_t point);
void LCD_DrawLine( uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1 ,uint16_t color);

void LCD_DrawCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color);
	// draws a filled circle with center x0,y0 radius r and selected color
void LCD_FillCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color);
	// draws a rectangle starting at x,y with width w and height h with selected color
void LCD_DrawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
	// draws a filled rectangle starting at x,y with width w and height h with selected color
void LCD_FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
	// draws a triangle with coordinates x0,y0 x1,y1 x2,y2 with selected color
void LCD_DrawTriangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void LCD_DrawCross(uint16_t Xpos, uint16_t Ypos, uint16_t in_color, uint16_t out_color);

void PutChinese(uint16_t Xpos,uint16_t Ypos,uint8_t *str,uint16_t Color,uint16_t bkColor);

void cleanPutChar( uint16_t Xpos, uint16_t Ypos, uint8_t ASCII, uint16_t charColor);
void cleanPutCharFont( uint16_t Xpos, uint16_t Ypos, uint8_t ASCII, uint16_t charColor, uint16_t FONTx);

void putChar(uint16_t Xpos, uint16_t Ypos, uint8_t ASCII, uint16_t charColor, uint16_t bkColor);
void putCharFont( uint16_t Xpos, uint16_t Ypos, uint8_t ASCII, uint16_t charColor, uint16_t bkColor, uint16_t FONTx);


void LCD_print(uint16_t Xpos, uint16_t Ypos, char *str);
//print float
void 	float2str( float f,char *str,int digit);
void int2str( int val,char *str);
void LCD_printColor(uint16_t Xpos, uint16_t Ypos, char *str, uint16_t Color);
void LCD_printColorFont(uint16_t Xpos, uint16_t Ypos, char *str, uint16_t Color, uint16_t FONTx);

void LCD_Chinese(uint16_t Xpos, uint16_t Ypos, uint8_t *str,uint16_t Color, uint16_t bkColor);
void LCD_DrawPicture(uint16_t StartX,uint16_t StartY,uint16_t EndX,uint16_t EndY,uint16_t *pic);


__inline void LCD_WriteIndex(uint16_t index);
__inline void LCD_WriteData(uint16_t data);
__inline uint16_t LCD_ReadData(void);
__inline uint16_t LCD_ReadReg(uint16_t LCD_Reg);
__inline void LCD_WriteReg(uint16_t LCD_Reg,uint16_t LCD_RegValue);
static void LCD_SetCursor( uint16_t Xpos, uint16_t Ypos );
void delay_ms(uint16_t ms);

#endif

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/

