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

#include "../mainheaders.h"

//-------------------------------------------------------------------//

bool clientheightlower=false;
bool clientheighthigher=false;
bool clientwidthtlower=false;
bool clientwidththigher=false;

//-------------------------------------------------------------------//

unsigned int uiNeedCallFunc=0;
unsigned int ArraySize=0;
GLubyte* ArraySS=0;
unsigned int arrayscaler1=0;
unsigned int arrayscaler2=0;

//-------------------------------------------------------------------//

//__declspec(naked) 
void __stdcall CallGate_GL_Read_Pixels(GLint x, GLint y, GLsizei width, GLsizei height,
								       GLenum format, GLenum type, GLvoid* data)
{

//	MessageBox(0,"RP: CallGate_GL_Read_Pixels called.\0",0,0);
	if(g_Screen_Updated)
	{

		if(width>g_Screen.iWidth)
		{
			message_hook = 11;
		}
		else if(width<g_Screen.iWidth)
		{
			message_hook = 12;
		}

		if(height>g_Screen.iHeight)
		{
			message_hook = 13;
		}
		else if(height<g_Screen.iHeight)
		{
			message_hook = 14;
		}

		if(x!=0)
		{
			message_hook = 15;
		}

		if(y!=0)
		{
			message_hook = 16;
		}

	}
	else
	{
		message_hook = 17;
	}

	//

	// Esto solamente rellena un búffer y no requiere de que se haya inicializado calcscreen..
	//
	if(data)
	{
	//	MessageBox(0,"RP: data OK\0",0,0);

		// hack activado
		if(CVARS.hackon)
		{
		//	MessageBox(0,"RP: hackon OK\0",0,0);

		//	bAntiSSInstalledOK -> esto se hace automático al inicio del hack (TRUE)
		//	bAntiSSStarted -> esto se hace manual desde el menu de antiss, y se lo activa (TRUE)

			if(bAntiSSInstalledOK)// instalado automáticamente
			{
				if(bAntiSSStarted)// iniciado manualmente
				{
					if(CVARS.antiss)// operativo por comando
					{

					//	MessageBox(0,"RP: GOING ON 1\0",0,0);

						ArraySize = (width * height * 3);
						ArraySS = (GLubyte*)data;

					//	MessageBox(0,"RP: GOING ON 2\0",0,0);

					//	char GG1[200];
					//	sprintf(GG1, "(%d %d %d %d ) = ArraySize %d\0", x,y,width, height, ArraySize);
					//	MessageBox(0,GG1,0,0);



						if(!CVARS.memess && g_CleanSS)
						{
							message_hook = 1;

							//

						//	MessageBox(0,"RP: OK\0",0,0);

							for(arrayscaler1=0; arrayscaler1<ArraySize; arrayscaler1++)
							{
							//	char GG[200];
							//	sprintf(GG, "arrayscaler1 %d\0", arrayscaler1);
							//	MessageBox(0,GG,0,0);

								ArraySS[arrayscaler1] = g_CleanSS[arrayscaler1];
							}

						//	memcpy(ArraySS, g_CleanSS, ArraySize);
						//	memmove(ArraySS, g_CleanSS, ArraySize);

						//	MessageBox(0,"RP: OK\0",0,0);

							//
						}
						
						else if(!CVARS.memess && !g_CleanSS)
						{
							message_hook = 101;
							
							// sin búffer, estopeamos
						//	CallGate_glReadPixels(x,y,width,height,format,type,data);

						//	MessageBox(0,"RP: NO OK\0",0,0);

						}

						else if(CVARS.memess && g_MemeSS)
						{
							message_hook = 2;

						//	MessageBox(0,"RP: memeOK\0",0,0);

							//

							for(arrayscaler2=0; arrayscaler2<ArraySize; arrayscaler2++) 
							{
							//	char GG[200];
							//	sprintf(GG, "arrayscaler2 %d\0", arrayscaler2);
							//	MessageBox(0,GG,0,0);

								ArraySS[arrayscaler2] = g_MemeSS[arrayscaler2];
							}

						//	memcpy(ArraySS, g_MemeSS, ArraySize);
						//	memmove(ArraySS, g_MemeSS, ArraySize);


						//	MessageBox(0,"RP: memeOK\0",0,0);

							
							//
						}

						else if(CVARS.memess && !g_MemeSS)
						{
							message_hook = 202;

							// sin meme, estopeamos
						//	CallGate_glReadPixels(x,y,width,height,format,type,data);

						//	MessageBox(0,"RP: NO memeOK\0",0,0);
						}

						else
						{
							message_hook = 3;

							// blackss
							// o stopea. no tiene búffer
						//	CallGate_glReadPixels(x,y,width,height,format,type,data);
						}
					}
					else // antiss no operativo por decisión del usuario
					{
						message_hook = 4;
						CallGate_glReadPixels_5(x,y,width,height,format,type,data);
					}
				}
				else // antiss no iniciado
				{
					message_hook = 5;
					CallGate_glReadPixels_5(x,y,width,height,format,type,data);
				}
			}
			else // antiss no instalado
			{
				message_hook = 6;
				CallGate_glReadPixels_5(x,y,width,height,format,type,data);
			}
		}
		else // hack desactivado
		{
			message_hook = 7;
			CallGate_glReadPixels_5(x,y,width,height,format,type,data);
		}
	}
	else
	{

	//	MessageBox(0,"RP: sin data 1\0",0,0);

		// sin data..
		message_hook = 8;

		// TODO
		// asignar un búffer de imagen negra por lo menos para este caso
		// así no stopea
		CallGate_glReadPixels_5(x,y,width,height,format,type,NULL);

	//	MessageBox(0,"RP: sin data 2\0",0,0);


		// img común, necesitamos un búffer con una imagen negra precargada
	/*	unsigned int nSize = w*h*3;
		char* dataBuffer = (char*)malloc(nSize*sizeof(unsigned char));
		if (!dataBuffer);
		else
		{
			CallGate_glReadPixels_5(x,y,width,height,format,type,dataBuffer);
			free(dataBuffer);
		}*/
	}

//	CallGate_glReadPixels(x,y,width,height,format,type,data);
//	glReadPixels(x,y,width,height,format,type,data);

}

//-------------------------------------------------------------------//



























