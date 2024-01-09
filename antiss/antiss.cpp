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

bool bAntiSSInstalledOK = false;

//-------------------------------------------------------------------//

bool bAntiSSStarted = false;

GLubyte* g_CleanSS = 0;// guarda el ss en un buffer !!!!!!!!!!!!!!!!!!!!! para luego ser manda2 al inj

unsigned char* g_MemeSS = 0;//GLubyte*

//-------------------------------------------------------------------//

StopTimer screentime;

unsigned int frames_ss = 0;

bool bAntissOrder = false;

int message_hook = 0;

//-------------------------------------------------------------------//

bool bRedrawMark = 0;

//-------------------------------------------------------------------//

// Esta es mi función privada que saca ss (DEBERÍA AJUSTARSE EN H y W a lo mismo que usa el sxei por su lado, 
// se supone que es la ventana del cs del client)
int TakeScreenShot(unsigned int h, unsigned int w)
{

	CallGate_glPixelStorei_5(GL_PACK_ALIGNMENT,1);
//	glPixelStorei(GL_PACK_ALIGNMENT,1);

	//-----------------------------------------------------

	// Reset..
	static bool onlyonetime=false;
	if(!onlyonetime)
	{
	//	onlyonetime=true;

		//

		if(g_CleanSS) delete []g_CleanSS;

		unsigned int nSize = w * h * 3;

		g_CleanSS = new GLubyte [nSize];
	}

	if (g_CleanSS == NULL) 
	{
		message_hook = 9;
		return -1;
	}

	//-----------------------------------------------------
	// tiene que ser una glReadPixels que se saltea el HWBP que tiene la original!!!!!!!!!!!!!!!!
	// por eso usamos un callgate

	CallGate_glReadPixels_5(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, g_CleanSS);
	//glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, g_CleanSS);

	//////////////////////////////////////////////////////////////////////////////

	if(g_CleanSS)
	{

//	static unsigned int filenumber = 0;
//	CreateTGA("takess_latest\0", filenumber++, nSize, w, h, g_CleanSS);

	}
	else
	{
		message_hook = 10;
		return -2;
	}

	//////////////////////////////////////////////////////////////////////////////

	return 0;
}

//-------------------------------------------------------------------//

void TakeSS(unsigned int h, unsigned int w)// 5th vp
{
	if(bAntissOrder)
	{
		bAntissOrder = false;
	//	if(InitScreenData)
		if(g_Screen_Updated)
		{
			int iRes = TakeScreenShot(h, w);// ESTA ES LA QUE RESETEA EL CLEAN SS BUFF

			if(iRes<0)
			{
				//char AAA[200]="\0";
				//sprintf(AAA, /*txt NO SS! (error %d)\0*/XorStr<0x07,23,0x44A102FC>("\x73\x70\x7D\x2A\x45\x43\x2D\x5D\x5C\x31\x31\x3A\x76\x66\x67\x79\x65\x38\x3C\x7E\x32\x1C"+0x44A102FC).s
				//	, iRes);
				//cmd.exec(AAA);

//				Con_Echo(/*&w [ANTISS] NO SS! (error %d)\0*/XorStr<0xAE,31,0x29B00194>("\x88\xD8\x90\xEA\xF3\xFD\xE0\xFC\xE5\xE4\xE5\x99\xF4\xF4\x9C\xEE\xED\x9E\xE0\xE9\xA7\xB1\xB6\xAA\xB4\xE7\xED\xAD\xE3\xCB"+0x29B00194).s, iRes);

			}
			else
			{
			}
		}
	}
}

//-------------------------------------------------------------------//

void TakeTestSS()// No se usa. Se usan comandos para tomar ss de muestra..
{
	/*	
	if(cvar.testss)
	{
		static bool pressed = false;
		static bool previousstate = false;
	//	if(GetAsyncKeyState(VK_END)>0)
		if(GetAsyncKeyState(VK_END) && !previousstate)
		{
			pressed=true;
			previousstate = true;

		//	if(InitScreenData)
			{
				TakeScreenShotTest(h, w);
			}
		}
		else if(!GetAsyncKeyState(VK_END) && previousstate)
		{
			pressed=false;
			previousstate = false;
		}
		else
		{
			pressed=false;
		}
	}*/
}

