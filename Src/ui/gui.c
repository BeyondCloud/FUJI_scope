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
#define DSO_CENTER_Y (BOTTOM_UI_Y+TOP_UI_Y)/2


#define DSO_DISP_W	320
#define DSO_DISP_H	170


#define T_Div_Button_ID 0
#define V_Div_Button_ID 1
#define Y_Trg_Button_ID 2
#define X_A_Button_ID 3
#define X_B_Button_ID 4
#define Y_A_Button_ID 5
#define Y_B_Button_ID 6


#define T_Div_List_ID 10
#define V_Div_List_ID 11
#define VERTI 0
#define HORIZ 1


extern scope_t scope;
int cur_draw[ADC_bufsize]= {120};
int prev_draw[ADC_bufsize]= {120};
int Trg_cnt=0;
int TIME_STEP=10;
int Trg_Y_val=DSO_CENTER_Y;
int X_A_val=100;
int X_B_val=300;
int Y_A_val=50;
int Y_B_val=180;

int Trg_pixel_range_PM=2;//PM means plus minus
bool lst_opened= FALSE;
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
GHandle X_A_Button;
GHandle X_B_Label;
GHandle X_B_Button;
GHandle X_F_Label;
GHandle X_F_Label_Txt;
GHandle X_AB_Label;
GHandle X_AB_Label_Txt;

