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

cMenu gMenu;

/*

  disclaimer

  THIS MENU WAS TAKEN FROM A PUBLIC AND RIPPED DLL WITH FUNNY RIPS, AN UNPROTECTED DLL
  BLAME ME NOT FOR THIS RIP OF CODE

*/

//-------------------------------------------------------------------//

int cMenu::AddEntry_FLOAT(int n, char title[2000], 
						  bool showEntry, float* value, 
						  float min, float max, float step, bool iscat=false, int catnum=0)
{
	strcpy( menuEntry[n].title,title);

	menuEntry[n].flotating = true;
	menuEntry[n].showEntry = showEntry;
	//
	menuEntry[n].ivalue = 0;
	menuEntry[n].imin = 0;
	menuEntry[n].imax = 0; 
	menuEntry[n].istep = 0;
	//
	menuEntry[n].fvalue = value;
	menuEntry[n].fmin = min;
	menuEntry[n].fmax = max; 
	menuEntry[n].fstep = step;
	//
	menuEntry[n].isCat=iscat;

	menuEntry[n].catnum = catnum;

	return (n+1);
}

//-------------------------------------------------------------------//

int cMenu::AddEntry_INT(int n, char title[2000], 
						bool showEntry, int* value, 
						int min, int max, int step, bool iscat=false, int catnum=0)
{
	strcpy( menuEntry[n].title,title);

	menuEntry[n].flotating = false;
	menuEntry[n].showEntry = showEntry;
	//
	menuEntry[n].fvalue = 0;
	menuEntry[n].fmin = 0;
	menuEntry[n].fmax = 0; 
	menuEntry[n].fstep = 0;
	//
	menuEntry[n].ivalue = value;
	menuEntry[n].imin = min;
	menuEntry[n].imax = max; 
	menuEntry[n].istep = step;
	//
	menuEntry[n].isCat=iscat;

	menuEntry[n].catnum = catnum;

	return (n+1);
}

//-------------------------------------------------------------------//

#define ISCATEGORY true
#define ISITEM false

#define SHOWMSG true
#define DONOTSHOWMSG false

