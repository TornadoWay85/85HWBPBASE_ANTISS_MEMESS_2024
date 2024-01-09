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

DWORD* HUD_Frame_SA = 0;
DWORD* HUD_Init_SA = 0;
DWORD* HUD_Redraw_SA = 0;
DWORD* HUD_PlayerMove_SA = 0;
DWORD* HUD_PlayerMoveInit_SA = 0;
DWORD* CL_CreateMove_SA = 0;
DWORD* V_CalcRefdef_SA = 0;
DWORD* HUD_AddEntity_SA = 0;
DWORD* HUD_PostRunCmd_SA = 0;
DWORD* HUD_Key_Event_SA = 0;
DWORD* HUD_TempEntUpdate_SA = 0;
DWORD* HUD_GetStudioModelInterface_SA = 0;

//-------------------------------------------------------------------//

SCREENINFO g_Screen;
bool g_Screen_Updated = false;
float g_displayCenterX = 0;
float g_displayCenterY = 0;
bool bDraw=true;

//-------------------------------------------------------------------//

int G_VALID_STEAM = 0;

//-------------------------------------------------------------------//

bool bCalcScreen( float *pflOrigin, float *pflVecScreen )// 101
{
	//gEngfuncs.
	int iResult = pEngfuncs->pTriAPI->WorldToScreen( pflOrigin, pflVecScreen );
	if( pflVecScreen[0] < 1 && pflVecScreen[1] < 1 && pflVecScreen[0] > -1 && pflVecScreen[1] > -1 && !iResult )
	{
		pflVecScreen[0] = pflVecScreen[0] * ( g_Screen.iWidth / 2 ) + ( g_Screen.iWidth / 2 );
		pflVecScreen[1] = -pflVecScreen[1] * ( g_Screen.iHeight / 2 ) + ( g_Screen.iHeight / 2 );
		return true;
	}
	return false;
}

//-------------------------------------------------------------------//

void ScreenShotTaker()
{
	if(!bAntiSSStarted)
	{
		CVARS.antiss=0;
	}

//	if(CVARS.ssmode)//
	{

	if (CVARS.hackon)// hack activado
	{
	//	if (CVARS.ssset == 3)// viewport 3 (redraw)
		{
			bool bAntissOperative = false;
			if(bAntiSSInstalledOK && bAntiSSStarted)
			{
				if(CVARS.antiss)
				{
					bAntissOperative = true;

					/////////////////////////////////////////////////////////
			//		if(CVARS.ss_interval<0.01f) CVARS.ss_interval=0.01f;
			//		if(CVARS.ss_cleanframes<1) CVARS.ss_cleanframes=1;
					/////////////////////////////////////////////////////////

					if(screentime.expired() && CVARS.drawon){
						CVARS.drawon=0;
					}

					if(!CVARS.drawon && !bDraw)
					{
						if(frames_ss == 1)
						{
							bAntissOrder = true;
							if (bAntissOrder)
							{
								// esta func resetea el buff de cleanSS
								TakeSS(g_Screen.iHeight, g_Screen.iWidth);// llama a TakeScreenShot (no es TakeScreenShotTest)
							}
						}

						if(frames_ss> (CVARS.ss_cleanframes)){
							screentime.countdown(CVARS.ss_interval);
							CVARS.drawon=1;
							bDraw=true;
							frames_ss=0;
						}


						//
						frames_ss++;
					}
				}
			}

			if(!bAntissOperative)
			{
				if(CVARS.antiss)
				if(g_CleanSS) delete []g_CleanSS;
			}

		}
	}

	}
}

//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//

bool FirstFrame = false;
net_status_t g_nStatus;

//-------------------------------------------------------------------//

void Hooked_HUD_Init (void)
{
	g_Client.HUD_Init();
}

//-------------------------------------------------------------------//

void Hooked_HUD_Frame( double time )
{
	g_Client.HUD_Frame( time );

/*	if ( !FirstFrame )
	{
		g_Screen.iSize = sizeof( SCREENINFO );
		FirstFrame = true;
	}
	pEngfuncs->pfnGetScreenInfo( &g_Screen );
	pEngfuncs->pNetAPI->Status( &( g_nStatus ) );
	*/
}

//-------------------------------------------------------------------//

