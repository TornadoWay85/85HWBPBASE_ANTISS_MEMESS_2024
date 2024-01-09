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

#define GL_BGR                            0x80E0
#define GL_BGRA                           0x80E1

t_glReadPixels pEAT_glReadPixels = 0;

//-------------------------------------------------------------------//

void InitSS()
{
	if(pGetProcAddress && pGetModuleHandleA)
	{

	pEAT_glReadPixels = (t_glReadPixels)
		pGetProcAddress(

		pGetModuleHandleA(/*opengl32.dll\0*/XorStr<0x89,14,0x8C75A28B>("\xE6\xFA\xEE\xE2\xEA\xE2\xBC\xA2\xBF\xF6\xFF\xF8\x95"+0x8C75A28B).s)

		, /*glReadPixels\0*/XorStr<0xAA,14,0xF630A89A>("\xCD\xC7\xFE\xC8\xCF\xCB\xE0\xD8\xCA\xD6\xD8\xC6\xB6"+0xF630A89A).s);
	}
}

//-------------------------------------------------------------------//

void LogSS()
{
//	extern t_glReadPixels pEAT_glReadPixels;
	DrawHudString(60, 100, 255, 255, 255, "pEAT_glReadPixels 0x%X (0x%X)\0", pEAT_glReadPixels, glReadPixels);

	DrawHudString(60, 120, 255, 255, 255, "g_CleanSS 0x%X\0", g_CleanSS);
	DrawHudString(60, 140, 255, 255, 255, "g_MemeSS 0x%X\0", g_MemeSS);

	unsigned char* GetData();
	
	DrawHudString(60, 160, 255, 255, 255, "GetData() 0x%X\0", GetData());

	DrawHudString(60, 180, 255, 255, 255, "message_hook %d\0", message_hook);

	DrawHudString(60, 200, 255, 255, 255, "iWidth %d | iHeight %d\0", g_Screen.iWidth, g_Screen.iHeight);

	DrawHudString(60, 220, 255, 255, 255, "ss_cleanframes %d (las frames que dura la toma de ss)\0", CVARS.ss_cleanframes);

	DrawHudString(60, 240, 255, 255, 255, "seess %d\0", CVARS.seess);

	DrawHudString(60, 260, 255, 255, 255, "testss %d\0", CVARS.testss);

	DrawHudString(60, 280, 255, 255, 255, "g_Screen_Updated %d (x%f y%f)\0",g_Screen_Updated , g_displayCenterX, g_displayCenterY);

}

//-------------------------------------------------------------------//

int CreateTGA(unsigned int fileid, unsigned int iSize, unsigned int h, unsigned int w, 
			  
			  GLvoid* pixels)
{
	char cFileName[500]="\0";

	sprintf(cFileName,/*%sscreenshot%d.tga\0*/XorStr<0xB2,20,0x2E3AA15E>("\x97\xC0\xC7\xD6\xC4\xD2\xDD\xD7\xC9\xD3\xD3\xC9\x9B\xDB\xEE\xB5\xA5\xA2\xC4"+0x2E3AA15E).s
		,getOgcDirFile(/*\0*/XorStr<0xA5,2,0xFFD9BEE7>("\xA5"+0xFFD9BEE7).s), fileid);

//	MessageBox(0,cFileName,"CreateTGA\0",0);
//	MessageBox(0,"CreateTGA 0\0","\0",0);

	//FILE* fScreenshot = fopen(cFileName,"rb\0");
	FILE* fScreenshot = fopen(cFileName,/*wb\0*/XorStr<0xB9,4,0xDEC7D651>("\xCE\xD8\xBB"+0xDEC7D651).s);
    if (fScreenshot == NULL)
	{
	//	fScreenshot = fopen(cFileName,"wb\0");
	//	if (fScreenshot == NULL)
		{

		//	logme1("CreateTGA = Error -11\0");
			return -11;
		}
	}

//	MessageBox(0,"CreateTGA 1\0","\0",0);

	if (!pixels)
	{
	//	logme1("CreateTGA = Error -22\0");
		fclose(fScreenshot);
		return -22;
	}

//	MessageBox(0,"CreateTGA 2\0","\0",0);

	//
	unsigned int nSizeX = w * h * 3;
	GLubyte* ss_x = new GLubyte [nSizeX];
	if (ss_x == NULL)
	{
	//	logme1("CreateTGA = Error -33\0");
		fclose(fScreenshot);
		return -33;
	}

//	MessageBox(0,"CreateTGA 3\0","\0",0);

	GLubyte* xss = (GLubyte*)pixels;
	for(unsigned int i=0; i<nSizeX; i++)
	{
		ss_x[i] = xss[i];
	}

//	MessageBox(0,"CreateTGA 4\0","\0",0);

	//
	//convert to BGR format
	if(CVARS.sstoblue)
	{
		unsigned char temp = 0;
		unsigned int j = 0;
		while (j < nSizeX)
		{
			temp      = ss_x[j];    //grab blue
			ss_x[j]   = ss_x[j+2];  //assign red to blue
			ss_x[j+2] = temp;       //assign blue to red
			j += 3;                 //skip to next blue byte
		}
	}

//	MessageBox(0,"CreateTGA 5\0","\0",0);

    unsigned char TGAheader[12]={0,0,2,0,0,0,0,0,0,0,0,0};
    unsigned char header[6] = {w%256,w/256,h%256,h/256,24,0};
    fwrite(TGAheader, sizeof(unsigned char), 12, fScreenshot);
    fwrite(header, sizeof(unsigned char), 6, fScreenshot);
    fwrite(ss_x, sizeof(GLubyte), nSizeX, fScreenshot);
    fclose(fScreenshot);
	delete [] ss_x;

//	MessageBox(0,"CreateTGA 6\0","\0",0);

//	logme1("CreateTGA = OK\0");
	return 0;
}