GHandle Label_Y;
GHandle Y_A_Label;
GHandle Y_A_Button;
GHandle Y_B_Label;
GHandle Y_B_Button;
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
GHandle CH1_AVG_Label;
GHandle CH1_AVG_Label_Txt;
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

	// Create label widget: CH1_AVG_Label
	wi.g.show = TRUE;
	wi.g.x = 250;
	wi.g.y = 200;
	wi.g.width = 25;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "AVG:";
	wi.customDraw = gwinLabelDrawJustifiedLeft;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_AVG_Label = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_AVG_Label, FALSE);
	gwinSetFont(CH1_AVG_Label, dejavu_sans_10);
	gwinRedraw(CH1_AVG_Label);

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

	// Create label widget: X_A_Button
	wi.g.show = TRUE;
	wi.g.x = 140;
	wi.g.y = 0;
	wi.g.width = 30;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "0.000";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = &divc;
	X_A_Button = gwinButtonCreate(0, &wi);
	gwinSetTag(X_A_Button,X_A_Button_ID);
	gwinSetFont(X_A_Button, dejavu_sans_10);
	gwinRedraw(X_A_Button);

	// Create label widget: X_B_Button
	wi.g.show = TRUE;
	wi.g.x = 140;
	wi.g.y = 15;
	wi.g.width = 30;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "0.000";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = &divc;
	X_B_Button = gwinButtonCreate(0, &wi);
	gwinSetTag(X_B_Button,X_B_Button_ID);
	gwinSetFont(X_B_Button, dejavu_sans_10);
	gwinRedraw(X_B_Button);




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

	// Create label widget: Y_A_Button
	wi.g.show = TRUE;
	wi.g.x = 240;
	wi.g.y = 0;
	wi.g.width = 30;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "0.000";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = &divc;
	Y_A_Button = gwinButtonCreate(0, &wi);
	gwinSetTag(Y_A_Button,Y_A_Button_ID);
	gwinSetFont(Y_A_Button, dejavu_sans_10);
	gwinRedraw(Y_A_Button);

	// Create label widget: Y_B_Button
	wi.g.show = TRUE;
	wi.g.x = 240;
	wi.g.y = 15;
	wi.g.width = 30;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "0.000";
	wi.customDraw = gwinButtonDraw_Normal;
	wi.customParam = 0;
	wi.customStyle = &divc;
	Y_B_Button = gwinButtonCreate(0, &wi);
	gwinSetTag(Y_B_Button,Y_B_Button_ID);
	gwinSetFont(Y_B_Button, dejavu_sans_10);
	gwinRedraw(Y_B_Button);

	// Create label widget: Y_AB_Label_Txt
	wi.g.show = TRUE;
	wi.g.x = 290;
	wi.g.y = 0;
	wi.g.width = 30;
	wi.g.height = 15;
	wi.g.parent = ghContainerPage0;
	wi.text = "";
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
	wi.text = "1.500";
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

	// Create label widget: CH1_AVG_Label_Txt
	wi.g.show = TRUE;
	wi.g.x = 275;
	wi.g.y = 200;
	wi.g.width = 45;
	wi.g.height = 10;
	wi.g.parent = ghContainerPage0;
	wi.text = "";
	wi.customDraw = gwinLabelDrawJustifiedRight;
	wi.customParam = 0;
	wi.customStyle = &x;
	CH1_AVG_Label_Txt = gwinLabelCreate(0, &wi);
	gwinLabelSetBorder(CH1_AVG_Label_Txt, FALSE);
	gwinSetFont(CH1_AVG_Label_Txt, dejavu_sans_10);
	gwinRedraw(CH1_AVG_Label_Txt);

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
    gwinListAddItem(T_Div_List, "100", TRUE);
    gwinListAddItem(T_Div_List, "30", TRUE);
    gwinListAddItem(T_Div_List, "10", TRUE);
    gwinListAddItem(T_Div_List, "5", TRUE);
    gwinListAddItem(T_Div_List, "3", TRUE);
    gwinListAddItem(T_Div_List, "1", TRUE);
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
inline float screenY_to_V(int Y)
{
	//200-->0 ,30->3
	return (DSO_DISP_H-(Y-TOP_UI_Y))*ADC_Vmax/DSO_DISP_H;
}
inline float screenX_to_T(int X)
{
	//200-->0 ,30->3
	return X*TIME_STEP;
}
//the data we ready to put inside cur_draw
inline int ADC_to_screenY(int ADC_val)
{
  //ADC_val =0~ 4096
  //linear map 0~4096 to 0~DSO_DISP_H ,flip Y vertically
  int remap = DSO_DISP_H - ((ADC_val)*DSO_DISP_H/4096);
  remap = remap + TOP_UI_Y ;//-(getAVG()-DSO_CENTER_Y)
  //ensure data draw won't overwite UI
  return clamp(remap,TOP_UI_Y,BOTTOM_UI_Y);
}
bool isTriggered(int ADC_data,int prev_ADC_data)
{
	int del = abs(ADC_to_screenY(ADC_data)-Trg_Y_val);
	return ((del<=Trg_pixel_range_PM) &&(prev_ADC_data<=ADC_data));
}
void waveDisplay()
{
  uint8_t adc_cnt = 0;
  //Assume 42MHz sample rate---> down scale to 420Hz
  scope.adc_buf[0][0] = HAL_ADC_GetValue(&hadc1);
  int x = 1;
  bool Trg_flag = false;
  Trg_cnt = 0;
  //get 320 adc data
  //DONOT draw wave in this field ,do it later instead. 
  while(TRUE)
  {
  	if(adc_cnt > TIME_STEP)
  	  {	 
  	  	 scope.adc_buf[0][x] = HAL_ADC_GetValue(&hadc1);

  	  	 	if(isTriggered(scope.adc_buf[0][x],scope.adc_buf[0][x-1]))
	  	  	{
	  	  		Trg_cnt++;
	  	  		 if(!Trg_flag)
  	  	 		{
		  	  		x=0;
		  	  		Trg_flag = TRUE;
		  	 	}
	  	  	}
  	  	 
   	  	if(x==ADC_bufsize-1) //buffer 320 ready
   			break;
   	     x++; 
   		 adc_cnt = 0;
  	  }
  	  	adc_cnt++;
   }
   //now draw your wave 
      if(!lst_opened)
   {
		//redraw_grid();
		for(x=0;x<ADC_bufsize;x++)
		{
			cur_draw[x] =  ADC_to_screenY(scope.adc_buf[0][x]);
		}

		for(x=1;x<ADC_bufsize;x++)
		{
			gdispDrawLine( x,prev_draw[x-1],x,prev_draw[x],Black);
		  	gdispDrawLine( x,cur_draw[x-1],x,cur_draw[x],Green);
		}


		for(x=0;x<ADC_bufsize;x++)
		{
			prev_draw[x]= cur_draw[x];
		}
		updateMeasData();
		redraw_cursor();
   	}
       
}