//-------------------------------------------------------------------//

void DrawResults()
{

	switch(message_hook)
	{
	case 1:
	{
	//	cmd.exec("txt [ANTISS] admin has taken a SS and he recieved a clean image :)\0");
//		Con_Echo(/*&w [ANTISS] admin has taken a SS and he recieved a clean image :)\0*/XorStr<0xC7,67,0x9EFF05BA>("\xE1\xBF\xE9\x91\x8A\x82\x99\x87\x9C\x83\x8C\xF2\xB2\xB0\xB8\xBF\xB9\xF8\xB1\xBB\xA8\xFC\xA9\xBF\xB4\x85\x8F\xC2\x82\xC4\xB6\xB5\xC7\x89\x87\x8E\xCB\x84\x88\xCE\x9D\x95\x92\x9B\x96\x82\x90\x92\xD7\x99\xD9\x99\x97\x99\x9C\x90\xDF\x69\x6C\x63\x64\x61\x25\x3C\x2E\x08"+0x9EFF05BA).s);
		message_hook=0;

	}

	break;
	case 101:
	{
//		Con_Echo(/*&w [ANTISS] admin has taken a SS but clean SS failed :/\0*/XorStr<0x65,57,0xB64941A9>("\x43\x11\x47\x33\x28\x24\x3F\x25\x3E\x3D\x32\x50\x10\x16\x1E\x1D\x1B\x56\x1F\x19\x0A\x5A\x0F\x1D\x16\x1B\x11\xA0\xE0\xA2\xD0\xD7\xA5\xE4\xF2\xFC\xA9\xE9\xE7\xE9\xEC\xE0\xAF\xC3\xC2\xB2\xF5\xF5\xFC\xFA\xF2\xFC\xB9\xA0\xB4\x9C"+0xB64941A9).s);
		message_hook=0;

	}

	break;
	case 2:
	{
//		Con_Echo(/*&w [ANTISS] admin has taken a SS but he recieved a black screen or a porn picture :)\0*/XorStr<0x40,86,0x405F1EF2>("\x66\x36\x62\x18\x05\x0B\x12\x0E\x1B\x1A\x17\x6B\x2D\x29\x23\x26\x3E\x71\x3A\x32\x27\x75\x22\x36\x33\x3C\x34\x7B\x3D\x7D\x0D\x0C\x40\x03\x17\x17\x44\x0D\x03\x47\x1A\x0C\x09\x02\x09\x1B\x0B\x0B\x50\x10\x52\x11\x18\x14\x15\x1C\x58\x0A\x19\x09\x19\x18\x10\x5F\xEF\xF3\xA2\xE2\xA4\xF5\xE9\xF5\xE6\xA9\xFA\xE2\xEF\xF9\xFB\xFD\xF5\xB1\xA8\xBA\x94"+0x405F1EF2).s);
		message_hook=0;


	}

	break;
	case 202:
	{
//		Con_Echo(/*&w [ANTISS] admin has taken a SS but meme SS failed :/\0*/XorStr<0x7B,56,0x9E901377>("\x5D\x0B\x5D\x25\x3E\xCE\xD5\xCB\xD0\xD7\xD8\xA6\xE6\xEC\xE4\xE3\xE5\xAC\xE5\xEF\xFC\xB0\xE5\xF3\xF8\xF1\xFB\xB6\xF6\xB8\xCA\xC9\xBB\xFE\xE8\xEA\xBF\xCD\xC4\xCF\xC6\x84\xF6\xF5\x87\xCE\xC8\xC3\xC7\xC9\xC9\x8E\x95\x9F\xB1"+0x9E901377).s);
		message_hook=0;


	}

	break;
	case 3:
	{
//		Con_Echo(/*&r [ANTISS] no hack buffer!\0*/XorStr<0x67,29,0x0512CC32>("\x41\x1A\x49\x31\x2A\x22\x39\x27\x3C\x23\x2C\x52\x1D\x1B\x55\x1E\x16\x1B\x12\x5A\x19\x09\x1B\x18\x1A\xF2\xA0\x82"+0x0512CC32).s);
		message_hook=0;

	}

	break;
	case 4:
	{
//		Con_Echo(/*&w [ANTISS] antiss is not operational!\0*/XorStr<0x38,40,0x3CE43B9B>("\x1E\x4E\x1A\x60\x7D\x73\x6A\x76\x13\x12\x1F\x63\x25\x2B\x32\x2E\x3B\x3A\x6A\x22\x3F\x6D\x20\x20\x24\x71\x3D\x23\x31\x27\x37\x23\x31\x36\x34\x3A\x30\x7C\x5E"+0x3CE43B9B).s);
		message_hook=0;


	}

	break;
	case 5:
	{
//		Con_Echo(/*&w [ANTISS] antiss is not initialized!\0*/XorStr<0x00,40,0x7D6A5D14>("\x26\x76\x22\x58\x45\x4B\x52\x4E\x5B\x5A\x57\x2B\x6D\x63\x7A\x66\x63\x62\x32\x7A\x67\x35\x78\x78\x6C\x39\x73\x75\x75\x69\x77\x7E\x4C\x48\x58\x46\x40\x04\x26"+0x7D6A5D14).s);
		message_hook=0;


	}

	break;
	case 6:
	{
//		Con_Echo(/*&w [ANTISS] antiss was not installed!\0*/XorStr<0xAE,39,0xA125D209>("\x88\xD8\x90\xEA\xF3\xFD\xE0\xFC\xE5\xE4\xE5\x99\xDB\xD5\xC8\xD4\xCD\xCC\xE0\xB6\xA3\xB0\xE4\xAB\xA9\xB3\xE8\xA0\xA4\xB8\xB8\xAC\xA2\xA3\xB5\xB5\xF3\xD3"+0xA125D209).s);
		message_hook=0;

	}

	break;
	case 7:
	{
//		Con_Echo(/*&w [ANTISS] hack is not active!\0*/XorStr<0x7E,33,0xE6120260>("\x58\x08\xA0\xDA\xC3\xCD\xD0\xCC\xD5\xD4\xD5\xA9\xE2\xEA\xEF\xE6\xAE\xE6\xE3\xB1\xFC\xFC\xE0\xB5\xF7\xF4\xEC\xF0\xEC\xFE\xBD\x9D"+0xE6120260).s);
		message_hook=0;


	}

	break;
	case 8:
	{
//		Con_Echo(/*&r [ANTISS] no data buffer!\0*/XorStr<0x51,29,0x425B2787>("\x77\x20\x73\x0F\x14\x18\x03\x11\x0A\x09\x06\x7C\x33\x31\x7F\x04\x00\x16\x02\x44\x07\x13\x01\x0E\x0C\x18\x4A\x6C"+0x425B2787).s);
		message_hook=0;


	}

	break;

	////////////////////////////////////////////////////////////////////////////////

	case 9:
	{
//		Con_Echo(/*&w [ANTISS] clean ss buffer fucked 1!\0*/XorStr<0xAD,39,0xA581C7FF>("\x8B\xD9\x8F\xEB\xF0\xFC\xE7\xFD\xE6\xE5\xEA\x98\xDA\xD6\xDE\xDD\xD3\x9E\xCC\xB3\xE1\xA0\xB6\xA2\xA3\xA3\xB5\xE8\xAF\xBF\xA8\xA7\xA8\xAA\xEF\xE1\xF0\xD2"+0xA581C7FF).s);
		message_hook=0;


	}

	break;
	case 10:
	{
//		Con_Echo(/*&w [ANTISS] clean ss buffer fucked 2!\0*/XorStr<0x32,39,0x10925322>("\x14\x44\x14\x6E\x77\x79\x6C\x70\x69\x68\x61\x1D\x5D\x53\x25\x20\x2C\x63\x37\x36\x66\x25\x3D\x2F\x2C\x2E\x3E\x6D\x28\x3A\x33\x3A\x37\x37\x74\x67\x77\x57"+0x10925322).s);
		message_hook=0;


	}

	break;

	////////////////////////////////////////////////////////////////////////////////

	case 11:
	{
//		Con_Echo(/*&w [ANTISS] width is higher!\0*/XorStr<0x25,30,0xD31F7500>("\x03\x51\x07\x73\x68\x64\x7F\x65\x7E\x7D\x72\x10\x46\x5B\x57\x40\x5D\x16\x5E\x4B\x19\x52\x52\x5B\x55\x5B\x4D\x61\x41"+0xD31F7500).s);
		message_hook=0;


	}

	break;
	case 12:
	{
//		Con_Echo(/*&w [ANTISS] width is lower!\0*/XorStr<0x3C,29,0xEB22F7EF>("\x1A\x4A\x1E\x64\x01\x0F\x16\x0A\x17\x16\x1B\x67\x3F\x20\x2E\x3F\x24\x6D\x27\x3C\x70\x3D\x3D\x24\x31\x27\x77\x57"+0xEB22F7EF).s);
		message_hook=0;


	}

	break;
	case 13:
	{
//		Con_Echo(/*&w [ANTISS] height is higher!\0*/XorStr<0x6D,31,0x6068C98D>("\x4B\x19\x4F\x2B\x30\x3C\x27\x3D\x26\x25\x2A\x58\x11\x1F\x12\x1B\x15\x0A\x5F\xE9\xF2\xA2\xEB\xED\xE2\xEE\xE2\xFA\xA8\x8A"+0x6068C98D).s);
		message_hook=0;


	}

	break;
	case 14:
	{
//		Con_Echo(/*&w [ANTISS] height is lower!\0*/XorStr<0x19,30,0x939EE679>("\x3F\x6D\x3B\x47\x5C\x50\x4B\x69\x72\x71\x7E\x04\x4D\x43\x4E\x4F\x41\x5E\x0B\x45\x5E\x0E\x43\x5F\x46\x57\x41\x15\x35"+0x939EE679).s);
		message_hook=0;


	}

	break;
	case 15:
	{
//		Con_Echo(/*&w [ANTISS] x > 0!\0*/XorStr<0xA2,20,0x1F91508B>("\x84\xD4\x84\xFE\xE7\xE9\xFC\xE0\xF9\xF8\xF1\x8D\xD6\x8F\x8E\x91\x82\x92\xB4"+0x1F91508B).s);
		message_hook=0;


	}

	break;
	case 16:
	{
//		Con_Echo(/*&w [ANTISS] y > 0!\0*/XorStr<0x63,20,0x965101B3>("\x45\x13\x45\x3D\x26\x26\x3D\x23\x38\x3F\x30\x4E\x16\x50\x4F\x52\x43\x55\x75"+0x965101B3).s);
		message_hook=0;


	}

	break;
	case 17:
	{
//		Con_Echo(/*&w [ANTISS] calscreen not initialized atm!\0*/XorStr<0x44,44,0xD311FD77>("\x62\x32\x66\x1C\x09\x07\x1E\x02\x1F\x1E\x13\x6F\x33\x30\x3E\x20\x37\x27\x33\x32\x36\x79\x34\x34\x28\x7D\x37\x31\x09\x15\x0B\x02\x08\x0C\x1C\x02\x0C\x49\x0B\x1F\x01\x4C\x6E"+0xD311FD77).s);
		message_hook=0;

	}

	default:break;
	}
}

