/******************************************************************************/
/* This file has been generated by the uGFX-Studio                            */
/*                                                                            */
/* http://ugfx.org                                                            */
/******************************************************************************/
#include <stdio.h>
#include "colors.h"
#include "widgetstyles.h"
#include "gui.h"

#include "gwin_widget.h"
#include "myDraw.h"

#include "stm32f4xx_hal.h"
#include "adc.h"
#include "LCD.h"  //float2str
#include "math.h"

#include "scope.h"


#define TOP_UI_Y	30
#define BOTTOM_UI_Y	200 //240-40


#define DSO_DISP_W	320
#define DSO_DISP_H	170


#define T_Div_Button_ID 0
#define V_Div_Button_ID 1
#define Y_Trg_Button_ID 2


#define T_Div_List_ID 10
#define V_Div_List_ID 11
extern scope_t scope;
uint16_t prev_draw[ADC_bufsize]= {120};

int TIME_STEP=10;

int Trg_Y_val=120;

// GListeners
GListener glistener;

// GHandles
GHandle ghContainerPage0;

GHandle Label_CH;

GHandle T_Div_Button;
GHandle T_Div_Label;
GHandle T_Div_List;


GHandle V_Div_Button;
GHandle V_Div_Label;
GHandle V_Div_List;

GHandle Label_X;
GHandle X_A_Label;
GHandle X_A_Label_Txt;
GHandle X_B_Label;
GHandle X_B_Label_Txt;
GHandle X_F_Label;
GHandle X_F_Label_Txt;
GHandle X_AB_Label;
GHandle X_AB_Label_Txt;

GHandle Label_Y;
GHandle Y_A_Label;
GHandle Y_A_Label_Txt;
GHandle Y_B_Label;
GHandle Y_B_Label_Txt;
GHandle Y_AB_Label;
GHandle Y_AB_Label_Txt;
GHandle Y_Trg_Label;
GHandle Y_Trg_Button;

GHandle Label_CH1;
GHandle CH1_RMS_Label;
GHandle CH1_RMS_Label_Txt;


GHandle CH1_SF_Label;
GHandle CH1_SF_Label_Txt;
GHandle CH1_Max_Label;
GHandle CH1_Max_Label_Txt;
GHandle CH1_PP_Label;
GHandle CH1_PP_Label_Txt;
GHandle CH1_RT_Label;
GHandle CH1_RT_Label_Txt;
GHandle CH1_Min_Label;
GHandle CH1_Min_Label_Txt;
GHandle CH1_Pk_Label;
GHandle CH1_Pk_Label_Txt;
GHandle CH1_P_Label;
GHandle CH1_P_Label_Txt;

GHandle Label_CH2;
GHandle CH2_Label;
// Fonts
font_t dejavu_sans_16;
font_t dejavu_sans_12;
font_t dejavu_sans_10;

static void containerDraw_Back(GWidgetObject* gw, void* param)
{
	(void)param;
	// Clear container area
	gdispGFillArea(gw->g.display, gw->g.x, gw->g.y, gw->g.width, gw->g.height, gw->pstyle->background);
	// Draw the elements
	gdispFillArea(0, 0, 340, 240, black_studio);
}

