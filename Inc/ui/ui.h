#ifndef __UI_H__
#define __UI_H__


#define BTN_NONE  0
#define BTN_NEXT  1
#define BTN_PREV  2
#define BTN_PLUS  3
#define BTN_MINUS 4
static GConsoleObject     gc;
static GListener        gl;
static font_t         font;
static coord_t          bWidth, bWidth2, bHeight;
static GHandle          ghc;
static coord_t          swidth, sheight;

static void DrawHeader(const char *title, bool_t btnNext, bool_t btnPrev, bool_t btnPlusMinus);
void UserInterface();

static int CheckButtons(GEventMouse *pem);

#endif //__UI_H__
