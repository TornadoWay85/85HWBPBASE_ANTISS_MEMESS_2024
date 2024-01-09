///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 85 HARDWARE BREAKPOINT BASE
//
// BY _85_ , (2024)
//
// Credits: Russian bases, OGC and Kyros Base code and ideas, gamedeception guys, unknowncheats.me, and VALVE!
//
// Tested on latest Steam CS version (Jan2024), beta versions, non-steam v43, maybe others
//
// https://cs85-etkboyscout.blogspot.com
// https://www.youtube.com/@TornadoWayOfficial
// david_85_arg@hotmail.com
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "mainheaders.h"

//-------------------------------------------------------------------//

bool oglSubtractive = false;

//-------------------------------------------------------------------//

void __stdcall ZN10cHexagonal8DrawLineEiiiiiiii(
												
float a1, 
float a2, 
float a3, 
float a4, 
GLubyte a5, 
GLubyte a6, 
GLubyte a7, 
GLubyte a8
)
{
	float v8; //
    float v9; //
    float v10; //
    float v11; //

	v8 = (long double)a2;
    v9 = (long double)a1;
	v10 = (long double)a4;
    v11 = (long double)a3;

    glPushMatrix();
    glLoadIdentity();
    glDisable(0xDE1u);
    glEnable(0xBE2u);
    glBlendFunc(0x302u, 0x303u);
    glColor4ub(a5, a6, a7, a8);
    glLineWidth(3.0);
    glBegin(1u);
    glVertex2f(v9, v8);
    glVertex2f(v11, v10);
    glEnd();
    glDisable(0xBE2u);
    glPopMatrix();
    glEnable(0xDE1u);
}

//-------------------------------------------------------------------//

void __stdcall ZN10cHexagonal40DrawFillRectangleWithGradientRightToLeftEiiiiiiiiiiii(
																					 																				 
float a1, 																				 
float a2, 																				 
float a3, 																				 
float a4, 
GLubyte a5, 																				 
GLubyte a6, 																				 
GLubyte a7, 																				 
GLubyte a8, 																				 
GLubyte a9, 																				 
GLubyte a10,																				 
GLubyte a11, 																					 
GLubyte a12)
{
	float v12 = (long double)a2;
    float v13 = (long double)a1;

	float v14 = (long double)(a2 + a4);
    float v15 = (long double)a1;

	float v16 = (long double)(a2 + a4);
    float v17 = (long double)(a1 + a3);

	float v18 = (long double)a2;
    float v19 = (long double)(a1 + a3);

    glPushMatrix();
    glLoadIdentity();
    glDisable(0xDE1u);
    glEnable(0xBE2u);
    glBlendFunc(0x302u, 0x303u);
    glBegin(7u);
    glColor4ub(a5, a6, a7, a8);//rgba
    glVertex2f(v13, v12);
    glVertex2f(v15, v14);
    glColor4ub(a9, a10, a11, a12);//rr gg bb aa
    glVertex2f(v17, v16);
    glVertex2f(v19, v18);
    glEnd();
    glDisable(0xBE2u);
    glPopMatrix();
    glEnable(0xDE1u);
}

//-------------------------------------------------------------------//

void __stdcall ZN10cHexagonal37DrawFillRectangleWithGradientUpToDownEiiiiiiiiiiii(

float a1, 
float a2, 
float a3, 
float a4, 																			  
GLubyte a5, 																		  
GLubyte a6, 																		  
GLubyte a7, 																		  
GLubyte a8, 																	 																		  
GLubyte a9, 																		  
GLubyte a10, 																			  
GLubyte a11, 																			  
GLubyte a12
)
{
   
	float v12 = 0; //
    float v13 = 0; //
    float v14 = 0; //
    float v15 = 0; //
    float v16 = 0; //
    float v17 = 0; //
    float v18 = 0; //
    float v19 = 0; //

	v12 = (long double)a2;
    v13 = (long double)a1;
	v14 = (long double)a2;
    v15 = (long double)(a1 + a3);
	v16 = (long double)(a2 + a4);
    v17 = (long double)(a1 + a3);
	v18 = (long double)(a2 + a4);
    v19 = (long double)a1;

    glPushMatrix();
    glLoadIdentity();
    glDisable(0xDE1u);
    glEnable(0xBE2u);
    glBlendFunc(0x302u, 0x303u);
    glBegin(7u);
    glColor4ub(a5, a6, a7, a8);
    glVertex2f(v13, v12);
    glVertex2f(v15, v14);
    glColor4ub(a9, a10, a11, a12);
    glVertex2f(v17, v16);
    glVertex2f(v19, v18);
    glEnd();
    glDisable(0xBE2u);
    glPopMatrix();
    glEnable(0xDE1u);
}

