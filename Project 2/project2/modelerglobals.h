#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.
/*
enum ModelControls
{ 
	XPOS, YPOS, ZPOS, HEIGHT, ROTATE, LEFTARMANGLE, RIGHTARMANGLE, HEAD, RHAND_X, RHAND_Y, RHAND_Z, 
	LHAND_X, LHAND_Y, LHAND_Z, KART_XPOS, KART_YPOS, KART_ZPOS, NUMCONTROLS
};
*/

enum ModelControls
{
	LEFTARMANGLE, RIGHTARMANGLE, RHAND_X, RHAND_Y, RHAND_Z,
	LHAND_X, LHAND_Y, LHAND_Z, KART_XPOS, KART_YPOS, KART_ZPOS, NUMCONTROLS
};

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f
#define COLOR_GRAY		0.5f, 0.5f, 0.5f
#define COLOR_BLACK		0.0f, 0.0f, 0.0f
#define COLOR_LESSBLACK 0.1f, 0.1f, 0.1f
#define COLOR_WHITE		1.0f, 1.0f, 1.0f
#define COLOR_BROWN		0.5f, 0.3f, 0.0f
#define COLOR_MARIOSKIN 0.9f, 0.7f, 0.5f

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))

#endif