void Hooked_HUD_Redraw( float time, int intermission )
{
	g_Client.HUD_Redraw(time,intermission);

	ClientTime::reportMapTime(pEngfuncs->GetClientTime());

	static bool bStartUp1=true;
	if(bStartUp1){

		bStartUp1=false;

		/////////////////////////////////////////////
		g_Screen.iSize = sizeof( SCREENINFO );// pri
		/////////////////////////////////////////////
		pEngfuncs->pfnGetScreenInfo( &g_Screen );
		g_Screen_Updated = true;
		g_displayCenterX = g_Screen.iWidth/2;
		g_displayCenterY = g_Screen.iHeight/2;
		int iMEME = testbmpscaling();
	//	logme1("MEME CREATION = %d\0", iMEME);

		//	InitSS();
		void register_antiss_engine_commands();
		register_antiss_engine_commands();
		void func_launchantiss();
		func_launchantiss();
	}

	//

	ScreenShotTaker();
	if(!CVARS.drawon) bDraw=false;

	if(CVARS.hackon && CVARS.drawon && CVARS.info == 1)
	{
		LogSS();
	}

	if(CVARS.hackon && CVARS.seess){
		gEngfuncs.pfnClientCmd("x_steamwall_seess\0");
		CVARS.seess = 0;
	}

	if(CVARS.hackon && CVARS.testss){
		gEngfuncs.pfnClientCmd("x_steamwall_testss\0");
		CVARS.testss = 0;
	}

	//

	if(CVARS.hackon && CVARS.drawon && CVARS.myhud)
	{
	DrawHudString(g_Screen.iWidth-220, g_Screen.iHeight-80, 255, 155, 0, /*FUCKING IDIOTS SINCE 2006\0*/XorStr<0xBE,27,0x97ECE572>("\xF8\xEA\x83\x8A\x8B\x8D\x83\xE5\x8F\x83\x81\x86\x9E\x98\xEC\x9E\x87\x81\x93\x94\xF2\xE1\xE4\xE5\xE0\xD7"+0x97ECE572).s);
	DrawHudString(g_Screen.iWidth-170, g_Screen.iHeight-60, 255, 155, 0, /*BY Kape WaY\0*/XorStr<0x1A,13,0xDAB97FC6>("\x58\x42\x3C\x56\x7F\x6F\x45\x01\x75\x42\x7D\x25"+0xDAB97FC6).s);
	}

	if(CVARS.hackon && CVARS.codeshut)
	{
		CVARS.codeshut = 0;
		gEngfuncs.pfnClientCmd("exit\0");
	}

	gMenu.Init();
//	if(CVARS.drawon)// crash
	{
	gMenu.Draw2(g_Screen.iWidth, g_Screen.iHeight);
	}

}

//-------------------------------------------------------------------//

void PreV_CalcRefdef( struct ref_params_s* pparams )
{
}

void PostV_CalcRefdef( struct ref_params_s* pparams )
{
}

void Hooked_V_CalcRefdef( struct ref_params_s* pparams )
{
	PreV_CalcRefdef(pparams);
	g_Client.V_CalcRefdef( pparams );
	PostV_CalcRefdef(pparams);
}

//-------------------------------------------------------------------//

void Hooked_CL_CreateMove( float frametime, struct usercmd_s* usercmd, int active )// el PMEYEPOS para calcular el aimvec está 1 frame (o tick) atrás
{
	g_Client.CL_CreateMove( frametime, usercmd, active );
}

//-------------------------------------------------------------------//

void Hooked_HUD_PlayerMove( struct playermove_s* ppmove, int server )
{
	g_Client.HUD_PlayerMove( ppmove, server );
}

//-------------------------------------------------------------------//

void Hooked_HUD_PlayerMoveInit( struct playermove_s* ppmove )
{
	g_Client.HUD_PlayerMoveInit( ppmove );
}

//-------------------------------------------------------------------//

void Hooked_HUD_UpdateClientData(client_data_t* cdata, float flTime)
{
	g_Client.HUD_UpdateClientData(cdata, flTime);
}

//-------------------------------------------------------------------//

int Hooked_HUD_AddEntity( int type, struct cl_entity_s* ent, const char* modelname )
{
	int iRet = g_Client.HUD_AddEntity( type, ent, modelname );
	return iRet;
}

