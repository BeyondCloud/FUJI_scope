/******************************************************************************/
/* This file has been generated by the uGFX-Studio                            */
/*                                                                            */
/* http://ugfx.org                                                            */
/******************************************************************************/
#ifndef _GUI_H_
#define _GUI_H_

#include "gfx.h"
//#include "scope.h"

// Widupdate groups
#define GROUP_DEFAULT 0

#define DOT_ON 2
#define DOT_OFF 3

// GListeners
extern GListener glistener;

// extern GHandles
extern GHandle ghContainerPage0;
extern GHandle Label_CH;

extern GHandle T_Div_Button;
extern GHandle T_Div_Label;
extern GHandle T_Div_List;


extern GHandle V_Div_Button;
extern GHandle V_Div_Label;
extern GHandle V_Div_List;

extern GHandle Label_X;
extern GHandle X_A_Label;
extern GHandle X_A_Label_Txt;
extern GHandle X_B_Label;
extern GHandle X_B_Label_Txt;
extern GHandle X_F_Label;
extern GHandle X_F_Label_Txt;
extern GHandle X_AB_Label;
extern GHandle X_AB_Label_Txt;

extern GHandle Label_Y;
extern GHandle Y_A_Label;
extern GHandle Y_A_Label_Txt;
extern GHandle Y_B_Label;
extern GHandle Y_B_Label_Txt;
extern GHandle Y_AB_Label;
extern GHandle Y_AB_Label_Txt;
extern GHandle Y_Trg_Label;
extern GHandle Y_Trg_Label_Txt;

extern GHandle Label_CH1;
extern GHandle CH1_RMS_Label;
extern GHandle CH1_RMS_Label_Txt;


extern GHandle CH1_SF_Label;
extern GHandle CH1_SF_Label_Txt;
extern GHandle CH1_Max_Label;
extern GHandle CH1_Max_Label_Txt;
extern GHandle CH1_PP_Label;
extern GHandle CH1_PP_Label_Txt;
extern GHandle CH1_RT_Label;
extern GHandle CH1_RT_Label_Txt;
extern GHandle CH1_Min_Label;
extern GHandle CH1_Min_Label_Txt;
extern GHandle CH1_Pk_Label;
extern GHandle CH1_Pk_Label_Txt;
extern GHandle CH1_P_Label;
extern GHandle CH1_P_Label_Txt;

extern GHandle Label_CH2;
extern GHandle CH2_Label;


// Function Prototypes



void guiCreate(void);
void guiShowPage(unsigned pageIndex);
void guiEventLoop(void);
void updateMeasData(void);


extern uint16_t ADC_buffer[][320];

static bool UI_data_ready;

#endif /* _GUI_H_ */

