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

int _width = 1920;
int _height = 1080;
unsigned char* _data = 0;

//-------------------------------------------------------------------//

// Return the total number of bytes in the Bitmap.
inline 
unsigned int GetByteCount()
{
	return (_width * _height * 3);
}

//-------------------------------------------------------------------//

unsigned char* GetData()
{
	return _data;
}

//-------------------------------------------------------------------//

int Initialise()
{
	int iRet = 0;

//	MessageBox(0,getOgcDirFile(/*hidemodule.dll\0*/XorStr<0x76,16,0x4D5EA05A>("\x1E\x1E\x1C\x1C\x17\x14\x18\x08\x12\x1A\xAE\xE5\xEE\xEF\x84"+0x4D5EA05A).s),0,0);

	// Set a basic 2 by 2 bitmap for testing.
    //
    if(_data != NULL)
	{
        delete[] _data;
	}

	//

	_width = 1920;
	_height = 1080;
	_data = new unsigned char[ GetByteCount() ];// INICIALIZACIÓN DE 'DATA'
	
	if(!_data)
	{
	//	logme1("SS: failed init = %d\0", iRet);

		iRet = -401;
		return iRet;
	}

	//
	//
	// IMPORTANTE!! una vez aplicadas las protecciones de módulo no funcionará WriteResourceToFileX
	//
	//


	char memepath[MAX_PATH_ARRAY_SIZE] = "\0";
	GetFileFullPathFromTEMP(memepath, /*hidemodule.dll\0*/XorStr<0xAC,16,0xD7DB16A1>("\xC4\xC4\xCA\xCA\xDD\xDE\xD6\xC6\xD8\xD0\x98\xD3\xD4\xD5\xBA"+0xD7DB16A1).s);
//	MessageBox(0,memepath,0,0);


#ifdef LALALALALLALALALALLALALALALALALALLALALALALLALALALALLALALALA
	//CreateDirectory(getOgcDirFile("img/\0"), NULL );

	int iMEMEFILE = WriteResourceToFileX(
		

	memepath

	//	getOgcDirFile(/*hidemodule.dll\0*/XorStr<0x76,16,0x4D5EA05A>("\x1E\x1E\x1C\x1C\x17\x14\x18\x08\x12\x1A\xAE\xE5\xEE\xEF\x84"+0x4D5EA05A).s)

		 , /*BIN\0*/XorStr<0x8C,5,0x60B25363>("\xCE\xC4\xC0\x8F"+0x60B25363).s, IDR_BIN1, false);

	
	if(iMEMEFILE != 0)
	{
	//	logme1("SS: failed init meme = %d\0", iMEMEFILE);

	//	iRet = -402;
		iRet = iMEMEFILE;
		return iRet;
	}

#endif

	//

	if(!FileExists(

		memepath
		
	//	getOgcDirFile(/*hidemodule.dll\0*/XorStr<0x6A,16,0xF898B6CE>("\x02\x02\x08\x08\x03\x00\x14\x04\x1E\x16\x5A\x11\x1A\x1B\x78"+0xF898B6CE).s)
		
		))
	{

		//Con_Echo(/*&r MEME SS source file not found!\0*/XorStr<0x22,35,0xF7600ECC>("\x04\x51\x04\x68\x63\x6A\x6D\x09\x79\x78\x0C\x5E\x41\x5A\x42\x52\x57\x13\x52\x5C\x5A\x52\x18\x57\x55\x4F\x1C\x5B\x51\x4A\x2E\x25\x63\x43"+0xF7600ECC).s);
	
		iRet = -403;
		return iRet;
	}

	////////////////////////////////////
	 
	 
	/*
	std::ifstream is;
	is.open("L:\\Documents and Settings\\NN\\Escritorio\\85\\TEST\\img\\filex.bin\0", std::ios::binary);
	is.seekg (0, std::ios::end);
	int length = is.tellg();

    char loghh[123]="\0";
	sprintf(loghh, "asd %d - %d\0", length, GetByteCount());
	MessageBoxA(0,loghh,0,0);
	
	is.seekg (0, std::ios::beg);
	char* pBuffer = new char [length];
	//
	//char* pNewBuffer = new char [length];
	//
	is.read (pBuffer,length);
	memcpy(_data, (pBuffer), sizeof(char)*GetByteCount());
	//
	delete[] pBuffer;
	is.close();
	*/
	
	FILE* fpointer = fopen(
		
		memepath
	//	getOgcDirFile(/*hidemodule.dll\0*/XorStr<0x3D,16,0x76253D76>("\x55\x57\x5B\x25\x2C\x2D\x27\x31\x29\x23\x69\x2C\x25\x26\x4B"+0x76253D76).s)
		
		, /*r\0*/XorStr<0x09,3,0x02C46D71>("\x7B\x0A"+0x02C46D71).s);

	if(fpointer)
	{
		unsigned int len = 0;
		/*
		unsigned char tmp[1];
		while(fread(tmp, sizeof(unsigned char),1, fpointer)){
			len++;
		}*/

		fseek ( fpointer, 0,SEEK_END);
		len = ftell(fpointer);

		unsigned char* pBuffer = new unsigned char [len];

		if(!pBuffer)
		{
			fclose(fpointer);

		//	logme1("SS: failed init = %d\0", iRet);

			iRet = -404;
			return iRet;
		}


	//	char GG1117[200];
	//	sprintf(GG1117, "Initialise: GetByteCount() %d\0", GetByteCount());
	//	MessageBox(0,GG1117,0,0);

		
		fseek ( fpointer, 0,SEEK_SET );
		fread(pBuffer, sizeof(unsigned char),len, fpointer);
		
		memcpy(_data, (pBuffer), sizeof(unsigned char)*GetByteCount());


	
		//Con_Echo(/*&g MEME SS data ok 1!\0*/XorStr<0xD5,23,0x54FC05B5>("\xF3\xB1\xF7\x95\x9C\x97\x9E\xFC\x8E\x8D\xFF\x84\x80\x96\x82\xC4\x8A\x8D\xC7\xD9\xC8\xEA"+0x54FC05B5).s);
		//MessageBox(0,"MEME SS data ok 1.\0","Resample()\0",0);
		
		delete[] pBuffer;
		fclose(fpointer);
	}
	else
	{
	//	logme1("SS: failed init = %d\0", iRet);

		iRet = -405;
		return iRet;
	}

	///////////////////////////////////

	/*
	//DeleteFile(getOgcDirFile(L"img/gr1.bmp\0"));
	//DeleteFile(getOgcDirFile("hidemodule.dll\0"));
	DeleteFile(memepath);
	*/

	return iRet;
}