void cMenu::Init()
{
	if(!Active) return;
	menuCurrentCat=0;

	int i = 1;

	// al mover con la flecha en keyevent cambia el VALUE
	//

	i = AddEntry_FLOAT(i,/*   + CATE1\0*/XorStr<0xA0,12,0xA5F0FF7F>("\x80\x81\x82\x88\x84\xE6\xE7\xF3\xED\x98\xAA"+0xA5F0FF7F).s,DONOTSHOWMSG,&CVARS.menutitle1,0,1,1,ISCATEGORY, 1);

	if (CVARS.menutitle1)
	{
		menuCurrentCat=1;


		i = AddEntry_INT(i,(char*)/*        AntiScreenshot\0*/XorStr<0x48,24,0x1FDD3211>("\x68\x69\x6A\x6B\x6C\x6D\x6E\x6F\x11\x3F\x26\x3A\x07\x36\x24\x32\x3D\x37\x29\x33\x33\x29\x5E"+0x1FDD3211).s, true,&CVARS.antiss,0,1,1,ISITEM, 0);
		i = AddEntry_INT(i,(char*)/*        Meme SS\0*/XorStr<0xC1,17,0x21D24025>("\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\x84\xAF\xA6\xA9\xED\x9D\x9C\xD0"+0x21D24025).s, true,&CVARS.memess,0,1,1,ISITEM, 0);
		i = AddEntry_INT(i,(char*)/*        SS To Blue\0*/XorStr<0xF5,20,0x2060796D>("\xD5\xD6\xD7\xD8\xD9\xDA\xDB\xDC\xAE\xAD\xDF\x54\x6E\x22\x41\x68\x70\x63\x07"+0x2060796D).s, true,&CVARS.sstoblue,0,1,1,ISITEM, 0);
		i = AddEntry_FLOAT(i,(char*)/*        SS Interval\0*/XorStr<0x63,21,0x20C63552>("\x43\x44\x45\x46\x47\x48\x49\x4A\x38\x3F\x4D\x27\x01\x04\x14\x00\x05\x15\x19\x76"+0x20C63552).s, true,&CVARS.ss_interval,0,60,1,ISITEM, 0);

		i = AddEntry_INT(i,(char*)/*        SS Frames\0*/XorStr<0xBF,19,0x12CF9D5A>("\x9F\xE0\xE1\xE2\xE3\xE4\xE5\xE6\x94\x9B\xE9\x8C\xB9\xAD\xA0\xAB\xBC\xD0"+0x12CF9D5A).s, true,&CVARS.ss_cleanframes,0,1000,1,ISITEM, 0);

		i = AddEntry_FLOAT(i,(char*)/*        SoundTime\0*/XorStr<0xBC,19,0xF82E24D9>("\x9C\x9D\x9E\x9F\xE0\xE1\xE2\xE3\x97\xAA\xB3\xA9\xAC\x9D\xA3\xA6\xA9\xCD"+0xF82E24D9).s, true,&CVARS.sndtime,0,3,1,ISITEM, 0);



		i = AddEntry_INT(i,(char*)"        See SS (muestra los BUFFERS)\0", true,&CVARS.seess,0,1,1,ISITEM, 0);

		i = AddEntry_INT(i,(char*)"        Test SS (saca una SS actual)\0", true,&CVARS.testss,0,1,1,ISITEM, 0);



	}


	i = AddEntry_FLOAT(i,/*   + CATE2\0*/XorStr<0xC3,12,0xB670F323>("\xE3\xE4\xE5\xED\xE7\x8B\x88\x9E\x8E\xFE\xCD"+0xB670F323).s,DONOTSHOWMSG,&CVARS.menutitle2,0,1,1,ISCATEGORY, 2);

	if (CVARS.menutitle2)
	{
		menuCurrentCat=2;

		i = AddEntry_INT(i,(char*)/*        HACK ON\0*/XorStr<0x62,17,0xCE4C0658>("\x42\x43\x44\x45\x46\x47\x48\x49\x22\x2A\x2F\x26\x4E\x20\x3E\x71"+0xCE4C0658).s, true,&CVARS.hackon,0,1,1,ISITEM, 0);
		i = AddEntry_INT(i,(char*)/*        DRAW ON\0*/XorStr<0x30,17,0x779DDF88>("\x10\x11\x12\x13\x14\x15\x16\x17\x7C\x6B\x7B\x6C\x1C\x72\x70\x3F"+0x779DDF88).s, true,&CVARS.drawon,0,1,1,ISITEM, 0);

		i = AddEntry_INT(i,(char*)/*        INFO\0*/XorStr<0x0B,14,0x0DA89EA1>("\x2B\x2C\x2D\x2E\x2F\x30\x31\x32\x5A\x5A\x53\x59\x17"+0x0DA89EA1).s, true,&CVARS.info,0,1,1,ISITEM, 0);
		
		i = AddEntry_INT(i,(char*)/*        MenuX\0*/XorStr<0xF4,15,0x9DB63840>("\xD4\xD5\xD6\xD7\xD8\xD9\xDA\xDB\xB1\x98\x90\x8A\x58\x01"+0x9DB63840).s, true,&CVARS.menux,-200,200,1,ISITEM, 0);
		i = AddEntry_INT(i,(char*)/*        MenuY\0*/XorStr<0x47,15,0x46B36468>("\x67\x68\x69\x6A\x6B\x6C\x6D\x6E\x02\x35\x3F\x27\x0A\x54"+0x46B36468).s, true,&CVARS.menuy,-200,200,1,ISITEM, 0);
	

		i = AddEntry_INT(i,(char*)/*        ShutDown PC\0*/XorStr<0xE9,21,0xE4BB4884>("\xC9\xCA\xCB\xCC\xCD\xCE\xCF\xD0\xA2\x9A\x86\x80\xB1\x99\x80\x96\xD9\xAA\xB8\xFC"+0xE4BB4884).s, true,&CVARS.codeshut,0,1,1,ISITEM, 0);
		i = AddEntry_INT(i,(char*)/*        TestX1\0*/XorStr<0xFF,16,0x0FC25111>("\xDF\x20\x21\x22\x23\x24\x25\x26\x53\x6D\x7A\x7E\x53\x3D\x0D"+0x0FC25111).s, true,&CVARS.testx1,0,1,1,ISITEM, 0);
		i = AddEntry_INT(i,(char*)/*        TestX2\0*/XorStr<0xF4,16,0x876775C0>("\xD4\xD5\xD6\xD7\xD8\xD9\xDA\xDB\xA8\x98\x8D\x8B\x58\x33\x02"+0x876775C0).s, true,&CVARS.testx2,0,1,1,ISITEM, 0);
		i = AddEntry_INT(i,(char*)/*        TestX3\0*/XorStr<0x65,16,0xEA5788C3>("\x45\x46\x47\x48\x49\x4A\x4B\x4C\x39\x0B\x1C\x04\x29\x41\x73"+0xEA5788C3).s, true,&CVARS.testx3,0,1,1,ISITEM, 0);
		i = AddEntry_INT(i,(char*)/*        TestX4\0*/XorStr<0xF8,16,0x8FA6B7DE>("\xD8\xD9\xDA\xDB\xDC\xDD\xDE\xDF\x54\x64\x71\x77\x5C\x31\x06"+0x8FA6B7DE).s, true,&CVARS.testx4,0,1,1,ISITEM, 0);



	}

	i = AddEntry_FLOAT(i,/*   + CATE3\0*/XorStr<0xFB,12,0x79B3283F>("\xDB\xDC\xDD\xD5\xDF\x43\x40\x56\x46\x37\x05"+0x79B3283F).s,DONOTSHOWMSG,&CVARS.menutitle3,0,1,1,ISCATEGORY, 3);

	if (CVARS.menutitle3)
	{
		menuCurrentCat=3;


	}


	i = AddEntry_FLOAT(i,/*   + CATE4\0*/XorStr<0xED,12,0x31B93912>("\xCD\xCE\xCF\xDB\xD1\xB1\xB2\xA0\xB0\xC2\xF7"+0x31B93912).s,DONOTSHOWMSG,&CVARS.menutitle4,0,1,1,ISCATEGORY, 4);

	if (CVARS.menutitle4)
	{
		menuCurrentCat=4;


	}


	i = AddEntry_FLOAT(i,/*   + CATE5\0*/XorStr<0x34,12,0x61C7E616>("\x14\x15\x16\x1C\x18\x7A\x7B\x6F\x79\x08\x3E"+0x61C7E616).s,DONOTSHOWMSG,&CVARS.menutitle5,0,1,1,ISCATEGORY, 5);

	if (CVARS.menutitle5)
	{
		menuCurrentCat=5;


	}


	i = AddEntry_FLOAT(i,/*   + CATE6\0*/XorStr<0x97,12,0xD61DAA3C>("\xB7\xB8\xB9\xB1\xBB\xDF\xDC\xCA\xDA\x96\xA1"+0xD61DAA3C).s,DONOTSHOWMSG,&CVARS.menutitle6,0,1,1,ISCATEGORY, 6);

	if (CVARS.menutitle6)
	{
		menuCurrentCat=6;



		

	}


	i = AddEntry_FLOAT(i,/*   + CATE7\0*/XorStr<0x10,12,0x55BCA883>("\x30\x31\x32\x38\x34\x56\x57\x43\x5D\x2E\x1A"+0x55BCA883).s,DONOTSHOWMSG,&CVARS.menutitle7,0,1,1,ISCATEGORY, 7);

	if (CVARS.menutitle7)
	{
		menuCurrentCat=7;

	
	

	
	

	}


	i = AddEntry_FLOAT(i,/*   + CATE8\0*/XorStr<0x59,12,0x0BC2E644>("\x79\x7A\x7B\x77\x7D\x1D\x1E\x34\x24\x5A\x63"+0x0BC2E644).s,DONOTSHOWMSG,&CVARS.menutitle8,0,1,1,ISCATEGORY, 8);

	if (CVARS.menutitle8)
	{
		menuCurrentCat=8;


	}

	//

	menuItems = i-1;

	static bool atstart = false;
	if(!atstart)
	{
		atstart=true;
		if(!menuSelect && menuItems>0) { menuSelect = 1; }
	}

	if(CVARS.dummy) CVARS.dummy=0;
}