static void createPagePage0(void)
{
	GWidgetInit wi;
	gwinWidgetClearInit(&wi);


	// create container widget: ghContainerPage0
	wi.g.show = FALSE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 320;
	wi.g.height = 240;
	wi.g.parent = 0;
	wi.text = "Container";
	wi.customDraw = containerDraw_Back;
	wi.customParam = 0;
	wi.customStyle = 0;
	ghContainerPage0 = gwinContainerCreate(0, &wi, 0);


	// Create label widget: T_Div_Label
	wi.g.show = TRUE;
	wi.g.x = 30;
	wi.g.y = 15;
	wi.g.width = 50;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "10us";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &divc;
	T_Div_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(T_Div_Label, FALSE);
	gwinSetFont(T_Div_Label, dejavu_sans_12);
	gwinRedraw(T_Div_Label);

	// Create label widget: V_Div_Label
	wi.g.show = TRUE;
	wi.g.x = 80;
	wi.g.y = 15;
	wi.g.width = 40;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "0.5V";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &divc;
	V_Div_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(V_Div_Label, FALSE);
	gwinSetFont(V_Div_Label, dejavu_sans_12);
	gwinRedraw(V_Div_Label);

	// Create label widget: Label_X
	wi.g.show = TRUE;
	wi.g.x = 120;
	wi.g.y = 0;
	wi.g.width = 10;
	wi.g.height = 30;
	wi.g.parent = ghContainerPage0;
	wi.text = "X";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &x;
	Label_X = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(Label_X, FALSE);

	// Create label widget: Label_Y
	wi.g.show = TRUE;
	wi.g.x = 220;
	wi.g.y = 0;
	wi.g.width = 10;
	wi.g.height = 30;
	wi.g.parent = ghContainerPage0;
	wi.text = "Y";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &y;
	Label_Y = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(Label_Y, FALSE);

	// Create label widget: Label_CH1
	wi.g.show = TRUE;
	wi.g.x = 0;
	wi.g.y = 200;
	wi.g.width = 40;
	wi.g.height = 20;
	wi.g.parent = ghContainerPage0;
	wi.text = "CH1";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &x;
	Label_CH1 = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(Label_CH1, FALSE);

	// Create label widget: Label_CH2
	wi.g.show = TRUE;
	wi.g.x = 0;
	wi.g.y = 220;
	wi.g.width = 40;
	wi.g.height = 20;
	wi.g.parent = ghContainerPage0;
	wi.text = "CH2";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &y;
	Label_CH2 = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(Label_CH2, FALSE);

	// Create label widget: Label_CH
	wi.g.show = TRUE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 30;
	wi.g.height = 30;
	wi.g.parent = ghContainerPage0;
	wi.text = "CH1";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &divc;
	Label_CH = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(Label_CH, FALSE);
	gwinSetFont(Label_CH, dejavu_sans_12);
	gwinRedraw(Label_CH);

	// Create label widget: X_A_Label
	wi.g.show = TRUE;
	wi.g.x = 130;
	wi.g.y = 0;
	wi.g.width = 10;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "A:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &x;
	X_A_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(X_A_Label, FALSE);
	gwinSetFont(X_A_Label, dejavu_sans_10);
	gwinRedraw(X_A_Label);

	// Create label widget: X_B_Label
	wi.g.show = TRUE;
	wi.g.x = 130;
	wi.g.y = 15;
	wi.g.width = 10;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "B:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &x;
	X_B_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(X_B_Label, FALSE);
	gwinSetFont(X_B_Label, dejavu_sans_10);
	gwinRedraw(X_B_Label);

	// create button widget: T_Div_Button
	wi.g.show = TRUE;
	wi.g.x = 30;
	wi.g.y = 0;
	wi.g.width = 50;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "T/Div";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = &divc;
	T_Div_Button = gwinButtonCreate(0, &wi);
	gwinSetTag(T_Div_Button,T_Div_Button_ID);
	gwinSetFont(T_Div_Button, dejavu_sans_12);
	gwinRedraw(T_Div_Button);

	// create button widget: V_Div_Button
	wi.g.show = TRUE;
	wi.g.x = 70;
	wi.g.y = 0;
	wi.g.width = 50;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "V/Div";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = &divc;
	V_Div_Button = gwinButtonCreate(0, &wi);
	gwinSetTag(V_Div_Button,V_Div_Button_ID);
	gwinSetFont(V_Div_Button, dejavu_sans_12);
	gwinRedraw(V_Div_Button);

	// Create label widget: Y_A_Label
	wi.g.show = TRUE;
	wi.g.x = 230;
	wi.g.y = 0;
	wi.g.width = 10;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "A:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &y;
	Y_A_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(Y_A_Label, FALSE);
	gwinSetFont(Y_A_Label, dejavu_sans_10);
	gwinRedraw(Y_A_Label);

	// Create label widget: Y_B_Label
	wi.g.show = TRUE;
	wi.g.x = 230;
	wi.g.y = 15;
	wi.g.width = 10;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "B:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &y;
	Y_B_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(Y_B_Label, FALSE);
	gwinSetFont(Y_B_Label, dejavu_sans_10);
	gwinRedraw(Y_B_Label);

	// Create label widget: X_F_Label
	wi.g.show = TRUE;
	wi.g.x = 170;
	wi.g.y = 0;
	wi.g.width = 10;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "F:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &x;
	X_F_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(X_F_Label, FALSE);
	gwinSetFont(X_F_Label, dejavu_sans_10);
	gwinRedraw(X_F_Label);

	// Create label widget: X_AB_Label
	wi.g.show = TRUE;
	wi.g.x = 170;
	wi.g.y = 15;
	wi.g.width = 20;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "A-B:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &x;
	X_AB_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(X_AB_Label, FALSE);
	gwinSetFont(X_AB_Label, dejavu_sans_10);
	gwinRedraw(X_AB_Label);

	// Create label widget: Y_AB_Label
	wi.g.show = TRUE;
	wi.g.x = 270;
	wi.g.y = 0;
	wi.g.width = 20;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "A-B:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &y;
	Y_AB_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(Y_AB_Label, FALSE);
	gwinSetFont(Y_AB_Label, dejavu_sans_10);
	gwinRedraw(Y_AB_Label);

	// Create label widget: Y_Trg_Label
	wi.g.show = TRUE;
	wi.g.x = 270;
	wi.g.y = 15;
	wi.g.width = 20;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "Trg:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &trg;
	Y_Trg_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(Y_Trg_Label, FALSE);
	gwinSetFont(Y_Trg_Label, dejavu_sans_10);
	gwinRedraw(Y_Trg_Label);

	// Create label widget: CH1_RMS_Label
	wi.g.show = TRUE;
	wi.g.x = 40;
	wi.g.y = 200;
	wi.g.width = 25;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "RMS:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_RMS_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_RMS_Label, FALSE);
	gwinSetFont(CH1_RMS_Label, dejavu_sans_10);
	gwinRedraw(CH1_RMS_Label);

	// Create label widget: CH1_SF_Label
	wi.g.show = TRUE;
	wi.g.x = 40;
	wi.g.y = 210;
	wi.g.width = 20;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "SF:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_SF_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_SF_Label, FALSE);
	gwinSetFont(CH1_SF_Label, dejavu_sans_10);
	gwinRedraw(CH1_SF_Label);

	// Create label widget: CH1_Max_Label
	wi.g.show = TRUE;
	wi.g.x = 110;
	wi.g.y = 200;
	wi.g.width = 25;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "Max:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_Max_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_Max_Label, FALSE);
	gwinSetFont(CH1_Max_Label, dejavu_sans_10);
	gwinRedraw(CH1_Max_Label);

	// Create label widget: CH1_PP_Label
	wi.g.show = TRUE;
	wi.g.x = 180;
	wi.g.y = 200;
	wi.g.width = 15;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "PP:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_PP_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_PP_Label, FALSE);
	gwinSetFont(CH1_PP_Label, dejavu_sans_10);
	gwinRedraw(CH1_PP_Label);

	// Create label widget: CH1_RT_Label
	wi.g.show = TRUE;
	wi.g.x = 250;
	wi.g.y = 200;
	wi.g.width = 15;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "RT:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_RT_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_RT_Label, FALSE);
	gwinSetFont(CH1_RT_Label, dejavu_sans_10);
	gwinRedraw(CH1_RT_Label);

	// Create label widget: CH1_Min_Label
	wi.g.show = TRUE;
	wi.g.x = 110;
	wi.g.y = 210;
	wi.g.width = 25;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "Min:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_Min_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_Min_Label, FALSE);
	gwinSetFont(CH1_Min_Label, dejavu_sans_10);
	gwinRedraw(CH1_Min_Label);

	// Create label widget: CH1_Pk_Label
	wi.g.show = TRUE;
	wi.g.x = 180;
	wi.g.y = 210;
	wi.g.width = 15;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "Pk:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_Pk_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_Pk_Label, FALSE);
	gwinSetFont(CH1_Pk_Label, dejavu_sans_10);
	gwinRedraw(CH1_Pk_Label);

	// Create label widget: CH1_P_Label
	wi.g.show = TRUE;
	wi.g.x = 250;
	wi.g.y = 210;
	wi.g.width = 10;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "P:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_P_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_P_Label, FALSE);
	gwinSetFont(CH1_P_Label, dejavu_sans_10);
	gwinRedraw(CH1_P_Label);

	// Create label widget: CH2_Label
	wi.g.show = TRUE;
	wi.g.x = 40;
	wi.g.y = 220;
	wi.g.width = 280;
	wi.g.height = 20;
	wi.g.parent = ghContainerPage0;
	wi.text = "";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &y;
	CH2_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH2_Label, FALSE);
	gwinSetFont(CH2_Label, dejavu_sans_10);
	gwinRedraw(CH2_Label);

	// Create list widget: V_Div_List
	wi.g.show = FALSE;
	wi.g.x = 70;
	wi.g.y = 30;
	wi.g.width = 50;
	wi.g.height = 70;
	wi.g.parent = ghContainerPage0;
	wi.text = "List1";
	wi.customDraw = gwinListDefaultDraw;
	wi.customParam = 0;
	wi.customStyle = &divc;
	V_Div_List = gwinListCreate(0, &wi, FALSE);
	gwinSetTag(V_Div_List,V_Div_List_ID);
	gwinListSetScroll(V_Div_List, scrollSmooth);
	gwinSetFont(V_Div_List, dejavu_sans_12);
	gwinRedraw(V_Div_List);
	gwinListAddItem(V_Div_List, "0.50V", FALSE);
	gwinListAddItem(V_Div_List, "0.25V", FALSE);
	gwinListAddItem(V_Div_List, "0.10V", FALSE);
	gwinListAddItem(V_Div_List, "0.05V", FALSE);

	gwinListSetSelected(V_Div_List, 0, FALSE);
	gwinListSetSelected(V_Div_List, 1, FALSE);
	gwinListSetSelected(V_Div_List, 2, FALSE);
	gwinListSetSelected(V_Div_List, 3, FALSE);

	// Create label widget: X_A_Label_Txt
	wi.g.show = TRUE;
	wi.g.x = 140;
	wi.g.y = 0;
	wi.g.width = 30;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "0.000";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &x;
	X_A_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(X_A_Label_Txt, FALSE);
	gwinSetFont(X_A_Label_Txt, dejavu_sans_10);
	gwinRedraw(X_A_Label_Txt);

	// Create label widget: X_B_Label_Txt
	wi.g.show = TRUE;
	wi.g.x = 140;
	wi.g.y = 15;
	wi.g.width = 30;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "0.000";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &x;
	X_B_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(X_B_Label_Txt, FALSE);
	gwinSetFont(X_B_Label_Txt, dejavu_sans_10);
	gwinRedraw(X_B_Label_Txt);

	// Create label widget: X_F_Label_Txt
	wi.g.show = TRUE;
	wi.g.x = 180;
	wi.g.y = 0;
	wi.g.width = 40;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "0.000";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &x;
	X_F_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(X_F_Label_Txt, FALSE);
	gwinSetFont(X_F_Label_Txt, dejavu_sans_10);
	gwinRedraw(X_F_Label_Txt);

	// Create label widget: X_AB_Label_Txt
	wi.g.show = TRUE;
	wi.g.x = 190;
	wi.g.y = 15;
	wi.g.width = 30;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "0.000";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &x;
	X_AB_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(X_AB_Label_Txt, FALSE);
	gwinSetFont(X_AB_Label_Txt, dejavu_sans_10);
	gwinRedraw(X_AB_Label_Txt);

	// Create label widget: Y_A_Label_Txt
	wi.g.show = TRUE;
	wi.g.x = 240;
	wi.g.y = 0;
	wi.g.width = 30;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "0.000";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &y;
	Y_A_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(Y_A_Label_Txt, FALSE);
	gwinSetFont(Y_A_Label_Txt, dejavu_sans_10);
	gwinRedraw(Y_A_Label_Txt);

	// Create label widget: Y_B_Label_Txt
	wi.g.show = TRUE;
	wi.g.x = 240;
	wi.g.y = 15;
	wi.g.width = 30;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "0.000";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &y;
	Y_B_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(Y_B_Label_Txt, FALSE);
	gwinSetFont(Y_B_Label_Txt, dejavu_sans_10);
	gwinRedraw(Y_B_Label_Txt);

	// Create label widget: Y_AB_Label_Txt
	wi.g.show = TRUE;
	wi.g.x = 290;
	wi.g.y = 0;
	wi.g.width = 30;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "0.000";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &y;
	Y_AB_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(Y_AB_Label_Txt, FALSE);
	gwinSetFont(Y_AB_Label_Txt, dejavu_sans_10);
	gwinRedraw(Y_AB_Label_Txt);

	// Create label widget: Y_Trg_Button
	wi.g.show = TRUE;
	wi.g.x = 290;
	wi.g.y = 15;
	wi.g.width = 30;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "0.000";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = &divc;
	Y_Trg_Button = gwinButtonCreate(0, &wi);
	gwinSetTag(Y_Trg_Button,Y_Trg_Button_ID);
	gwinSetFont(Y_Trg_Button ,dejavu_sans_10);
	gwinRedraw(Y_Trg_Button);







	// Create label widget: CH1_RMS_Label_Txt

	wi.g.show = TRUE;
	wi.g.x = 65;
	wi.g.y = 200;
	wi.g.width = 45;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text ="";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_RMS_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_RMS_Label_Txt, FALSE);
	gwinSetFont(CH1_RMS_Label_Txt, dejavu_sans_10);
	gwinRedraw(CH1_RMS_Label_Txt);

	// Create label widget: CH1_SF_Label_Txt
	wi.g.show = TRUE;
	wi.g.x = 60;
	wi.g.y = 210;
	wi.g.width = 50;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_SF_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_SF_Label_Txt, FALSE);
	gwinSetFont(CH1_SF_Label_Txt, dejavu_sans_10);
	gwinRedraw(CH1_SF_Label_Txt);

	// Create label widget: CH1_Max_Label_Txt
	wi.g.show = TRUE;
	wi.g.x = 135;
	wi.g.y = 200;
	wi.g.width = 45;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_Max_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_Max_Label_Txt, FALSE);
	gwinSetFont(CH1_Max_Label_Txt, dejavu_sans_10);
	gwinRedraw(CH1_Max_Label_Txt);

	// Create label widget: CH1_Min_Label_Txt

	wi.g.show = TRUE;
	wi.g.x = 135;
	wi.g.y = 210;
	wi.g.width = 45;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_Min_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_Min_Label_Txt, FALSE);
	gwinSetFont(CH1_Min_Label_Txt, dejavu_sans_10);
	gwinRedraw(CH1_Min_Label_Txt);

	// Create label widget: CH1_PP_Label_Txt

	wi.g.show = TRUE;
	wi.g.x = 195;
	wi.g.y = 200;
	wi.g.width = 55;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_PP_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_PP_Label_Txt, FALSE);
	gwinSetFont(CH1_PP_Label_Txt, dejavu_sans_10);
	gwinRedraw(CH1_PP_Label_Txt);

	// Create label widget: CH1_Pk_Label_Txt

	wi.g.show = TRUE;
	wi.g.x = 195;
	wi.g.y = 210;
	wi.g.width = 55;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_Pk_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_Pk_Label_Txt, FALSE);
	gwinSetFont(CH1_Pk_Label_Txt, dejavu_sans_10);
	gwinRedraw(CH1_Pk_Label_Txt);

	// Create label widget: CH1_RT_Label_Txt
	wi.g.show = TRUE;
	wi.g.x = 265;
	wi.g.y = 200;
	wi.g.width = 55;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_RT_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_RT_Label_Txt, FALSE);
	gwinSetFont(CH1_RT_Label_Txt, dejavu_sans_10);
	gwinRedraw(CH1_RT_Label_Txt);

	// Create label widget: CH1_P_Label_Txt
	wi.g.show = TRUE;
	wi.g.x = 260;
	wi.g.y = 210;
	wi.g.width = 60;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_P_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_P_Label_Txt, FALSE);
	gwinSetFont(CH1_P_Label_Txt, dejavu_sans_10);
	gwinRedraw(CH1_P_Label_Txt);

	// Create list widget: T_Div_List
	wi.g.show = FALSE;
	wi.g.x = 30;
	wi.g.y = 30;
	wi.g.width = 50;
	wi.g.height = 70;
	wi.g.parent = ghContainerPage0;
	wi.text = "List1";
	wi.customDraw = gwinListDefaultDraw;
	wi.customParam = 0;
	wi.customStyle = &divc;
	T_Div_List = gwinListCreate(0, &wi, FALSE);
	gwinSetTag(T_Div_List,T_Div_List_ID);
	gwinListSetScroll(T_Div_List, scrollSmooth);
	gwinSetFont(T_Div_List, dejavu_sans_12);
	gwinRedraw(T_Div_List);
    gwinListAddItem(T_Div_List, "10us", TRUE);
    gwinListAddItem(T_Div_List, "25us", TRUE);
    gwinListAddItem(T_Div_List, "50us", TRUE);
    gwinListAddItem(T_Div_List, "100us", TRUE);
    gwinListAddItem(T_Div_List, "500us", TRUE);
    gwinListAddItem(T_Div_List, "1ms", TRUE);
	gwinListSetSelected(T_Div_List, 0, FALSE);
	gwinListSetSelected(T_Div_List, 1, FALSE);
	gwinListSetSelected(T_Div_List, 2, FALSE);
	gwinListSetSelected(T_Div_List, 3, FALSE);
	gwinListSetSelected(T_Div_List, 4, FALSE);
	gwinListSetSelected(T_Div_List, 5, FALSE);
}