//-------------------------------------------------------------------//

void DrawAntiSSInfo()
{


	if(bAntiSSInstalledOK && bAntiSSStarted)
	{
	//	if(cvar.antiss)
		{
		//	if(cvar.draw)
			{
				DrawResults();
			}
		}
	}


}

//-------------------------------------------------------------------//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// COMMANDS
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------//

void func_testss()// Crea un TGA en la carpeta del hl
{
	if(bAntiSSInstalledOK && bAntiSSStarted)
	{
		if(CVARS.antiss)
		{
			if(g_Screen_Updated)
		//	if(InitScreenData)
			{
				// Esto emula a cómo saca SS el Injected :) (sale sin tono, normal)
				int iRes = TakeScreenShotTest(g_Screen.iHeight, g_Screen.iWidth);
				if(iRes<0)
				{
				//	char AAA[200]="\0";
				//	sprintf(AAA, /*txt Take SS experimented an error %d !\0*/XorStr<0xF4,40,0x1096F05C>("\x80\x8D\x82\xD7\xAC\x98\x91\x9E\xDC\xAE\xAD\xDF\x65\x79\x72\x66\x76\x6C\x6B\x62\x66\x7D\x6F\x6F\x2C\x6C\x60\x2F\x75\x63\x60\x7C\x66\x35\x33\x73\x38\x38\x1A"+0x1096F05C).s
				//	, iRes);
				//	cmd.exec(AAA);

//					Con_Echo(/*&w [ANTISS] Take SS experimented an error %d !\0*/XorStr<0x59,48,0xBCDC558E>("\x7F\x2D\x7B\x07\x1C\x10\x0B\x29\x32\x31\x3E\x44\x31\x07\x0C\x0D\x49\x39\x38\x4C\x08\x16\x1F\x15\x03\x1B\x1E\x11\x1B\x02\x12\x1C\x59\x1B\x15\x5C\x18\x0C\x0D\xEF\xF3\xA2\xA6\xE0\xA5\xA7\x87"+0xBCDC558E).s
//						, iRes);
				}
				else
				{

				}
			}
		}
		else
		{
//			Con_Echo(/*&w [ANTISS] ANTISS not operational!\0*/XorStr<0x41,37,0xE8A5D6F5>("\x67\x35\x63\x1F\x04\x08\x13\x01\x1A\x19\x16\x6C\x0C\x00\x1B\x19\x02\x01\x73\x3A\x3A\x22\x77\x37\x29\x3F\x29\x3D\x29\x37\x30\x0E\x00\x0E\x42\x64"+0xE8A5D6F5).s);
		}
	}
}