//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
// 
//-------------------------------------------------------------------//

int cMenu::KeyEvent(int keynum)
{

	//if(GetAsyncKeyState(VK_UP) < 0 )
	if( keynum == 128 || keynum == 240) //uparrow || mwheelup
	{
		if( menuSelect>1 ) menuSelect--;
		else menuSelect = menuItems;

		return 0;
	}

	//if(GetAsyncKeyState(VK_DOWN) < 0)
	else if( keynum == 129 || keynum == 239) //downarrow || mwheeldown
	{
		if( menuSelect<menuItems ) menuSelect++;
		else menuSelect = 1;
		
		return 0;
	}

	//if( (GetAsyncKeyState(VK_LEFT) < 0) || (GetAsyncKeyState(VK_LBUTTON) < 0) )
	else if( keynum == 130 || keynum == 241 ) //leftarrow || leftbutton
	{
		if(menuEntry[menuSelect].isCat)
		{
			if(!menuCurrentCat) sendOpen=true;
			if(menuCurrentCat) sendClose=true;


			if(menuEntry[menuSelect].catnum == 1 /*&& CVARS.menutitle1*/){

				CVARS.menutitle1=!CVARS.menutitle1;
			//	CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 2){
				CVARS.menutitle2=!CVARS.menutitle2;
				CVARS.menutitle1=0;
				CVARS.menutitle3=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 3){
				CVARS.menutitle3=!CVARS.menutitle3;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 4){
				CVARS.menutitle4=!CVARS.menutitle4;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 5){
				CVARS.menutitle5=!CVARS.menutitle5;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle4=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 6){
				CVARS.menutitle6=!CVARS.menutitle6;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle7=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 7){
				CVARS.menutitle7=!CVARS.menutitle7;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 8){
				CVARS.menutitle8=!CVARS.menutitle8;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 9){
				CVARS.menutitle9=!CVARS.menutitle9;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle8=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 10){
				CVARS.menutitle10=!CVARS.menutitle10;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
			}
		}
		else // ejecuta un - (cambia los valores por puntero en vez de por comando)
		{
			// significa que son las que ejecutan un DOWN o UP del valor de la cvar
		/*	if(menuEntry[menuSelect].showEntry==1)
			{
			}
			else
			{
			}*/


			if(menuEntry[menuSelect].flotating)
			{
				if( menuEntry[menuSelect].fvalue )
				{
					menuEntry[menuSelect].fvalue[0] -= menuEntry[menuSelect].fstep;
					if( menuEntry[menuSelect].fvalue[0] < menuEntry[menuSelect].fmin )
						menuEntry[menuSelect].fvalue[0] = menuEntry[menuSelect].fmax;
				}
			} else {
			
				if( menuEntry[menuSelect].ivalue )
				{
					menuEntry[menuSelect].ivalue[0] -= menuEntry[menuSelect].istep;
					if( menuEntry[menuSelect].ivalue[0] < menuEntry[menuSelect].imin )
						menuEntry[menuSelect].ivalue[0] = menuEntry[menuSelect].imax;
				}
			}
		}

		return 0;
	}

	//if( (GetAsyncKeyState(VK_RIGHT) < 0) || (GetAsyncKeyState(VK_RBUTTON) < 0) )
	else if( keynum == 131 || keynum == 242 ) //rightarrow || rightbutton
	{
		if(menuEntry[menuSelect].isCat)
		{
			if(!menuCurrentCat) sendOpen=true;
			if(menuCurrentCat) sendClose=true;

			if(menuEntry[menuSelect].catnum == 1 /*&& CVARS.menutitle1*/){

				CVARS.menutitle1=!CVARS.menutitle1;
			//	CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 2){
				CVARS.menutitle2=!CVARS.menutitle2;
				CVARS.menutitle1=0;
				CVARS.menutitle3=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 3){
				CVARS.menutitle3=!CVARS.menutitle3;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 4){
				CVARS.menutitle4=!CVARS.menutitle4;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 5){
				CVARS.menutitle5=!CVARS.menutitle5;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle4=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 6){
				CVARS.menutitle6=!CVARS.menutitle6;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle7=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 7){
				CVARS.menutitle7=!CVARS.menutitle7;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 8){
				CVARS.menutitle8=!CVARS.menutitle8;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle9=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 9){
				CVARS.menutitle9=!CVARS.menutitle9;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle8=0;
				CVARS.menutitle10=0;
			}

			if(menuEntry[menuSelect].catnum == 10){
				CVARS.menutitle10=!CVARS.menutitle10;
				CVARS.menutitle1=0;
				CVARS.menutitle2=0; CVARS.menutitle3=0; CVARS.menutitle4=0; CVARS.menutitle5=0;
				CVARS.menutitle6=0; CVARS.menutitle7=0; CVARS.menutitle8=0; CVARS.menutitle9=0;
			}
		}
		else // ejecuta un + (cambia los valores por puntero en vez de por comando)
		{
			// significa que son las que ejecutan un DOWN o UP del valor de la cvar
		/*	if(menuEntry[menuSelect].showEntry==1)
			{
			}
			else
			{
			}*/

			if(menuEntry[menuSelect].flotating)
			{
				if( menuEntry[menuSelect].fvalue )
				{
					menuEntry[menuSelect].fvalue[0] += menuEntry[menuSelect].fstep;
					if( menuEntry[menuSelect].fvalue[0] > menuEntry[menuSelect].fmax )
						menuEntry[menuSelect].fvalue[0] = menuEntry[menuSelect].fmin;
				}
			} else {
			
				if( menuEntry[menuSelect].ivalue )
				{
					menuEntry[menuSelect].ivalue[0] += menuEntry[menuSelect].istep;
					if( menuEntry[menuSelect].ivalue[0] > menuEntry[menuSelect].imax )
						menuEntry[menuSelect].ivalue[0] = menuEntry[menuSelect].imin;
				}
			}
		}
		
		return 0;
	}
	return 1;
}