void guiShowPage(unsigned pageIndex)
{
	// Hide all pages
	gwinHide(ghContainerPage0);

	// Show page selected page
	switch (pageIndex) {
	case 0:
		gwinShow(ghContainerPage0);
		break;

	default:
		break;
	}
}
uint16_t getRemapADC()
{
  //ADC_val =0~ 4096
  //linear map 0~4096 to 30~200,also flip Y vertically    
  uint16_t ADC_val = HAL_ADC_GetValue(&hadc1);
  uint16_t remap = BOTTOM_UI_Y - ((ADC_val)*DSO_DISP_H/4096);
  //ensure data draw won't overwite UI
  return clamp(remap,TOP_UI_Y,BOTTOM_UI_Y);
}
void waveDisplay()
{
  uint16_t adc_cnt = 0;
  //Assume 42MHz sample rate---> down scale to 420Hz
  scope.buf[0][0] = getRemapADC();
  int x = 1;
  //get 320 adc data, draw scope 
  while(TRUE)
  {
  	if(adc_cnt > TIME_STEP)
  	  {
  	  	 
  	  	 scope.buf[0][x] = getRemapADC();
  	  	 gdispDrawLine( x,prev_draw[x-1],x,prev_draw[x],Black);
      	 gdispDrawLine( x,scope.buf[0][x-1],x,scope.buf[0][x],Green);
      	 if(x==ADC_bufsize-1) //buffer 320 ready
   			break;
   	     x++;
   		 adc_cnt = 0;
  	  }
  	  	adc_cnt++;
  	  
   }
   int i;
   for(i=0;i<ADC_bufsize;i++)
   		prev_draw[i]= scope.buf[0][i];
   	updateMeasData();
       
}