//-------------------------------------------------------------------//

void func_seess()// Crea el archivo seess1.tga en la unidad C
{
	if(bAntiSSInstalledOK && bAntiSSStarted)
	{
		if(CVARS.antiss)
		{
			if(g_Screen_Updated)
		//	if(InitScreenData)
			{
				if(CVARS.memess)
				{
					if(g_MemeSS)
					{
						// esta func está guardando/sacando ss con tono azul !!!!!!!!!!!!!!!!!!!
						int iRes = SaveScreenShot(g_Screen.iWidth, g_Screen.iHeight, g_MemeSS);
						if(iRes<0)
						{
							//char AAA[200]="\0";
							//sprintf(AAA, /*txt See SS experimented an error %d !\0*/XorStr<0x6B,39,0x29FEFFA3>("\x1F\x14\x19\x4E\x3C\x15\x14\x52\x20\x27\x55\x13\x0F\x08\x1C\x08\x12\x11\x18\x10\x0B\xE5\xE5\xA2\xE2\xEA\xA5\xE3\xF5\xFA\xE6\xF8\xAB\xA9\xE9\xAE\xAE\x90"+0x29FEFFA3).s
							//	, iRes);
							//cmd.exec(AAA);
//							Con_Echo(/*&w [ANTISS] See SS experimented an error %d !\0*/XorStr<0xD9,47,0xF3111219>("\xFF\xAD\xFB\x87\x9C\x90\x8B\xA9\xB2\xB1\xBE\xC4\xB6\x83\x82\xC8\xBA\xB9\xCB\x89\x95\x9E\x8A\x82\x98\x9F\x96\x9A\x81\x93\x93\xD8\x98\x94\xDB\x99\x8F\x8C\x90\x72\x21\x27\x67\x24\x24\x06"+0xF3111219).s
//								, iRes);

						}

						else
						{
						//	cmd.exec(/*txt See SS with meme SS = FINE!\0*/XorStr<0x15,33,0xA9DF2064>("\x61\x6E\x63\x38\x4A\x7F\x7E\x3C\x4E\x4D\x3F\x57\x48\x56\x4B\x04\x48\x43\x4A\x4D\x09\x79\x78\x0C\x10\x0E\x69\x79\x7F\x77\x12\x34"+0xA9DF2064).s);
						
//							Con_Echo(/*&w [ANTISS] See SS with meme SS = FINE!\0*/XorStr<0xAD,41,0xA50C3AAC>("\x8B\xD9\x8F\xEB\xF0\xFC\xE7\xFD\xE6\xE5\xEA\x98\xEA\xDF\xDE\x9C\xEE\xED\x9F\xB7\xA8\xB6\xAB\xE4\xA8\xA3\xAA\xAD\xE9\x99\x98\xEC\xF0\xEE\x89\x99\x9F\x97\xF2\xD4"+0xA50C3AAC).s);
						}
					}
					else
					{
					//	cmd.exec(/*txt See SS with meme SS = fucked!\0*/XorStr<0xF1,35,0x71549898>("\x85\x8A\x87\xD4\xA6\x93\x92\xD8\xAA\xA9\xDB\x8B\x94\x8A\x97\x20\x6C\x67\x6E\x61\x25\x55\x54\x28\x34\x2A\x6D\x79\x6E\x65\x6A\x74\x30\x12"+0x71549898).s);
					

//						Con_Echo(/*&w [ANTISS] See SS with meme SS = fucked!\0*/XorStr<0x89,43,0xA90C5690>("\xAF\xFD\xAB\xD7\xCC\xC0\xDB\xD9\xC2\xC1\xCE\xB4\xC6\xF3\xF2\xB8\xCA\xC9\xBB\xEB\xF4\xEA\xF7\x80\xCC\xC7\xCE\xC1\x85\xF5\xF4\x88\x94\x8A\xCD\xD9\xCE\xC5\xCA\xD4\x90\xB2"+0xA90C5690).s);
					}
				}
				else
				{
					///////////
					if(g_CleanSS)// se resetea en alguna parte
					///////////
					{
						// esta func está guardando/sacando ss con tono azul !!!!!!!!!!!!!!!!!!!
						int iRes = SaveScreenShot(g_Screen.iWidth, g_Screen.iHeight, g_CleanSS);
						if(iRes<0)
						{
							//char AAA[200]="\0";
							//sprintf(AAA, /*txt See SS experimented an error %d !\0*/XorStr<0xB5,39,0xDFDC73BB>("\xC1\xCE\xC3\x98\xEA\xDF\xDE\x9C\xEE\xED\x9F\xA5\xB9\xB2\xA6\xB6\xAC\xAB\xA2\xA6\xBD\xAF\xAF\xEC\xAC\xA0\xEF\xB5\xA3\xA0\xBC\xA6\xF5\xF3\xB3\xF8\xF8\xDA"+0xDFDC73BB).s
							//	, iRes);
							//cmd.exec(AAA);

//							Con_Echo(/*&w [ANTISS] See SS experimented an error %d !\0*/XorStr<0x51,47,0x3BFC8457>("\x77\x25\x73\x0F\x14\x18\x03\x11\x0A\x09\x06\x7C\x0E\x3B\x3A\x40\x32\x31\x43\x01\x1D\x16\x02\x1A\x00\x07\x0E\x02\x19\x0B\x0B\x50\x10\x1C\x53\x11\x07\x04\x18\x0A\x59\x5F\x1F\x5C\x5C\x7E"+0x3BFC8457).s
//								, iRes);

						}
						else
						{
						//	cmd.exec(/*txt See SS with clean SS = FINE!\0*/XorStr<0xCB,34,0x2226FC0C>("\xBF\xB4\xB9\xEE\x9C\xB5\xB4\xF2\x80\x87\xF5\xA1\xBE\xAC\xB1\xFA\xB8\xB0\xB8\xBF\xB1\xC0\xB2\xB1\xC3\xD9\xC5\xA0\xAE\xA6\xAC\xCB\xEB"+0x2226FC0C).s);
						
//							Con_Echo(/*&w [ANTISS] See SS with clean SS = FINE!\0*/XorStr<0xD5,42,0x43324560>("\xF3\xA1\xF7\x83\x98\x94\x8F\x95\x8E\x8D\x82\xC0\xB2\x87\x86\xC4\xB6\xB5\xC7\x9F\x80\x9E\x83\xCC\x8E\x82\x8A\x91\x9F\xD2\xA0\xA7\xD5\xCB\xD7\xBE\xB0\xB4\xBE\xDD\xFD"+0x43324560).s);

						}
					}
					else
					{
					//	cmd.exec(/*txt See SS with clean SS = fucked!\0*/XorStr<0xCD,36,0x560C90CB>("\xB9\xB6\xBB\xF0\x82\xB7\xB6\xF4\x86\x85\xF7\xAF\xB0\xAE\xB3\xFC\xBE\xB2\xBA\x81\x8F\xC2\xB0\xB7\xC5\xDB\xC7\x8E\x9C\x89\x80\x89\x89\xCF\xEF"+0x560C90CB).s);
					
//						Con_Echo(/*&w [ANTISS] See SS with clean SS = fucked!\0*/XorStr<0xFA,44,0xA47EBB1F>("\xDC\x8C\xDC\xA6\xBF\xB1\x54\x48\x51\x50\x59\x25\x55\x62\x6D\x29\x59\x58\x2C\x7A\x67\x7B\x78\x31\x71\x7F\x71\x74\x78\x37\x4B\x4A\x3A\x26\x3C\x7B\x6B\x7C\x4B\x44\x46\x02\x24"+0xA47EBB1F).s);
					
					}
				}
			}
		}
		else
		{
//			Con_Echo(/*&w [ANTISS] ANTISS not operational!\0*/XorStr<0x41,37,0xE8A5D6F5>("\x67\x35\x63\x1F\x04\x08\x13\x01\x1A\x19\x16\x6C\x0C\x00\x1B\x19\x02\x01\x73\x3A\x3A\x22\x77\x37\x29\x3F\x29\x3D\x29\x37\x30\x0E\x00\x0E\x42\x64"+0xE8A5D6F5).s);
		}
	}
}

