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

struct menu_entrys
{
	char title[2000];
	bool flotating;
	bool showEntry;
	//
	int* ivalue;
	int imin;
	int imax;
	int istep;
	//
	float* fvalue;
	float fmin;
	float fmax;
	float fstep;
	//
	bool isCat;
	int catnum;
};

//-------------------------------------------------------------------//

class cMenu
{

public:

	cMenu()
	{
		for(unsigned int i=0; i<999; i++)
		{
			menuEntry[i].title[0] = 0;
			menuEntry[i].flotating = 0;
			menuEntry[i].showEntry = 0;
			//
			menuEntry[i].ivalue = 0;
			menuEntry[i].imin = 0;
			menuEntry[i].imax = 0;
			menuEntry[i].istep = 0;
			//
			menuEntry[i].fvalue = 0;
			menuEntry[i].fmin = 0.0f;
			menuEntry[i].fmax = 0.0f;
			menuEntry[i].fstep = 0.0f;

			menuEntry[i].isCat=false;
			menuEntry[i].catnum = 0;
		}

		menuSelect=0;
		menuItems=0;
		menuCurrentCat=0;
		sendOpen=0;
		sendClose=0;
		Active=false;
		
	}

private:

	int AddEntry_FLOAT(int n, char title[2000], 
		bool showEntry, float* value, float min, float max, float step, bool iscat, int catnum);
	int AddEntry_INT(int n, char title[2000], 
		bool showEntry, int* value, int min, int max, int step, bool iscat, int catnum);
	int menuSelect;
	int menuItems;
	int menuCurrentCat;
	bool sendOpen;
	bool sendClose;
	menu_entrys menuEntry[999];

public:

	void Init();
	void DrawItem_FLOAT(int i, float _xxx, float _yyy, float _www, float _hhh, int r, int g, int b, int a);
	void DrawItem_INT(int i, float _xxx, float _yyy, float _www, float _hhh, int r, int g, int b, int a);
	void Draw2(int iWidth, int iHeight);
	int KeyEvent(int keynum);
	int Active;
};

//-------------------------------------------------------------------//

extern cMenu gMenu;

//-------------------------------------------------------------------//