void updateMeasData()
{
	updateMax();
	updateMin();
	updateP2P();
	updatePK();
	updateRMS();
	char max_s[16];
	char min_s[16];
	char rms_s[16];
	char val_str[16];
	//snprintf(updateVal, sizeof(updateVal), "%f",getMax());
	//sprintf(updateVal,"%0.3f",getMax());
	float2str(getRMS(),val_str,3);
	gwinSetText(CH1_RMS_Label_Txt,val_str,TRUE);
	float2str(getMax(),val_str,3);
	gwinSetText(CH1_Max_Label_Txt,val_str,TRUE);
	float2str(getMin(),val_str,3);
	gwinSetText(CH1_Min_Label_Txt,val_str,TRUE);
	float2str(getP2P(),val_str,3);
	gwinSetText(CH1_PP_Label_Txt,val_str,TRUE);
	float2str(getPK(),val_str,3);
	gwinSetText(CH1_Pk_Label_Txt,val_str,TRUE);	
	
}




void guiCreate(void)
{
	GWidgetInit wi;

	// Prepare fonts
	dejavu_sans_16 = gdispOpenFont("DejaVuSans16");
	dejavu_sans_12 = gdispOpenFont("DejaVuSans12");
	dejavu_sans_10 = gdispOpenFont("DejaVuSans10");

	// Prepare images

	// GWIN settings
	gwinWidgetClearInit(&wi);
	gwinSetDefaultFont(dejavu_sans_16);
	gwinSetDefaultStyle(&white, FALSE);
	gwinSetDefaultColor(black_studio);
	gwinSetDefaultBgColor(black_studio);

	// Create all the display pages
	createPagePage0();

	// Select the default display page


	guiShowPage(0);

 
}