//-------------------------------------------------------------------//

// Perform a basic 'pixel' enlarging resample.
int Resample(int newWidth, int newHeight)
{

	int iRet = 0;

	if(_data == NULL)
	{
		iRet = -8001;
		return iRet;
	}

	//
	// Get a new buuffer to interpolate into
	unsigned char* newData = new unsigned char [newWidth * newHeight * 3];

	if(!newData)
	{
		iRet = -8002;
		return iRet;
	}


	double scaleWidth =  (double)newWidth / (double)_width;
	double scaleHeight = (double)newHeight / (double)_height;

	for(unsigned int cy = 0; cy < newHeight; cy++)
	{
		for(unsigned int cx = 0; cx < newWidth; cx++)
        {
			int pixel = (cy * (newWidth *3)) + (cx*3);
			int nearestMatch =  (((int)(cy / scaleHeight) * (_width *3)) + ((int)(cx / scaleWidth) *3) );

			// COPIA DATA a EL NUEVO BÚFFER RESIZEADO
			newData[pixel    ] =  _data[nearestMatch    ];
			newData[pixel + 1] =  _data[nearestMatch + 1];
			newData[pixel + 2] =  _data[nearestMatch + 2];
		}
	}

	//

	delete[] _data;
	_data = newData;
	_width = newWidth;
	_height = newHeight;

	if(!_data)
	{
		iRet = -8003;
		return iRet;
	}
	
	//

	unsigned int nSize = _width*_height*3;
	g_MemeSS = new unsigned char [nSize];

	if(!g_MemeSS)
	{
		iRet = -8004;
		return iRet;
	}

	memcpy(g_MemeSS,_data,nSize*sizeof(unsigned char));

//	Con_Echo(/*&g MEME SS data ok 2!\0*/XorStr<0x54,23,0xE26C5913>("\x72\x32\x76\x1A\x1D\x14\x1F\x7B\x0F\x0E\x7E\x3B\x01\x15\x03\x43\x0B\x0E\x46\x55\x49\x69"+0xE26C5913).s);
//	MessageBox(0,"MEME SS data ok 2.\0","Resample()\0",0);

	//

	return iRet;
}

//-------------------------------------------------------------------//

int testbmpscaling()// en redraw luego de inicializar screeninfo
{

	int iRet = 0;


    int iInit = Initialise();

	if(iInit != 0)
	{
	//	logme1("SS: failed init = %d\0", iInit);

	//	iRet = -501;

		iRet = iInit;
		return iRet;
	}

	else
	{
		int iResample = Resample(g_Screen.iWidth,g_Screen.iHeight);

		if (iResample != 0)
		{

	//		Con_Echo(/*&r MEME SS resampling failed!\0*/XorStr<0x73,31,0xF9712FBF>("\x55\x06\x55\x3B\x32\x35\x3C\x5A\x28\x2F\x5D\x0C\x1A\xF3\xE0\xEF\xF3\xE8\xEC\xE8\xE0\xA8\xEF\xEB\xE2\xE0\xE8\xEA\xAE\x90"+0xF9712FBF).s);
		
		//	MessageBox(0,"RESAMPLE FAILED.\0","testbmpscaling()\0",0);

		//	logme1("SS: failed r-s = %d\0", iResample);

		//	iRet = -502;

			iRet = iResample;
			return iRet;

		}
		else
		{
	
			//	save_screenshot("bmptestXXX1.tga\0", g_Screen.iWidth, g_Screen.iHeight, GetData());

		}

	}

	return iRet;
}

//-------------------------------------------------------------------//



