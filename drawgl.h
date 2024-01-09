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

#pragma once

//-------------------------------------------------------------------//

extern bool oglSubtractive;

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
);

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
GLubyte a12);

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
);

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
);

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
);

void __cdecl Z8FillRGBAiiiihhhh(

float a1, 
float a2, 
float a3, 
float a4, 
GLubyte a5, 
GLubyte a6, 
GLubyte a7, 
GLubyte a8
);