//-------------------------------------------------------------------//

void func_memess()
{
	if(bAntiSSInstalledOK && bAntiSSStarted)
	{
		if(CVARS.antiss)
		{
			CVARS.memess = !CVARS.memess;

			if(CVARS.memess)
			{
			//	cmd.exec(/*txt Now the SS will be a meme image!\0*/XorStr<0x74,38,0x5FA94A8D>("\x00\x0D\x02\x57\x36\x16\x0D\x5B\x08\x15\x1B\x5F\xD3\xD2\xA2\xF4\xED\xE9\xEA\xA7\xEA\xEC\xAA\xEA\xAC\xE0\xEB\xE2\xF5\xB1\xFB\xFE\xF5\xF2\xF3\xB6\x98"+0x5FA94A8D).s);
			
//				Con_Echo(/*&w [ANTISS] Now the SS will be a meme image!\0*/XorStr<0x55,46,0x855CC207>("\x73\x21\x77\x03\x18\x14\x0F\x15\x0E\x0D\x02\x40\x2F\x0D\x14\x44\x11\x0E\x02\x48\x3A\x39\x4B\x1B\x04\x02\x03\x50\x13\x17\x53\x15\x55\x1B\x12\x15\x1C\x5A\x12\x11\x1C\x19\x1A\xA1\x81"+0x855CC207).s);
		
			}
			else
			{
			//	cmd.exec(/*txt Now the SS will be a clean image!\0*/XorStr<0x6E,39,0x0A726A81>("\x1A\x17\x04\x51\x3C\x1C\x03\x55\x02\x1F\x1D\x59\x29\x28\x5C\x0A\x17\x13\xEC\xA1\xE0\xE6\xA4\xE4\xA6\xE4\xE4\xEC\xEB\xE5\xAC\xE4\xE3\xEE\xF7\xF4\xB3\x93"+0x0A726A81).s);
	
//				Con_Echo(/*&w [ANTISS] Now the SS will be a clean image!\0*/XorStr<0x5E,47,0x864016EC>("\x78\x28\x40\x3A\x23\x2D\x30\x2C\x35\x34\x35\x49\x24\x04\x1B\x4D\x1A\x07\x15\x51\x21\x20\x54\x02\x1F\x1B\x14\x59\x18\x1E\x5C\x1C\x5E\x1C\xEC\xE4\xE3\xED\xA4\xEC\xEB\xE6\xEF\xEC\xAB\x8B"+0x864016EC).s);
			}
		}
		else
		{
//			Con_Echo(/*&w [ANTISS] ANTISS not operational!\0*/XorStr<0x41,37,0xE8A5D6F5>("\x67\x35\x63\x1F\x04\x08\x13\x01\x1A\x19\x16\x6C\x0C\x00\x1B\x19\x02\x01\x73\x3A\x3A\x22\x77\x37\x29\x3F\x29\x3D\x29\x37\x30\x0E\x00\x0E\x42\x64"+0xE8A5D6F5).s);	
		}
	}
}