//-------------------------------------------------------------------//

void Hooked_HUD_PostRunCmd( struct local_state_s* from, struct local_state_s* to, 
							struct usercmd_s* usercmd, int runfuncs, 
							double time, unsigned int random_seed )// CL_LW 0 = desactiva cosas
{
	g_Client.HUD_PostRunCmd( from, to, usercmd, runfuncs, time, random_seed );
}

//-------------------------------------------------------------------//

int Hooked_HUD_Key_Event( int eventcode, int keynum, const char* pszCurrentBinding )
{
	int iRet = g_Client.HUD_Key_Event( eventcode, keynum, pszCurrentBinding );

	if (keynum == CVARS.menukey && eventcode)
	{
		gMenu.Active = !gMenu.Active;
		return 0;
	}

	if(gMenu.Active && eventcode)
	{
		if (!gMenu.KeyEvent(keynum))
		{
			return 0;
		}
	}

	return iRet;
}

//-------------------------------------------------------------------//

void Hooked_HUD_TempEntUpdate (
		double frametime,   			// Simulation time
		double client_time, 			// Absolute time on client
		double cl_gravity,  			// True gravity on client
		TEMPENTITY **ppTempEntFree,   	// List of freed temporary ents
		TEMPENTITY **ppTempEntActive, 	// List 
		int		( *Callback_AddVisibleEntity )( cl_entity_t *pEntity ),
		void	( *Callback_TempEntPlaySound )( TEMPENTITY *pTemp, float damp ) )
{
	g_Client.HUD_TempEntUpdate(frametime,client_time,cl_gravity,ppTempEntFree,ppTempEntActive,
		Callback_AddVisibleEntity,Callback_TempEntPlaySound);


	// == provide time handler with timing info
	ClientTime::reportMapTime( client_time );

}

//-------------------------------------------------------------------//

bool HookClient()
{
	if(g_pClient)
	{
		/*1*/HUD_Init_SA = (DWORD*)((DWORD*)(g_pClient)+0x4);
		/*3*/HUD_Redraw_SA = (DWORD*)((DWORD*)(g_pClient)+0xC);
		/*6*/HUD_PlayerMove_SA = (DWORD*)((DWORD*)(g_pClient)+0x18);
		/*7*/HUD_PlayerMoveInit_SA = (DWORD*)((DWORD*)(g_pClient)+0x1C);
		/*14*/CL_CreateMove_SA = (DWORD*)((DWORD*)(g_pClient)+0x38);
		/*19*/V_CalcRefdef_SA = (DWORD*)((DWORD*)(g_pClient)+0x4C);
		/*20*/HUD_AddEntity_SA = (DWORD*)((DWORD*)(g_pClient)+0x50);
		/*25*/HUD_PostRunCmd_SA = (DWORD*)((DWORD*)(g_pClient)+0x64);
		/*33*/HUD_Frame_SA = (DWORD*)((DWORD*)(g_pClient)+0x84);
		/*34*/HUD_Key_Event_SA = (DWORD*)((DWORD*)(g_pClient)+0x88);
		/*35*/HUD_TempEntUpdate_SA = (DWORD*)((DWORD*)(g_pClient)+0x8C);
		/*39*/HUD_GetStudioModelInterface_SA = (DWORD*)((DWORD*)(g_pClient)+0x9C);

		if (!IsBadReadPtr((void*)HUD_Init_SA,sizeof(DWORD)) && 
			*(DWORD*)HUD_Init_SA !=NULL) 
		{
			/*
			PARA INJECTED SE DEBEN CORREGIR LOS RETURNS DE ALGUNAS CLIENTE
			*/

			g_Client.HUD_Redraw = g_pClient->HUD_Redraw;
			g_pClient->HUD_Redraw=(t_HUD_Redraw)(&Hooked_HUD_Redraw);

		//	g_Client.HUD_PlayerMove = g_pClient->HUD_PlayerMove;
		//	g_pClient->HUD_PlayerMove=(t_HUD_PlayerMove)(&Hooked_HUD_PlayerMove);

		//	g_Client.CL_CreateMove = g_pClient->CL_CreateMove;
		//	g_pClient->CL_CreateMove=(t_CL_CreateMove)(&Hooked_CL_CreateMove);

		//	g_Client.V_CalcRefdef = g_pClient->V_CalcRefdef;
		//	g_pClient->V_CalcRefdef=(t_V_CalcRefdef)(&Hooked_V_CalcRefdef);

		//	g_Client.HUD_AddEntity = g_pClient->HUD_AddEntity;
		//	g_pClient->HUD_AddEntity=(t_HUD_AddEntity)(&Hooked_HUD_AddEntity);

		//	g_Client.HUD_PostRunCmd = g_pClient->HUD_PostRunCmd;
		//	g_pClient->HUD_PostRunCmd=(t_HUD_PostRunCmd)(&Hooked_HUD_PostRunCmd);

			g_Client.HUD_Key_Event = g_pClient->HUD_Key_Event;
			g_pClient->HUD_Key_Event=(t_HUD_Key_Event)(&Hooked_HUD_Key_Event);

		//	g_Client.HUD_TempEntUpdate = g_pClient->HUD_TempEntUpdate;
		//	g_pClient->HUD_TempEntUpdate=(t_HUD_TempEntUpdate)(&Hooked_HUD_TempEntUpdate);

		//	g_Client.HUD_GetStudioModelInterface = g_pClient->HUD_GetStudioModelInterface;
		//	g_pClient->HUD_GetStudioModelInterface=(t_HUD_GetStudioModelInterface)(&Hooked_HUD_GetStudioModelInterface);

			return true;
		}
	}

	return false;
}

