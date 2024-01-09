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

struct ControlVariables_s
{

	int hackon;
	int drawon;

	int info;



	int menukey;

	int menu_cat2_sub1;
	int menu_cat2_sub2;
	int menu_cat2_sub3;
	int menu_cat2_sub4;
	int menu_cat2_sub5;
	int menu_cat2_sub6;
	int menu_cat2_sub7;
	int menu_cat2_sub8;
	int menu_cat2_sub9;
	int menu_cat2_sub10;

	float menu_cat3_sub1;
	float menu_cat3_sub2;
	float menu_cat3_sub3;
	float menu_cat3_sub4;


	float menutitle1;
	float menutitle2;
	float menutitle3;
	float menutitle4;
	float menutitle5;
	float menutitle6;
	float menutitle7;
	float menutitle8;
	float menutitle9;
	float menutitle10;


	int dummy;

	int menux;
	int menuy;

	int testx1;
	int testx2;
	int testx3;
	int testx4;


	//

	int antiss;
	int memess;

	int sstoblue;

	float ss_interval;//1
	int ss_cleanframes;

	float sndtime;

	int seess;
	int testss;

	int antifb;

	int sndpickup;

	//

	int myhud;

	int codeshut;
};

//-------------------------------------------------------------------//

extern struct ControlVariables_s CVARS;

//-------------------------------------------------------------------//

void InitControlVariables();

//-------------------------------------------------------------------//
