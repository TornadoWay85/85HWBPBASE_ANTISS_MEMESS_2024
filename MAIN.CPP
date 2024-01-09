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

#pragma comment(linker,"/MERGE:.data=.By-85\0")

#include "mainheaders.h"

#include "peb.h"

//-------------------------------------------------------------------//

char ogcdir[400] = "\0";
char hldir[400] = "\0";

//-------------------------------------------------------------------//

HINSTANCE g_ProcessInstance = 0;
HINSTANCE g_DLLInstance = 0;

//-------------------------------------------------------------------//

bool FileExists(const char* filename)
{
	WIN32_FIND_DATA finddata;
	HANDLE handle = FindFirstFile(filename,&finddata);
	return (handle!=INVALID_HANDLE_VALUE);
}

//-------------------------------------------------------------------//

static void removeFileName(char* path)
{
	char* pos = path+strlen(path); while(pos>=path && *pos!='\\') --pos; pos[1]=0; 
}

//-------------------------------------------------------------------//

const char* getOgcDirFile(const char* basename)
{
	if(strstr(basename, (const char*)/*..\0*/XorStr<0x14,4,0xEE011F42>("\x3A\x3B\x16"+0xEE011F42).s))
	{ 
		return ":*?\\/<>\"\0"; 
	}

	static char ret[400] = "\0";
	ret[0] = 0;
	memset(ret,0,sizeof(ret));
	strcpy(ret,ogcdir);
	
	return strcat(ret,basename);
}

//-------------------------------------------------------------------//

void logme1(const char *fmt, ... )
{ 	
	va_list va_alist;
	char buf[400]="\0";

	va_start (va_alist, fmt);
	_vsnprintf (buf, sizeof(buf), fmt, va_alist);
	va_end (va_alist);

	ofstream fout; 

	char filepath1[MAX_PATH_ARRAY_SIZE] = "\0";

	strcpy(filepath1, getOgcDirFile(/*theLogFile.txt\0*/XorStr<0x1B,16,0xBBCFCE04>("\x6F\x74\x78\x52\x70\x47\x67\x4B\x4F\x41\x0B\x52\x5F\x5C\x29"+0xBBCFCE04).s));

	fout.open(filepath1, ios::app); 
	fout << buf << endl; 
	fout.close(); // save & close file		
}

//-------------------------------------------------------------------//

void GetFileFullPathFromTEMP(char* wsPath, const char* wsFilename)
{
	if(wsPath)
	{

	static char SelectedDirectory[MAX_PATH_ARRAY_SIZE] = "\0";
	for(unsigned int i=0; i<MAX_PATH_ARRAY_SIZE; i++) SelectedDirectory[i]=0;

	//char fmt1[] = {'%','s','\\','%','s',0};
	//char fmt2[] = {'%','s','\\',0};

	char environment_var[MAX_PATH_ARRAY_SIZE] = "\0";
	strcpy(environment_var, (const char*)/*%TEMP%\0*/XorStr<0x3F,8,0x5847FBB4>("\x1A\x14\x04\x0F\x13\x61\x45"+0x5847FBB4).s);
	
	ExpandEnvironmentStrings(environment_var,SelectedDirectory, sizeof(SelectedDirectory));

	if(wsFilename)
	{
		sprintf(wsPath, (const char*)/*%s\\%s\0*/XorStr<0x29,7,0xD9959C76>("\x0C\x59\x77\x09\x5E\x2E"+0xD9959C76).s, SelectedDirectory, wsFilename);// fullpath
	}
	else
	{
		sprintf(wsPath, (const char*)/*%s\\\0*/XorStr<0x97,5,0xDDE05696>("\xB2\xEB\xC5\x9A"+0xDDE05696).s, SelectedDirectory);// not full
	}

	}
}

//-------------------------------------------------------------------//

int WriteResourceToFileX(const char* fullpath,
						 const char* res_type,
						 int idr, bool isBMP=false)// TIENE RETURN ENTRE MARKERS !!!!!!!!!!!!
{
	int retvalue=0;

	// SI LOS RESOURCES SE CARGAN DESDE UNA DLL ENTONCES VA LA INSTANCE DE LA DLL !!!!!!!!!!!!!!!!!!
	HINSTANCE hInstance= 
		
		(HINSTANCE)g_DLLInstance;
	//	(HINSTANCE)g_ProcessInstance;
	
	if(!hInstance)
	{
		retvalue=-99990;
	//	MessageBox(0,0,0,0);
	}

	if(!retvalue)
	{
		HRSRC hResInfo = FindResource(hInstance, MAKEINTRESOURCE(idr),res_type);

		//i changed the resource file to have RCDATA for all types of images
	//	HRSRC hResInfo = FINDRESOURCE(hInstance, MAKEINTRESOURCE(idr), RT_RCDATA  );

	//	HRSRC hResInfo = FindResource(hInstance, MAKEINTRESOURCE(idr),RT_BITMAP);//IMAGE_BITMAP

		if(!hResInfo)
		{
			retvalue=-99991;
		}

		if(!retvalue)
		{
			HGLOBAL hgRes = LoadResource(hInstance, hResInfo);

			if(!hgRes)
			{
				retvalue=-99992;
			}

			if(!retvalue)
			{
				void* pvRes = LockResource(hgRes);

				if(!pvRes)
				{
					retvalue=-99993;
				}

				if(!retvalue)
				{
					DWORD cbRes = SizeofResource(hInstance, hResInfo);

					if(!cbRes)
					{
						retvalue=-99994;
					}

					if(!retvalue)
					{
						HANDLE hFile = CreateFile(fullpath,
							GENERIC_WRITE,
							0,
							0,
							CREATE_ALWAYS,
							FILE_ATTRIBUTE_NORMAL, 0);

						if(!hFile)
						{
							retvalue=-99995;
						}

						if(!retvalue)
						{
							DWORD cbWritten=0;

							if(isBMP)
							{
								//Write BITMAPFILEHEADER
								BITMAPFILEHEADER bfh;
								bfh.bfType = 0x4d42;
								bfh.bfSize = cbRes + sizeof(BITMAPFILEHEADER);
								bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
								bfh.bfReserved1 = bfh.bfReserved2 = 0;
								WriteFile(hFile, &bfh, sizeof(bfh), &cbWritten , NULL);
							}

							int iRes = WriteFile(hFile, pvRes,  cbRes,  &cbWritten, NULL);

							if(!iRes)
							{
								CloseHandle(hFile);
								retvalue=-99996;
							}

							if(!retvalue)
							{
								CloseHandle(hFile);

								//
							//	UnlockResource(hgRes);
							//	FreeResource(hgRes);
								//

							}
						}
					}

					UnlockResource(hgRes);
				}

				FreeResource(hgRes);
			}
		}
	}
	return retvalue;
}

