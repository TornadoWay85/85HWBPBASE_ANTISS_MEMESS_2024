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

struct ControlVariables_s CVARS;

//-------------------------------------------------------------------//

void InitControlVariables()
{
	CVARS.hackon=1;
	CVARS.drawon=1;


	CVARS.info=1;
	CVARS.myhud=1;


	CVARS.menukey=147;

	CVARS.menu_cat2_sub1=69;
	CVARS.menu_cat2_sub2=50;//126
	CVARS.menu_cat2_sub3=201;//181
	CVARS.menu_cat2_sub4=18;
	CVARS.menu_cat2_sub5=-1;
	CVARS.menu_cat2_sub6=0;
	CVARS.menu_cat2_sub7=0;
	CVARS.menu_cat2_sub8=0;
	CVARS.menu_cat2_sub9=0;

	CVARS.menu_cat3_sub1=0.00f;
	CVARS.menu_cat3_sub2=0.00f;
	CVARS.menu_cat3_sub3=255.00f;
	CVARS.menu_cat3_sub4=255.00f;

	CVARS.menutitle1=0.00;
	CVARS.menutitle2=0.00;
	CVARS.menutitle3=0.00;
	CVARS.menutitle4=0.00;
	CVARS.menutitle5=0.00;
	CVARS.menutitle6=0.00;
	CVARS.menutitle7=0.00;
	CVARS.menutitle8=0.00;
	CVARS.menutitle9=0.00;
	CVARS.menutitle10=0.00;


	CVARS.dummy=0;


	CVARS.menux=-15;
	CVARS.menuy=-90;


	CVARS.testx1=0;
	CVARS.testx2=0;
	CVARS.testx3=0;
	CVARS.testx4=0;



	CVARS.antiss=1;
	CVARS.memess=0;

	CVARS.sstoblue = 0;

	CVARS.ss_interval = 1;//60
	CVARS.ss_cleanframes = 3;

	CVARS.sndtime = 0.3;

	CVARS.seess = 0;
	CVARS.testss = 0;

	CVARS.antifb = 1;

	CVARS.sndpickup = 1;

	//

	CVARS.myhud = 1;
	CVARS.codeshut = 0;

}

//-------------------------------------------------------------------//