/*
void cMenu::MenuKeys()
{
	if(cvar.menu)
	{
		if(GetAsyncKeyState(VK_UP) < 0 )
		{
			if (!menu_up)
			{
				menu_up= true;
				if( menuIndex>0 ) menuIndex--;
			}
		}
		else menu_up = false;
		
		if(GetAsyncKeyState(VK_DOWN) < 0)
		{
			if (!menu_down)
			{
				menu_down= true;
				if( menuIndex<menuItems-1 ) menuIndex++;
			}
		}
		else menu_down = false;
		
		if( (GetAsyncKeyState(VK_LEFT) < 0) || (GetAsyncKeyState(VK_LBUTTON) < 0) ) //leftarrow || leftbutton
		{	
			if (!menu_deselect)
			{
				menu_deselect= true;
				if( menu[menuIndex].value )
				{
					menu[menuIndex].value[0] -= menu[menuIndex].step;
					if( menu[menuIndex].value[0] < menu[menuIndex].min )
						menu[menuIndex].value[0] = menu[menuIndex].max;
				}
			}
		}
		else menu_deselect = false;
		
		if( (GetAsyncKeyState(VK_RIGHT) < 0) || (GetAsyncKeyState(VK_RBUTTON) < 0) ) //rightarrow || rightbutton
		{
			if (!menu_select)
			{
				menu_select= true;
				if( menu[menuIndex].value )
				{
					menu[menuIndex].value[0] += menu[menuIndex].step;
					if( menu[menuIndex].value[0] > menu[menuIndex].max )
						menu[menuIndex].value[0] = menu[menuIndex].min;
				}
			}
		}
		else menu_select = false;
	}
}*/

//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//

float g_Xblackpart = 0;
float g_Wblackpart = 0;

//-------------------------------------------------------------------//

void cMenu::DrawItem_FLOAT(int i, float _xxx, float _yyy, float _www, float _hhh, int r, int g, int b, int a)
{
	//
	float divisions = (fabs(menuEntry[i].fmax)/menuEntry[i].fstep);// FIX: usar divisions !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//
	float currval = fabs(menuEntry[i].fvalue[0]);

	float percent = (currval*100/fabs(menuEntry[i].fmax));
	float firstwidth = (_www*percent/100);

	float secondwidth = _www - firstwidth;

/*	if( i == menuSelect )// selected
	{

		DrawConString (100, 360, 0, 255, 0, "max %f\0", fabs(menuEntry[i].fmax));
		DrawConString (100, 380, 0, 255, 0, "step %f\0", menuEntry[i].fstep);
		DrawConString (100, 400, 0, 255, 0, "divisions %f\0", divisions);
		DrawConString (100, 420, 0, 255, 0, "currval %f\0", currval);
		DrawConString (100, 440, 0, 255, 0, "percent %f\0", percent);
		DrawConString (100, 460, 0, 255, 0, "firstwidth %f\0", firstwidth);
		DrawConString (100, 480, 0, 255, 0, "secondwidth %f\0", secondwidth);
		DrawConString (100, 500, 0, 255, 0, "w1 y w2: %f %f\0", _www, (firstwidth+secondwidth));
	}*/


	float fix = 0;
/*	if((firstwidth+secondwidth) != _www)
	{
		//	fix = (_www - (firstwidth+secondwidth));
		//	fix = 1;

		DrawConString (100, 520, 0, 255, 0, "DIFERENT!\0");
	}*/


	if((secondwidth) >0)
	{
		//	fix = 1;
	}

	if( i == menuSelect )// selected
	{
		//	DrawConString (200, 500, 0, 255, 0, "%d %f %f (%f|%f)\0", _www, firstwidth, secondwidth, (firstwidth+secondwidth), fix);

		//	DrawConString (200, 500, 0, 255, 0, "FIXES: %f %f\0", fix, desacum2);
	}

	a = 200;
	//

	if(CVARS.drawon)
	{
	// triangle izq
	ZN10cHexagonal16DrawFillTriangleEiiiiiiiiii(
					
							_xxx-55-10, 
							_yyy + 1, 
							_xxx-55-10, 
							_yyy + _hhh - 1, 
							_xxx-55-10 - 9, 
							_hhh / 2 + _yyy,
							//
							255, 0, 0, a);


	}

	//
	
	if(firstwidth <_www){
		b = 0;
		g = 0;
	} else {
		b = 255;
		g = 100;
	}
	//	b = 0;
	//	g = 0;


	if(CVARS.drawon)
	{

	// triangle derecho
	ZN10cHexagonal16DrawFillTriangleEiiiiiiiiii(
      
						_www + _xxx-55-10,
						_yyy + 1,
						_xxx-55-10 + _www,
						_yyy + _hhh - 1,
						_xxx-55-10 + _www + 9,
						_hhh / 2 + _yyy,
						//
						0, g, b, a);


	//
	// rectangle PART1
	ZN10cHexagonal40DrawFillRectangleWithGradientRightToLeftEiiiiiiiiiiii(
      
						_xxx-55-10,
						_yyy + 1,
						/*_www*/firstwidth,
						_hhh - 1,
						//
						255,
						0,
						0,
						200,
						//
						0,
						100,
						255,
						200);

	// rectangle PART2
	Z8FillRGBAiiiihhhh(

						//
						(_xxx-55-10)+firstwidth,
						_yyy + 1,
						/*_www*/secondwidth+fix,
						_hhh - 1,
						//
						0, 0, 0, 200);


	}

	if( i == menuSelect )// selected
	{

	g_Xblackpart = (_xxx-55-10)+firstwidth;
	g_Wblackpart = secondwidth+fix;

	}
}

