
#include "gfx.h"
#include "ui.h"

#include "gdisp.h"
#include "gui.h"
#include "gdriver.h"
#include "ginput_mouse.h"
#include "ginput_driver_mouse.h"
#include <string.h>

#include "stm32f4xx_hal.h"

#include "cmsis_os.h"
#include "rng.h"
#include "myDraw.h"
#include "colors.h"
#include "spi.h"
#include "gpio.h"
#include "LCD.h"
#include "gwin_widget.h"
/*  screeen disp coordinate
         __________
    (0,0)          (320,0)
    |                   |
    |                   |
    (0,240)________(320,240)
*/


void UserInterface()
{

  gfxInit();
//ginputCalibrateMouse(0);


  gdispSetBacklight(100);
  gdispSetContrast(100);

  geventListenerInit(&glistener);
  gwinAttachListener(&glistener);

  guiCreate();
  //displayADC();



  while (1) 
  {
    
    guiEventLoop();
  }
}