//-------------------------------------------------------------------//

void func_antissactive()
{
	if(bAntiSSInstalledOK && bAntiSSStarted)
	{
		CVARS.antiss = !CVARS.antiss;
		if(CVARS.antiss)
		{
		//	cmd.exec(/*txt ANTISS operative!\0*/XorStr<0x63,23,0xD420EC3A>("\x17\x1C\x11\x46\x26\x26\x3D\x23\x38\x3F\x4D\x01\x1F\x15\x03\x13\x07\x1D\x03\x13\x56\x78"+0xD420EC3A).s);
		
//			Con_Echo(/*&w [ANTISS] ANTISS operative!\0*/XorStr<0x6B,31,0x55D4BFB0>("\x4D\x1B\x4D\x35\x2E\x3E\x25\x3B\x20\x27\x28\x56\x36\x36\x2D\x33\x28\x2F\x5D\x11\x0F\xE5\xF3\xE3\xF7\xED\xF3\xE3\xA6\x88"+0x55D4BFB0).s);
		}
		else
		{
//			Con_Echo(/*&w [ANTISS] ANTISS out of service!\0*/XorStr<0x08,36,0xAEF07E65>("\x2E\x7E\x2A\x50\x4D\x43\x5A\x46\x43\x42\x4F\x33\x55\x5B\x42\x5E\x4B\x4A\x3A\x74\x69\x69\x3E\x70\x46\x01\x51\x46\x56\x53\x4F\x44\x4D\x08\x2A"+0xAEF07E65).s);
		}
	}
}