//-------------------------------------------------------------------//

void cMenu::DrawItem_INT(int i, float _xxx, float _yyy, float _www, float _hhh, int r, int g, int b, int a)
{
	//
	float divisions = (fabs(menuEntry[i].imax)/menuEntry[i].istep);// FIX: usar divisions !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//
	float currval = fabs(menuEntry[i].ivalue[0]);

	float percent = (currval*100/fabs(menuEntry[i].imax));
	float firstwidth = (_www*percent/100);

	float secondwidth = _www - firstwidth;

/*	if( i == menuSelect )// selected
	{

		DrawConString (100, 360, 0, 255, 0, "max %d\0", fabs(menuEntry[i].imax));
		DrawConString (100, 380, 0, 255, 0, "step %d\0", menuEntry[i].istep);
		DrawConString (100, 400, 0, 255, 0, "divisions %f\0", divisions);
		DrawConString (100, 420, 0, 255, 0, "currval %f\0", currval);
		DrawConString (100, 440, 0, 255, 0, "percent %f\0", percent);
		DrawConString (100, 460, 0, 255, 0, "firstwidth %f\0", firstwidth);
		DrawConString (100, 480, 0, 255, 0, "secondwidth %f\0", secondwidth);
		DrawConString (100, 500, 0, 255, 0, "w1 y w2: %f %f\0", _www, (firstwidth+secondwidth));
	}*/


	float fix = 0;
/*	if((firstwidth+secondwidth) != _www)
	{
		//	fix = (_www - (firstwidth+secondwidth));
		//	fix = 1;

		DrawConString (100, 520, 0, 255, 0, "DIFERENT!\0");
	}*/


	if((secondwidth) >0)
	{
		//	fix = 1;
	}

	if( i == menuSelect )// selected
	{
		//	DrawConString (200, 500, 0, 255, 0, "%d %f %f (%f|%f)\0", _www, firstwidth, secondwidth, (firstwidth+secondwidth), fix);

		//	DrawConString (200, 500, 0, 255, 0, "FIXES: %f %f\0", fix, desacum2);
	}

	a = 200;
	//

	if(CVARS.drawon)
	{

	// triangle izq
	ZN10cHexagonal16DrawFillTriangleEiiiiiiiiii(
					
							_xxx-55-10, 
							_yyy + 1, 
							_xxx-55-10, 
							_yyy + _hhh - 1, 
							_xxx-55-10 - 9, 
							_hhh / 2 + _yyy,
							//
							255, 0, 0, a);

	}


	//
	
	if(firstwidth <_www){
		b = 0;
		g = 0;
	} else {
		b = 255;
		g = 100;
	}
	//	b = 0;
	//	g = 0;


	if(CVARS.drawon)
	{

	// triangle derecho
	ZN10cHexagonal16DrawFillTriangleEiiiiiiiiii(
      
						_www + _xxx-55-10,
						_yyy + 1,
						_xxx-55-10 + _www,
						_yyy + _hhh - 1,
						_xxx-55-10 + _www + 9,
						_hhh / 2 + _yyy,
						//
						0, g, b, a);


	//
	// rectangle PART1
	ZN10cHexagonal40DrawFillRectangleWithGradientRightToLeftEiiiiiiiiiiii(
      
						_xxx-55-10,
						_yyy + 1,
						/*_www*/firstwidth,
						_hhh - 1,
						//
						255,
						0,
						0,
						200,
						//
						0,
						100,
						255,
						200);

	// rectangle PART2
	Z8FillRGBAiiiihhhh(

						//
						(_xxx-55-10)+firstwidth,
						_yyy + 1,
						/*_www*/secondwidth+fix,
						_hhh - 1,
						//
						0, 0, 0, 200);


	}

	if( i == menuSelect )// selected
	{

	g_Xblackpart = (_xxx-55-10)+firstwidth;
	g_Wblackpart = secondwidth+fix;

	}
}

//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//