void updateMeasData()
{
	updateMax();
	updateMin();
	updateP2P();
	updatePK();
	updateRMS();
	updateAVG();
	char val_str[16];
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
	float2str(getAVG(),val_str,3);
	gwinSetText(CH1_AVG_Label_Txt,val_str,TRUE);	
	float2str(Trg_cnt,val_str,1);
	gwinSetText(CH1_SF_Label_Txt,val_str,TRUE);	
	
		
}
void redraw_cursor()
{
	drawDotLineHV(0, Trg_Y_val, 320, Trg_Y_val, Red);
	drawDotLineHV(0, Y_A_val, 320, Y_A_val, Yellow);
	drawDotLineHV(0, Y_B_val, 320, Y_B_val, Yellow);
	drawDotLineHV(X_A_val,TOP_UI_Y, X_A_val,BOTTOM_UI_Y, Yellow);
	drawDotLineHV(X_B_val,TOP_UI_Y, X_B_val,BOTTOM_UI_Y, Yellow);
		
}/*
void redraw_grid()
{
	//horizontal grid
	
	float y_step=DSO_DISP_H/6;
	int i =0;
	float cur_y=y_step+TOP_UI_Y;
	for(i;i<5;i++)
	{
		drawDotLineHV(0, (int)cur_y, 320, (int)cur_y, navy_studio);
		cur_y+=y_step;
	}
	//vertical grid
	for(i=0;i<320;i+=32)
		drawDotLineHV(i,TOP_UI_Y, i,BOTTOM_UI_Y, navy_studio);
	
	
	int x,y;
	for(x = 32;x<320;x+=32)
	{
		for(y = 59;y<200;y+=29)
			gdispDrawPixel(x, y, navy_studio);
	}
						
}
*/


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
			lst_opened = TRUE;
			gwinSetVisible(T_Div_List, TRUE);
			opened_gh = &T_Div_List;
		break;
		case V_Div_Button_ID:
			if(gwinGetTag(*opened_gh) == T_Div_List_ID)
				gwinSetVisible( T_Div_List,FALSE);
			lst_opened = TRUE;
			gwinSetVisible(V_Div_List, TRUE);
			opened_gh = &V_Div_List;
		break;	
		case Y_Trg_Button_ID:
			opened_gh = &Y_Trg_Button;
		break;
		case Y_A_Button_ID:
			opened_gh = &Y_A_Button;
		break;
		case Y_B_Button_ID:
			opened_gh = &Y_B_Button;
		break;
		case X_A_Button_ID:
			opened_gh = &X_A_Button;
		break;
		case X_B_Button_ID:
			opened_gh = &X_B_Button;
		break;

	}
}
//Set text if select item
inline void lst_event(GHandle gh,uint16_t tag,GEvent* pe)
{
	char* chp = gwinListItemGetText(gh,((GEventGWinList *)pe)->item);
	int i;
	switch(tag)
	{
		case T_Div_List_ID:
			sscanf(chp, "%d", &i);			
			gwinSetText(T_Div_Label,chp,TRUE);	
			TIME_STEP=i; //3.5/6.5	//3200*3.5/6.5---500Hz
		break;
		case V_Div_List_ID:
			gwinSetText(V_Div_Label,chp,TRUE);	

		break;
			
	}
}
inline void resetCursor(GHandle gh,int *target_val,GEventMouse *pem,int HV)
{
	if(pem->y < TOP_UI_Y || pem->y > BOTTOM_UI_Y)
			return;
	char val_str[16];
		//Clean previous draw
	if(HV==HORIZ)
	{
		//update button text
		drawDotLineHV(0, *target_val, 320,*target_val, Black);
		*target_val = pem->y;
		float2str(screenY_to_V(pem->y),val_str,3);
		gwinSetText(gh,val_str,TRUE);	
		//update A-B label text
		float f = screenY_to_V(Y_A_val) - screenY_to_V(Y_B_val);
		float2str(f,val_str,3);
		gwinSetText(Y_AB_Label_Txt,val_str,TRUE);
	}
	else
	{
		drawDotLineHV(*target_val, TOP_UI_Y,*target_val,BOTTOM_UI_Y, Black);
		*target_val = pem->x;
		float2str(screenX_to_T(pem->x),val_str,0);
		gwinSetText(gh,val_str,TRUE);	

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
	char val_str[16];
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
					lst_opened = FALSE;
					gdispFillArea(0,TOP_UI_Y,320,DSO_DISP_H,Black);
					gwinSetVisible(gh, FALSE);
				}
			break;
			default:
				if(opened_gh==NULL)
					break;
				tag = gwinGetTag(*opened_gh);
				pem = (GEventMouse *)pe;	 	
				switch(tag)
				{
					case Y_Trg_Button_ID:
						resetCursor(Y_Trg_Button,&Trg_Y_val,pem,HORIZ);
					break;
					case Y_A_Button_ID:
						if(pem->y >=Y_B_val)
							break;
						resetCursor(Y_A_Button,&Y_A_val,pem,HORIZ);
					break;
					case Y_B_Button_ID:
						if(pem->y <=Y_A_val)
							break;
						resetCursor(Y_B_Button,&Y_B_val,pem,HORIZ);
					break;
					case X_A_Button_ID:
						if(pem->x >=X_B_val)
							break;
						resetCursor(X_A_Button,&X_A_val,pem,VERTI);
					break;
					case X_B_Button_ID:
						if(pem->x <=X_A_val)
							break;
						resetCursor(X_B_Button,&X_B_val,pem,VERTI);
					break;
					case V_Div_List_ID:
					case T_Div_List_ID:
						if(gwinListItemIsSelected(*opened_gh, ((GEventGWinList *)pe)->item))
						{
							lst_event(*opened_gh,tag,pe);
							lst_opened = FALSE;
							gdispFillArea(0,TOP_UI_Y,320,DSO_DISP_H,Black);
					
							gwinSetVisible(*opened_gh, FALSE);
							opened_gh = NULL;
						}
					break;
						
				}
				
			break;

		}

	}
}