GHandle *opened_gh=NULL;

inline void btn_event(uint16_t tag)
{

	switch(tag)
	{
		case T_Div_Button_ID:
			if(gwinGetTag(*opened_gh) == V_Div_List_ID)
				gwinSetVisible( V_Div_List,FALSE);
			gwinSetVisible(T_Div_List, TRUE);
			opened_gh = &T_Div_List;
		break;
		case V_Div_Button_ID:
			if(gwinGetTag(*opened_gh) == T_Div_List_ID)
				gwinSetVisible( T_Div_List,FALSE);
			gwinSetVisible(V_Div_List, TRUE);
			opened_gh = &V_Div_List;
		break;	
		case Y_Trg_Button_ID:
			opened_gh = &Y_Trg_Button;
			drawDotLineHV(0, Trg_Y_val, 320, Trg_Y_val, Red);
		break;
	}
}
//Set text if select item
inline void lst_event(GHandle gh,uint16_t tag,GEvent* pe)
{
	switch(tag)
	{
		case T_Div_List_ID:
			gwinSetText(T_Div_Label,gwinListItemGetText(gh,((GEventGWinList *)pe)->item),TRUE);	
		break;
		case V_Div_List_ID:
			gwinSetText(V_Div_Label,gwinListItemGetText(gh,((GEventGWinList *)pe)->item),TRUE);		
		break;
			
	}
}