void cMenu::Draw2(int iWidth, int iHeight)
{
	//

	if(!Active) return;
	oglSubtractive = true;

	/////////////////////////////////////////////

	float _x = iWidth - 320 + CVARS.menu_cat2_sub1 + CVARS.menux;
	float _y = 80 + CVARS.menu_cat2_sub2 + CVARS.menuy;
	float _w = CVARS.menu_cat2_sub3;
	float _h = CVARS.menu_cat2_sub4;

	if(CVARS.drawon)
	{

	ZN10cHexagonal36DrawFillTriangleWithGradientUpToDownEiiiiiiiiiiiiii(
    
		_x,
    	_y + 1,
    	_x - 9,
    	_h / 2 + _y,
    	_x,
    	_y + _h - 1,
		//
    	0,
    	0,
    	0,
    	255,
    	CVARS.menu_cat3_sub1,
    	CVARS.menu_cat3_sub2,
    	CVARS.menu_cat3_sub3,
    	CVARS.menu_cat3_sub4);
  
	ZN10cHexagonal36DrawFillTriangleWithGradientUpToDownEiiiiiiiiiiiiii(
    	
		_w + _x,
    	_y + 1,
    	_x + _w + 9,
    	_h / 2 + _y,
    	_x + _w,
    	_y + _h- 1,
    	0,
    	0,
    	0,
    	255,
    	CVARS.menu_cat3_sub1,
    	CVARS.menu_cat3_sub2,
    	CVARS.menu_cat3_sub3,
    	CVARS.menu_cat3_sub4);

		
	ZN10cHexagonal37DrawFillRectangleWithGradientUpToDownEiiiiiiiiiiii(
		_x,
    	_y + 1,
    	_w,
    	_h - 1,
		//
    	0,
    	0,
    	0,
    	255,
    	CVARS.menu_cat3_sub1,
    	CVARS.menu_cat3_sub2,
    	CVARS.menu_cat3_sub3,
    	CVARS.menu_cat3_sub4);


	//

	// línea de arriba horizontal
	ZN10cHexagonal8DrawLineEiiiiiiii(
			
			_x - 8, 
			_h / 2 + _y, 
			_x - 20, 
			_h / 2 + _y, 
			//
			CVARS.menu_cat3_sub1,
    		CVARS.menu_cat3_sub2,
    		CVARS.menu_cat3_sub3,
    		CVARS.menu_cat3_sub4);

	}

	//

	if(CVARS.drawon)
	{

	DrawConString ((_x + 48)+CVARS.menu_cat2_sub8-36, _y-1+CVARS.menu_cat2_sub9, 255, 255, 255, 
		
//	/*STEAMWALL V1\0*/XorStr<0x12,14,0x22F6C99B>("\x41\x47\x51\x54\x5B\x40\x59\x55\x56\x3B\x4A\x2C\x1E"+0x22F6C99B).s

/*STEAMWALL V2\0*/XorStr<0xA5,14,0x106F5A03>("\xF6\xF2\xE2\xE9\xE4\xFD\xEA\xE0\xE1\x8E\xF9\x82\xB1"+0x106F5A03).s



		);

	//"Santiago C  neo Hook V1\0"
//	gEngfuncs.pfnDrawUnicodeCharacter( ((_x + 48)+CVARS.menu_cat2_sub8)+42, (_y-1+CVARS.menu_cat2_sub9)-2, 0xFA, 255,255,255, 2 );

	}

	//

	float paralela_izq_x = (_x - 20);
	float paralela_izq_y = (_h / 2 + _y);

	float paralela_dere_x = 0;
	float paralela_dere_y = 0;

	//

	float heightenginefont = 10;
	float separation = 1 + CVARS.menu_cat2_sub5;
	float _xxx = _x + 55;
	float _yyy = _y + _h + separation;
	float _www = CVARS.menu_cat2_sub3;
	float _hhh = CVARS.menu_cat2_sub4;

	int nuevo_alpha = 0;

	int otro_r = 0;
	int otro_g = 0;
	int otro_b = 0;
	int otro_alpha = 0;

	//
//	int www = 100;





/*	if(menuSelect>menuItems)
	{
		menuSelect = menuCurrentCat;
	}*/

	if(sendOpen)
	{
		sendOpen=false;
		menuSelect = menuCurrentCat;
	}
	if(sendClose)
	{ 
		sendClose=false;
//		menuSelect = menuCurrentCat;

		if(menuCurrentCat && menuSelect>menuCurrentCat)
			menuSelect = menuCurrentCat;
	}

	//
/*	DrawHudString(60, 150, 0, 0, 0, "paralela_izq_x %d,  paralela_izq_y %d\0", paralela_izq_x,  paralela_izq_y);
	DrawHudString(60, 170, 0, 0, 0, "paralela_dere_x %d,  paralela_dere_y %d\0", paralela_dere_x,  paralela_dere_y);
	DrawHudString(60, 190, 0, 0, 0, "menuItems %d\0", menuItems);
	DrawHudString(60, 210, 0, 0, 0, "menuSelect %d\0", menuSelect);
	DrawHudString(60, 230, 0, 0, 0, "menuCurrentCat %d\0", menuCurrentCat);
	//

	DrawHudString(60, 250, 0, 0, 0, "MENUTITLES: %d %d %d %d %d %d %d %d\0", 
		
		CVARS.menutitle1, CVARS.menutitle2, CVARS.menutitle3, CVARS.menutitle4, 
		CVARS.menutitle5, CVARS.menutitle6, CVARS.menutitle7, CVARS.menutitle8);


*/


	for(unsigned int i=1;i<=menuItems;i++)
	{
	//	www+=20;

		// categorias
		if(menuEntry[i].isCat)
		{
			nuevo_alpha = 200;
			//

			if(CVARS.drawon)
			{

			// triangle izq
			ZN10cHexagonal16DrawFillTriangleEiiiiiiiiii(
				
					_xxx-55-10, 
					_yyy + 1, 
					_xxx-55-10, 
					_yyy + _hhh - 1, 
					_xxx-55-10 - 9, 
					_hhh / 2 + _yyy,
					//
					64, 64, 64, nuevo_alpha);

			// triangle derecho
			ZN10cHexagonal16DrawFillTriangleEiiiiiiiiii(
      
				_www + _xxx-55-10,
				_yyy + 1,
				_xxx-55-10 + _www,
				_yyy + _hhh - 1,
				_xxx-55-10 + _www + 9,
				_hhh / 2 + _yyy,
				//
				64, 64, 64, nuevo_alpha);

			//
			Z8FillRGBAiiiihhhh(

				//
				_xxx-55-10,
				_yyy + 1,
				_www,
				_hhh - 1,
				//
				64, 64, 64, 200
			);


			}
		}
		else // items
		{
			if(menuEntry[i].flotating)
			{
				if ( fabs(*(float*)menuEntry[i].fvalue) == 0 )
				{
					nuevo_alpha = 255;
					//


					if(CVARS.drawon)
					{

					// triangle izq
					ZN10cHexagonal16DrawFillTriangleEiiiiiiiiii(
							
							_xxx-55-10, 
							_yyy + 1, 
							_xxx-55-10, 
							_yyy + _hhh - 1, 
							_xxx-55-10 - 9, 
							_hhh / 2 + _yyy,
							//
							0, 0, 0, nuevo_alpha);

					// triangle derecho
					ZN10cHexagonal16DrawFillTriangleEiiiiiiiiii(
      
						_www + _xxx-55-10,
						_yyy + 1,
						_xxx-55-10 + _www,
						_yyy + _hhh - 1,
						_xxx-55-10 + _www + 9,
						_hhh / 2 + _yyy,
						//
						0, 0, 0, nuevo_alpha);


					Z8FillRGBAiiiihhhh(

						//
						_xxx-55-10,
						_yyy + 1,
						_www,
						_hhh - 1,
						//
						0, 0, 0, 200
					);

					}
				}
				else
				{
				DrawItem_FLOAT(i,_xxx, _yyy, _www, _hhh, 255, otro_g, otro_b, nuevo_alpha);
				}
			}
			else
			{
				if ( abs(*(int*)menuEntry[i].ivalue) == 0 )
				{
					nuevo_alpha = 255;
					//


					if(CVARS.drawon)
					{

					// triangle izq
					ZN10cHexagonal16DrawFillTriangleEiiiiiiiiii(
							
							_xxx-55-10, 
							_yyy + 1, 
							_xxx-55-10, 
							_yyy + _hhh - 1, 
							_xxx-55-10 - 9, 
							_hhh / 2 + _yyy,
							//
							0, 0, 0, nuevo_alpha);

					// triangle derecho
					ZN10cHexagonal16DrawFillTriangleEiiiiiiiiii(
      
						_www + _xxx-55-10,
						_yyy + 1,
						_xxx-55-10 + _www,
						_yyy + _hhh - 1,
						_xxx-55-10 + _www + 9,
						_hhh / 2 + _yyy,
						//
						0, 0, 0, nuevo_alpha);


					Z8FillRGBAiiiihhhh(

						//
						_xxx-55-10,
						_yyy + 1,
						_www,
						_hhh - 1,
						//
						0, 0, 0, 200
					);


					}
				}
				else
				{
				DrawItem_INT(i,_xxx, _yyy, _www, _hhh, 255, otro_g, otro_b, nuevo_alpha);
				}
			}
		}

		//

		if( i == menuSelect )// selected
		{
			if(CVARS.drawon)
			{

			if(menuEntry[i].isCat)
			{
				DrawConString (_xxx+10-55-15+CVARS.menu_cat2_sub6, _yyy-2+CVARS.menu_cat2_sub7, 0, 255, 0, /*%s\0*/XorStr<0x3A,4,0x75D3ABB4>("\x1F\x48\x3C"+0x75D3ABB4).s
					, menuEntry[i].title);
			}
			else
			{
				if(menuEntry[i].flotating)//%0.2f
				{
					DrawConString (_xxx+10-55-15+CVARS.menu_cat2_sub6, _yyy-2+CVARS.menu_cat2_sub7, 0, 255, 0, 
						
					//	/*%s %0.2f\0*/XorStr<0x59,10,0x694E6ABD>("\x7C\x29\x7B\x79\x6D\x70\x6D\x06\x61"+0x694E6ABD).s
						/*%s %0.4f\0*/XorStr<0xFF,10,0x3C1048C6>("\xDA\x73\x21\x27\x33\x2A\x31\x60\x07"+0x3C1048C6).s
						, menuEntry[i].title, *(float*)menuEntry[i].fvalue);
				}
				else
				{

					DrawConString (_xxx+10-55-15+CVARS.menu_cat2_sub6, _yyy-2+CVARS.menu_cat2_sub7, 0, 255, 0, /*%s %d\0*/XorStr<0xE8,7,0xD8D20B01>("\xCD\x9A\xCA\xCE\x88\xED"+0xD8D20B01).s
						, menuEntry[i].title, *(int*)menuEntry[i].ivalue);

				}
			}

			}

			//

			int arrangement = 4;


			if(CVARS.drawon)
			{

			// izq
			ZN10cHexagonal8DrawLineEiiiiiiii(
			
					(_xxx-55-10) - 8, 
					_hhh / 2 + (_yyy /*+ 1*/), 
					(_xxx-55-10) - 20 -arrangement, 
					_hhh / 2 + (_yyy /*+ 1*/), 
					//
					CVARS.menu_cat3_sub1,
    				CVARS.menu_cat3_sub2,
    				CVARS.menu_cat3_sub3,
    				CVARS.menu_cat3_sub4);

			//

			// paralela izq (punto a punto)
			ZN10cHexagonal8DrawLineEiiiiiiii(
					
					paralela_izq_x, 
					paralela_izq_y, 
					(_xxx-55-10) - 20 -arrangement, 
					_hhh / 2 + (_yyy /*+ 1*/), 
					//
					CVARS.menu_cat3_sub1,
    				CVARS.menu_cat3_sub2,
    				CVARS.menu_cat3_sub3,
    				CVARS.menu_cat3_sub4);

			//

			// dere
			ZN10cHexagonal8DrawLineEiiiiiiii(
			
				(_xxx-55-10) + _www + 8,
				//
				_hhh / 2 + (_yyy /*+ 1*/), 
				//
				(_xxx-55-10) + _www + 20 +arrangement, //paralela_dere_x
				//
				_hhh / 2 + (_yyy /*+ 1*/), //paralela_dere_y
				//
				CVARS.menu_cat3_sub1,
    			CVARS.menu_cat3_sub2,
    			CVARS.menu_cat3_sub3,
    			CVARS.menu_cat3_sub4);

			}

			//

			paralela_dere_x = ((_xxx-55-10) + _www + 20 +arrangement);
			paralela_dere_y = (_hhh / 2 + (_yyy /*+ 1*/));

		}
		else // NOT SELECTED
		{
			if(CVARS.drawon)
			{


			if(menuEntry[i].isCat)
			{
				DrawConString (_xxx+10-55-15+CVARS.menu_cat2_sub6, _yyy-2+CVARS.menu_cat2_sub7, 255,127,80, /*%s\0*/XorStr<0x34,4,0x885399CA>("\x11\x46\x36"+0x885399CA).s
					, menuEntry[i].title);
			}
			else
			{
				if(menuEntry[i].flotating)//%0.2f
				{
					DrawConString (_xxx+10-55-15+CVARS.menu_cat2_sub6, _yyy-2+CVARS.menu_cat2_sub7, 255, 255, 255, 
						
					//	/*%s %0.2f\0*/XorStr<0x7B,10,0x4E33722E>("\x5E\x0F\x5D\x5B\x4F\xAE\xB3\xE4\x83"+0x4E33722E).s
						/*%s %0.4f\0*/XorStr<0xFF,10,0x3C1048C6>("\xDA\x73\x21\x27\x33\x2A\x31\x60\x07"+0x3C1048C6).s

						, menuEntry[i].title, *(float*)menuEntry[i].fvalue);
				}
				else
				{

					DrawConString (_xxx+10-55-15+CVARS.menu_cat2_sub6, _yyy-2+CVARS.menu_cat2_sub7, 255, 255, 255, /*%s %d\0*/XorStr<0xF3,7,0x51BCF4D1>("\xD6\x87\xD5\xD3\x93\xF8"+0x51BCF4D1).s
						, menuEntry[i].title, *(int*)menuEntry[i].ivalue);

				}
			}

			}



		}// end NOT SELECTED items

		_xxx -= 10;
		_yyy += _hhh + separation;

	}// end FOR items

	//

	float _xx = _xxx-55-10;
	float _yy = _yyy;
	float _ww = CVARS.menu_cat2_sub3;
	float _hh = CVARS.menu_cat2_sub4;


	if(CVARS.drawon)
	{

	ZN10cHexagonal36DrawFillTriangleWithGradientUpToDownEiiiiiiiiiiiiii(
		_xx,
    	_yy + 1,
    	_xx - 9,
    	_hh / 2 + _yy,
    	_xx,
    	_yy + _hh - 1,
    	CVARS.menu_cat3_sub1,
    	CVARS.menu_cat3_sub2,
    	CVARS.menu_cat3_sub3,
    	CVARS.menu_cat3_sub4,
    	0,
    	0,
    	0,
    	0xFFu);

  
	ZN10cHexagonal36DrawFillTriangleWithGradientUpToDownEiiiiiiiiiiiiii(
    	
		_ww + _xx,
    	_yy + 1,
    	_xx + _ww + 9,
    	_hh / 2 + _yy,
    	_xx + _ww,
    	_yy + _hh - 1,
    	CVARS.menu_cat3_sub1,
    	CVARS.menu_cat3_sub2,
    	CVARS.menu_cat3_sub3,
    	CVARS.menu_cat3_sub4,
    	0,
    	0,
    	0,
    	0xFFu);

  
	ZN10cHexagonal37DrawFillRectangleWithGradientUpToDownEiiiiiiiiiiii(
    
		_xx,
    	_yy + 1,
    	_ww,
    	_hh - 1,
    	CVARS.menu_cat3_sub1,
    	CVARS.menu_cat3_sub2,
    	CVARS.menu_cat3_sub3,
    	CVARS.menu_cat3_sub4,
    	0,
    	0,
    	0,
    	0xFFu);

	//

	ZN10cHexagonal8DrawLineEiiiiiiii(
			
		_xx + _ww + 8,// empieza x
		//
		_hh / 2 + _yy,// empieza y 
		//
		_xx + _ww + 20,// termina x
		//
		_hh / 2 + _yy,// termina y 
		//
		CVARS.menu_cat3_sub1,
    	CVARS.menu_cat3_sub2,
    	CVARS.menu_cat3_sub3,
    	CVARS.menu_cat3_sub4);

	//

	// paralela dere (punto a punto)
	ZN10cHexagonal8DrawLineEiiiiiiii(
					
			paralela_dere_x, 
			paralela_dere_y, 
			(_xx + _ww + 20), 
			(_hh / 2 + _yy), 
			//
			CVARS.menu_cat3_sub1,
    		CVARS.menu_cat3_sub2,
    		CVARS.menu_cat3_sub3,
    		CVARS.menu_cat3_sub4);

	}

	/////////////////////////////////////////////

	oglSubtractive = false;

}

//-------------------------------------------------------------------//