//-------------------------------------------------------------------//

int TakeScreenShotTest(unsigned int h, unsigned int w)// Para simular la sacada de ss del injected
{
	// para que salte por sxei, tenés que llamarla con vinculación dinámica.
	// que es como se supone que el sxei la llama.

/*	t_glPixelStorei pEAT_glPixelStorei = (t_glPixelStorei)
		GetProcAddress(pGetModuleHandleA("opengl32.dll\0"), "glPixelStorei\0");
	if(!pEAT_glPixelStorei) return;
	pEAT_glPixelStorei(GL_PACK_ALIGNMENT,1);*/

	//

//	MessageBox(0,"TakeScreenShotTest 0\0","\0",0);

	CallGate_glPixelStorei_5(GL_PACK_ALIGNMENT,1);
//	glPixelStorei(GL_PACK_ALIGNMENT,1);

//	MessageBox(0,"TakeScreenShotTest 1\0","\0",0);

	///////////////////////////////////////////////////////

	unsigned int nSize = 0;
	
	nSize = w * h * 3;

	GLubyte* pixels = new GLubyte [nSize];
   
	if (pixels == NULL)
	{

	//	logme1("TakeScreenShotTest = Error -1\0");

		return -1;
	}

	/////////////////////////////////////////////////////////////////////

	// para que salte como en el sxei, tenés que llamarla con vinculación dinámica.
	// que es como se supone que el sxei la llama.

//	MessageBox(0,"TakeScreenShotTest 2\0","\0",0);

//	t_glReadPixels 
//	pEAT_glReadPixels = (t_glReadPixels)
//		pGetProcAddress(

//		pGetModuleHandleA(/*opengl32.dll\0*/XorStr<0x89,14,0x8C75A28B>("\xE6\xFA\xEE\xE2\xEA\xE2\xBC\xA2\xBF\xF6\xFF\xF8\x95"+0x8C75A28B).s)

//		, /*glReadPixels\0*/XorStr<0xAA,14,0xF630A89A>("\xCD\xC7\xFE\xC8\xCF\xCB\xE0\xD8\xCA\xD6\xD8\xC6\xB6"+0xF630A89A).s);
	

	InitSS();


	if(!pEAT_glReadPixels)
	{
	//	MessageBox(0,"TakeScreenShotTest FUCK YOU\0","\0",0);
	//	logme1("TakeScreenShotTest = Error -2\0");

		delete [] pixels;
		return -2;
	}

//	MessageBox(0,"TakeScreenShotTest 3\0","\0",0);

	pEAT_glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, pixels);//GL_BGR

	//
//	CallGate_glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, pixels);

	//

//	glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, pixels);

	/////////////////////////////////////////////////////////////////////