void guiEventLoop(void)
{
	//Setup code
	GEvent* pe;
	GHandle gh;
	GSourceHandle gs;	//for listen mouse event 
	GEventMouse     *pem;
	uint16_t tag;

	gs = ginputGetMouse(0);//for listen mouse event 
  	geventAttachSource(&glistener, gs, GLISTEN_MOUSEDOWNMOVES|GLISTEN_MOUSEMETA);
	//Inf 
	while (1) 
	{
		// Get an event
		//stuck here until event is received
   		waveDisplay();
 
		pe = geventEventWait(&glistener,5);
		switch (pe->type) 
		{
			case GEVENT_GWIN_BUTTON:
				tag= gwinGetTag(((GEventGWinButton *)pe)->gwin);
				btn_event(tag);
			break;
			case GEVENT_GWIN_LIST:
				gh = ((GEventGWinList *)pe)->gwin;
				tag= gwinGetTag(gh);

				if(gwinListItemIsSelected(gh, ((GEventGWinList *)pe)->item))
				{
					lst_event(gh,tag,pe);
					gwinSetVisible(gh, FALSE);
				}
			break;
			default:
				if(opened_gh==NULL)
					break;
				tag = gwinGetTag(*opened_gh);
				
				switch(tag)
				{
					case Y_Trg_Button_ID:
						pem = (GEventMouse *)pe;
					 	if(pem->y >TOP_UI_Y && pem->y< BOTTOM_UI_Y)
					 	{
							//Clean previous draw
							drawDotLineHV(0, Trg_Y_val, 320, Trg_Y_val, Black);
							Trg_Y_val = pem->y;
							drawDotLineHV(0, Trg_Y_val, 320, Trg_Y_val, Red);
					 	}
					break;
					case V_Div_List_ID:
					case T_Div_List_ID:
						if(gwinListItemIsSelected(*opened_gh, ((GEventGWinList *)pe)->item))
						{
							lst_event(*opened_gh,tag,pe);
							gwinSetVisible(*opened_gh, FALSE);
							opened_gh = NULL;
						}
					break;
						
				}
				
			break;

		}

	}
}