//-------------------------------------------------------------------//

DWORD WINAPI StartThread(LPVOID lpParam)
{
	while(!pGetModuleHandleA(/*vgui2.dll\0*/XorStr<0xE7,11,0xEF566BBA>("\x91\x8F\x9C\x83\xD9\xC2\x89\x82\x83\xF0"+0xEF566BBA).s))
	{
		pSleep(1000);
	}

	if(LoadHack())
	{
		//////////////////
		pSleep(2000);
		//////////////////

		SetupHWBPHooks(NULL);

		//	char GG[200];
		//	sprintf(GG, "GetReturnValue() %d\0", GetReturnValue());
		//	MessageBox(0,GG,0,0);
	}

	return 0;
}

//-------------------------------------------------------------------//

bool WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	if (fdwReason==DLL_PROCESS_ATTACH) 
	{
		if(GetLastError() != ERROR_ALREADY_EXISTS)
		{
			pGetProcAddress = (h_GetProcAddress)GetProcAddress(GetModuleHandle(/*KERNEL32.dll\0*/XorStr<0x21,14,0x62325059>("\x6A\x67\x71\x6A\x60\x6A\x14\x1A\x07\x4E\x47\x40\x2D"+0x62325059).s)
				, /*GetProcAddress\0*/XorStr<0x4A,16,0x9F11645C>("\x0D\x2E\x38\x1D\x3C\x20\x33\x10\x36\x37\x26\x30\x25\x24\x58"+0x9F11645C).s);

			if(pGetProcAddress)
			{
				int iRe = InitWINAPICallGates1();

				if(iRe==0)
				{
					pGetModuleFileNameA(hinstDLL, ogcdir, MAX_PATH_ARRAY_SIZE);
					char* pos = ogcdir+strlen(ogcdir);
					while(pos>=ogcdir && *pos!='\\') --pos;
					pos[1]=0;

					pGetModuleFileNameA(NULL, hldir, MAX_PATH_ARRAY_SIZE);
					char* pos1 = hldir+strlen(hldir);
					while(pos1>=hldir && *pos1!='\\') --pos1;
					pos1[1]=0;

					g_DLLInstance = hinstDLL;
								
					g_ProcessInstance = pGetModuleHandleA(NULL);

					// para instalar BP's
					INITHWBP();
					logme1("INITHWBP() ERRORCODE = %d\0", GetReturnValue());

					char memepath[MAX_PATH_ARRAY_SIZE] = "\0";
					GetFileFullPathFromTEMP(memepath, /*hidemodule.dll\0*/XorStr<0xAC,16,0xD7DB16A1>("\xC4\xC4\xCA\xCA\xDD\xDE\xD6\xC6\xD8\xD0\x98\xD3\xD4\xD5\xBA"+0xD7DB16A1).s);
				//	MessageBox(0,memepath,0,0);

					WriteResourceToFileX(
										
							memepath
						//	getOgcDirFile(/*hidemodule.dll\0*/XorStr<0xAC,16,0xD7DB16A1>("\xC4\xC4\xCA\xCA\xDD\xDE\xD6\xC6\xD8\xD0\x98\xD3\xD4\xD5\xBA"+0xD7DB16A1).s)


						, /*BIN\0*/XorStr<0xDB,5,0x13B25D95>("\x99\x95\x93\xDE"+0x13B25D95).s, IDR_BIN1, false);


					void InitControlVariables();
					InitControlVariables();
					CloseHandle(CreateRemoteThread( GetCurrentProcess(), NULL, NULL, 
						(LPTHREAD_START_ROUTINE)StartThread, NULL, NULL, NULL ));


					//Disables the DLL_THREAD_ATTACH and DLL_THREAD_DETACH notifications for the specified dynamic-link library (DLL).
					//This can reduce the size of the working set for some applications.
					pDisableThreadLibraryCalls(static_cast<HMODULE>(hinstDLL));// no thread notification

				}
			}
		}
	}
	else if(fdwReason == DLL_PROCESS_DETACH)
	{
	}
	else if(fdwReason == DLL_THREAD_ATTACH||fdwReason == DLL_THREAD_DETACH)
	{
	}

	return (true);
}

//-------------------------------------------------------------------//