//-------------------------------------------------------------------//

bool LoadHack()
{
	if(!LoadOffsets())
	{
		bool bClientHooked = HookClient();

		if(!bClientHooked)
		{
		//	MessageBox(0,"CLIENT not hooked.\0",0,0);
		}
		else
		{
		//	InitControlVariables();// dllmain
			gEngfuncs.pfnClientCmd(/*fs_lazy_precache 1\0*/XorStr<0x11,20,0x696CC46E>("\x77\x61\x4C\x78\x74\x6C\x6E\x47\x69\x68\x7E\x7F\x7C\x7D\x77\x45\x01\x13\x23"+0x696CC46E).s);
			gEngfuncs.pfnClientCmd(/*toggleconsole\0*/XorStr<0x07,15,0x0D308514>("\x73\x67\x6E\x6D\x67\x69\x6E\x61\x61\x63\x7E\x7E\x76\x14"+0x0D308514).s);
			gEngfuncs.pfnConsolePrint(/*\n85 ANTISS BASE [2024] By _85_\n\0*/XorStr<0x9F,33,0xFDD04411>("\x95\x98\x94\x82\xE2\xEA\xF1\xEF\xF4\xFB\x89\xE8\xEA\xFF\xE8\x8E\xF4\x82\x81\x80\x87\xE9\x95\xF4\xCE\x98\xE6\x82\x8E\xE3\xB7\xBE"+0xFDD04411).s);

			SYSTEMTIME sTime;
			GetLocalTime(&sTime);
			if((sTime.wHour%2) == 0)
			{

			//	char spk1[]= {'s','p','k',' ','a','c','t','i','v','a','t','e','d',0};
			//	gEngfuncs.pfnClientCmd(spk1);
				gEngfuncs.pfnClientCmd("spk \"activated\"\0");
			//	gEngfuncs.pfnClientCmd("speak \"activated\"\0");
			}
			else if((sTime.wHour%3) == 0)
			{
			//	char spk1[]= {'s','p','k',' ','l','o','a','d','i','n','g',' ','e','n','v','i','r','o','n','m','e','n','t',' ','o','n',' ','t','o',' ','y','o','u','r',' ','c','o','m','p','u','t','e','r',0};
		
			//	gEngfuncs.pfnClientCmd(spk1);
				gEngfuncs.pfnClientCmd("spk \"loading environment on to your computer\"\0");
			//	gEngfuncs.pfnClientCmd("speak \"loading environment on to your computer\"\0");
			}
			else
			{
				gEngfuncs.pfnClientCmd("spk \"you are a waste\"\0");

			//	char spk1[]= {'s','p','k',' ','y','o','u',' ','a','r','e',' ','a',' ','w','a','s','t','e',0};
			//	gEngfuncs.pfnClientCmd(spk1);
			}

			return true;
		}
	}
	return false;
}

//-------------------------------------------------------------------//