//-------------------------------------------------------------------//

void __stdcall ZN10cHexagonal16DrawFillTriangleEiiiiiiiiii(
														   
float a1, 
float a2, 
float a3, 
float a4, 
float a5, 
float a6, 
GLubyte a7, 
GLubyte a8, 
GLubyte a9, 
GLubyte a10
)
{
	float v10 = 0; //
    float v11 = 0; //
    float v12 = 0; //
    float v13 = 0; //
    float v14 = 0; //
    float v15 = 0; //

	v10 = (long double)a2;
    v11 = (long double)a1;
    v12 = (long double)a4;
    v13 = (long double)a3;
    v14 = (long double)a6;
    v15 = (long double)a5;

    glPushMatrix();
    glLoadIdentity();
    glDisable(0xDE1u);
    glEnable(0xBE2u);
    glBlendFunc(0x302u, 0x303u);
    glShadeModel(0x1D01u);
    glColor4ub(a7, a8, a9, a10);
    glBegin(4u);
    glVertex2f(v11, v10);
    glVertex2f(v13, v12);
    glVertex2f(v15, v14);
    glEnd();
    glDisable(0xBE2u);
    glPopMatrix();
    glEnable(0xDE1u);
}

//-------------------------------------------------------------------//

void __stdcall ZN10cHexagonal36DrawFillTriangleWithGradientUpToDownEiiiiiiiiiiiiii(
																				   
float a1, 																		   
float a2, 																		   
float a3, 																		   
float a4, 																		   
float a5, 																		   
float a6, 																	   
GLubyte a7,																	   
GLubyte a8,																		   
GLubyte a9,																	   
GLubyte a10,													   
GLubyte a11, 																			   
GLubyte a12, 																			   
GLubyte a13, 																			   
GLubyte a14
)
{
	float v14 = 0; //
    float v15 = 0; //
    float v16 = 0; //
    float v17 = 0; //
    float v18 = 0; //
    float v19 = 0; //

	v14 = (long double)a2;
    v15 = (long double)a1;
	v16 = (long double)a4;
    v17 = (long double)a3;
	v18 = (long double)a6;
    v19 = (long double)a5;

    glPushMatrix();
    glLoadIdentity();
    glDisable(0xDE1u);
    glEnable(0xBE2u);
    glBlendFunc(0x302u, 0x303u);
    glShadeModel(0x1D01u);
    glBegin(4u);
    glColor4ub(a7, a8, a9, a10);
    glVertex2f(v15, v14);
    glVertex2f(v17, v16);
    glColor4ub(a11, a12, a13, a14);
    glVertex2f(v19, v18);
    glEnd();
    glDisable(0xBE2u);
    glPopMatrix();
    glEnable(0xDE1u);
}

//-------------------------------------------------------------------//

void __cdecl Z8FillRGBAiiiihhhh(

float a1, 
float a2, 
float a3, 
float a4, 
GLubyte a5, 
GLubyte a6, 
GLubyte a7, 
GLubyte a8
)
{
  float v8 = 0; //
  float v9 = 0; //
  float v10 = 0; //
  float v11 = 0; //
  float v12 = 0; //
  float v13 = 0; //
  float v14 = 0; //
  float v15 = 0; //

  glPushMatrix();
  glMatrixMode(0x1700u);
  glLoadIdentity();
  glDisable(0xDE1u);
  glEnable(0xBE2u);
  glBlendFunc(0x302u, 0x303u);
  glShadeModel(0x1D01u);
  glColor4ub(a5, a6, a7, a8);
  glBegin(9u);
  v8 = (long double)a2;
  v9 = (long double)a1;
  glVertex2f(v9, v8);
  v10 = (long double)a2;
  v11 = (long double)(a1 + a3);
  glVertex2f(v11, v10);
  v12 = (long double)(a2 + a4);
  v13 = (long double)(a1 + a3);
  glVertex2f(v13, v12);
  v14 = (long double)(a2 + a4);
  v15 = (long double)a1;
  glVertex2f(v15, v14);
  glEnd();
  glDisable(0xBE2u);
  glPopMatrix();
  glEnable(0xDE1u);
}

//-------------------------------------------------------------------//