//	MessageBox(0,"TakeScreenShotTest 4\0","\0",0);

	if(pixels)
	{
		static unsigned int filenumber = 0;
		int iRes = CreateTGA(filenumber++, nSize, h, w, pixels);

		if(iRes<0)
		{
		//	logme1("TakeScreenShotTest = %d\0", iRes);
			delete [] pixels;
			return iRes;
		}
	}
	else
	{
	//	logme1("TakeScreenShotTest = Error -3\0");
		return -3;
	}

//	MessageBox(0,"TakeScreenShotTest 5\0","\0",0);

	/////////////////////////////////////////////////////////////////////

//	logme1("TakeScreenShotTest = OK\0");
	delete [] pixels;
	return 0;
}

//-------------------------------------------------------------------//

// g_CleanSS = 
// g_MemeSS = ver cómo se inicializa, para resolver posibles crashes (en testbmpscaling())

int SaveScreenShot(unsigned int w, unsigned int h, 
				   
				   void* theBuf)// no toma ss internamente sino que usa un buff global que le pasamos
{
	//This prevents the images getting padded 
	// when the width multiplied by 3 is not a multiple of 4
//	glPixelStorei(GL_PACK_ALIGNMENT, 1);

//	MessageBox(0,"SaveScreenShot 0\0","\0",0);

	unsigned int nSize = w*h*3;
    // First let's create our buffer, 3 channels per Pixel
    char* dataBuffer = (char*)malloc(nSize*sizeof(unsigned char));
    if (!dataBuffer)
	{
	//	logme1("SaveScreenShot = ERROR -1\0");
		return -1;
	}

	if(!theBuf)
	{
	//	logme1("SaveScreenShot = ERROR -2\0");
		free(dataBuffer);
		return -2;
	}

//	char GG111[200];
//	sprintf(GG111, "SaveScreenShot: nSize %d\0", nSize);
//	MessageBox(0,GG111,0,0);

//	MessageBox(0,"SaveScreenShot 1\0","\0",0);

	// Let's fetch them from the backbuffer
	// We request the pixels in GL_BGR format, thanks to Berzeger for the tip
	/*
	glReadPixels((GLint)0, (GLint)0,(GLint)w, (GLint)h,GL_BGR, GL_UNSIGNED_BYTE, dataBuffer);*/
	

/*	char GG1112[200];
	sprintf(GG1112, "SaveScreenShot: theBuf 0x%X\0", theBuf);
	MessageBox(0,GG1112,0,0);*/

	memcpy(dataBuffer,theBuf,nSize*sizeof(unsigned char));

/*	unsigned char* theBufXXX = (unsigned char*)theBuf;

	unsigned int arrayscalerX = 0;
	for(arrayscalerX=0; arrayscalerX<nSize; arrayscalerX++)
	{
	//	dataBuffer[arrayscalerX] = (unsigned char*)theBuf[arrayscalerX];

	//	dataBuffer[arrayscalerX] = reinterpret_cast<unsigned char*>(&theBuf[arrayscalerX]);

		dataBuffer[arrayscalerX] = theBufXXX[arrayscalerX];
	}*/


//	MessageBox(0,"SaveScreenShot 2\0","\0",0);

    //Now the file creation
    FILE* filePtr = fopen(getOgcDirFile(/*seess1.tga\0*/XorStr<0xBC,12,0x8CC761D5>("\xCF\xD8\xDB\xCC\xB3\xF0\xEC\xB7\xA3\xA4\xC6"+0x8CC761D5).s)
		, /*wb\0*/XorStr<0x97,4,0x48B1AD01>("\xE0\xFA\x99"+0x48B1AD01).s);
    if (!filePtr)
	{
	//	logme1("SaveScreenShot = ERROR -3\0");
		free(dataBuffer);
		return -3;
	}

    unsigned char TGAheader[12]={0,0,2,0,0,0,0,0,0,0,0,0};
    unsigned char header[6] = { w%256,w/256,
			       h%256,h/256,
			       24,0};

//	MessageBox(0,"SaveScreenShot 3\0","\0",0);

    // We write the headers
    fwrite(TGAheader,	sizeof(unsigned char),	12,	filePtr);
    fwrite(header,	sizeof(unsigned char),	6,	filePtr);
    // And finally our image data
    fwrite(dataBuffer,	sizeof(GLubyte),	nSize,	filePtr);
    fclose(filePtr);
 
    free(dataBuffer);

//	MessageBox(0,"SaveScreenShot 4\0","\0",0);
 
	//logme1("SaveScreenShot = OK\0");
    return 0;
}

//-------------------------------------------------------------------//