//-------------------------------------------------------------------//

void func_antissenable()
{
	if(bAntiSSInstalledOK)
	{
		if(!bAntiSSStarted)
		{

//			Con_Echo(/*&w [ANTISS] ANTISS INITTED!\0*/XorStr<0x22,29,0xBA43AC62>("\x04\x54\x04\x7E\x67\x69\x7C\x60\x79\x78\x71\x0D\x6F\x61\x64\x78\x61\x60\x14\x7C\x78\x7E\x6C\x6D\x7F\x7F\x1D\x3D"+0xBA43AC62).s);

			bAntiSSStarted = true; //ahora instala el hook derecho viejo y no activa el antiss hasta que manualmente se ejecuta este comando

			CVARS.antiss = 1;// antes se ponía a 1 junto con bAntiSSInstalledOK

		}
		else
		{
		//	cmd.exec(/*txt ANTISS ALREADY INITTED!\0*/XorStr<0x52,29,0xDDBC5FEB>("\x26\x2B\x20\x75\x17\x19\x0C\x10\x09\x08\x7C\x1C\x12\x0D\x25\x20\x26\x3A\x44\x2C\x28\x2E\x3C\x3D\x2F\x2F\x4D\x6D"+0xDDBC5FEB).s);
		
//			Con_Echo(/*&w [ANTISS] ANTISS ALREADY INITTED!\0*/XorStr<0xC1,37,0x17A95C1D>("\xE7\xB5\xE3\x9F\x84\x88\x93\x81\x9A\x99\x96\xEC\x8C\x80\x9B\x99\x82\x81\xF3\x95\x99\x84\x92\x99\x9D\x83\xFB\x95\x93\x97\x8B\xB4\xA4\xA6\xC2\xE4"+0x17A95C1D).s);

		}
	}
}

//-------------------------------------------------------------------//

void func_launchantiss()
{
	func_antissenable();
}

//-------------------------------------------------------------------//

void register_antiss_commands()
{
}

//-------------------------------------------------------------------//

void register_antiss_engine_commands()
{

	//
	// CRASH!!!!!!!!!!!!!!!!!!!!!!!!!!! si le aplicás XORSTR
	
	/*
	gEngfuncs.pfnAddCommand("x_steamwall_antissactive\0", func_antissactive);// activa / desactiva
//	gEngfuncs.pfnAddCommand("x_steamwall_antissenable\0", func_antissenable);
	gEngfuncs.pfnAddCommand("x_steamwall_launchantiss\0", func_launchantiss);
	gEngfuncs.pfnAddCommand("x_steamwall_activate_memess\0", func_memess);*/


	pEngfuncs->pfnAddCommand("x_steamwall_testss\0" ,func_testss);
	pEngfuncs->pfnAddCommand("x_steamwall_seess\0" ,func_seess);


}

//-------------------------------------------------------------------//





