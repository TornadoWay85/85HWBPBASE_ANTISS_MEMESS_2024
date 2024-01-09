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

typedef void (*t_HUD_Frame)( double time );

typedef void (*t_HUD_Init) (void);

typedef void (*t_HUD_Redraw)( float time, int intermission );

typedef void (*t_V_CalcRefdef)( struct ref_params_s* pparams );

typedef void (*t_CL_CreateMove)( float frametime, struct usercmd_s* usercmd, int active );

typedef void (*t_HUD_PlayerMove)( struct playermove_s* ppmove, int server );
typedef void (*t_HUD_PlayerMoveInit)( struct playermove_s *ppmove );

typedef int (*t_HUD_AddEntity)( int type, struct cl_entity_s* ent, const char* modelname );

typedef void (*t_HUD_UpdateClientData)(client_data_t* cdata, float flTime);

typedef void (*t_HUD_PostRunCmd)( struct local_state_s* from, struct local_state_s* to, 
							struct usercmd_s* usercmd, int runfuncs, 
							double time, unsigned int random_seed );

typedef int (*t_HUD_Key_Event)( int eventcode, int keynum, const char* pszCurrentBinding );

typedef void (*t_HUD_TempEntUpdate) (
		double frametime,   			// Simulation time
		double client_time, 			// Absolute time on client
		double cl_gravity,  			// True gravity on client
		TEMPENTITY **ppTempEntFree,   	// List of freed temporary ents
		TEMPENTITY **ppTempEntActive, 	// List 
		int		( *Callback_AddVisibleEntity )( cl_entity_t *pEntity ),
		void	( *Callback_TempEntPlaySound )( TEMPENTITY *pTemp, float damp ) );

typedef void (*t_HUD_VoiceStatus)(int entindex, qboolean bTalking);


typedef int (*t_HUD_GetStudioModelInterface)(int version, struct r_studio_interface_s** ppinterface, 
								 struct engine_studio_api_s* pstudioX);

//-------------------------------------------------------------------//

void Hooked_HUD_Frame( double time );
void Hooked_HUD_Init (void);
void Hooked_HUD_Redraw( float time, int intermission );
void Hooked_V_CalcRefdef( struct ref_params_s* pparams );
void Hooked_CL_CreateMove( float frametime, struct usercmd_s* usercmd, int active );
void Hooked_HUD_PlayerMove( struct playermove_s* ppmove, int server );
void Hooked_HUD_PlayerMoveInit( struct playermove_s* ppmove );
void Hooked_HUD_UpdateClientData(client_data_t* cdata, float flTime);
int Hooked_HUD_AddEntity( int type, struct cl_entity_s* ent, const char* modelname );
void Hooked_HUD_PostRunCmd( struct local_state_s* from, struct local_state_s* to, 
							struct usercmd_s* usercmd, int runfuncs, 
							double time, unsigned int random_seed );
int Hooked_HUD_Key_Event( int eventcode, int keynum, const char* pszCurrentBinding );
void Hooked_HUD_TempEntUpdate (
		double frametime,   			// Simulation time
		double client_time, 			// Absolute time on client
		double cl_gravity,  			// True gravity on client
		TEMPENTITY **ppTempEntFree,   	// List of freed temporary ents
		TEMPENTITY **ppTempEntActive, 	// List 
		int		( *Callback_AddVisibleEntity )( cl_entity_t *pEntity ),
		void	( *Callback_TempEntPlaySound )( TEMPENTITY *pTemp, float damp ) );
int Hooked_HUD_GetStudioModelInterface(int version, struct r_studio_interface_s** ppinterface, 
								 struct engine_studio_api_s* pstudioX);

//-------------------------------------------------------------------//

typedef struct cl_clientfuncs_s
{
	/*0*/int ( *Initialize ) ( cl_enginefunc_t *pEnginefuncs, int iVersion );
	/*1*/void ( *HUD_Init ) ( void ); //int ( *HUD_Init ) ( void );
	/*2*/int ( *HUD_VidInit ) ( void );
	/*3*/void ( *HUD_Redraw ) ( float time, int intermission );
	/*4*/int ( *HUD_UpdateClientData ) ( client_data_t *pcldata, float flTime );
	int ( *HUD_Reset ) ( void );
	/*6*/void ( *HUD_PlayerMove ) ( struct playermove_s *ppmove, int server );
	/*7*/void ( *HUD_PlayerMoveInit ) ( struct playermove_s *ppmove );
	char ( *HUD_PlayerMoveTexture ) ( char *name );
	void ( *IN_ActivateMouse ) ( void );
	void ( *IN_DeactivateMouse ) ( void );
	void ( *IN_MouseEvent ) ( int mstate );
	void ( *IN_ClearStates ) ( void );
	void ( *IN_Accumulate ) ( void );
	/*14*/void ( *CL_CreateMove ) ( float frametime, struct usercmd_s *cmd, int active );
	int ( *CL_IsThirdPerson ) ( void );
	void ( *CL_CameraOffset ) ( float *ofs );
	struct kbutton_s *( *KB_Find ) ( const char *name );
	void ( *CAM_Think ) ( void );
	/*19*/void ( *V_CalcRefdef ) ( struct ref_params_s *pparams );
	/*20*/int ( *HUD_AddEntity ) ( int type, struct cl_entity_s *ent, const char *modelname );
	void ( *HUD_CreateEntities ) ( void );
	void ( *HUD_DrawNormalTriangles ) ( void );
	void ( *HUD_DrawTransparentTriangles ) ( void );
	void ( *HUD_StudioEvent ) ( const struct mstudioevent_s *event, const struct cl_entity_s *entity );
	/*25*/void ( *HUD_PostRunCmd ) ( struct local_state_s *from, struct local_state_s *to, struct usercmd_s *cmd, int runfuncs, double time, unsigned int random_seed );
	void ( *HUD_Shutdown ) ( void );
	void ( *HUD_TxferLocalOverrides ) ( struct entity_state_s *state, const struct clientdata_s *client );
	void ( *HUD_ProcessPlayerState ) ( struct entity_state_s *dst, const struct entity_state_s *src );
	void ( *HUD_TxferPredictionData ) ( struct entity_state_s *ps, const struct entity_state_s *pps, struct clientdata_s *pcd, const struct clientdata_s *ppcd, struct weapon_data_s *wd, const struct weapon_data_s *pwd );
	void ( *Demo_ReadBuffer ) ( int size, unsigned char *buffer );
	int ( *HUD_ConnectionlessPacket ) ( struct netadr_s *net_from, const char *args, char *response_buffer, int *response_buffer_size );
	int ( *HUD_GetHullBounds ) ( int hullnumber, float *mins, float *maxs );
	/*33*/void ( *HUD_Frame ) ( double time );
	/*34*/int ( *HUD_Key_Event ) ( int down, int keynum, const char *pszCurrentBinding );
	/*35*/void ( *HUD_TempEntUpdate ) ( double frametime, double client_time, double cl_gravity, struct tempent_s **ppTempEntFree, struct tempent_s **ppTempEntActive, int ( *Callback_AddVisibleEntity )( struct cl_entity_s *pEntity ), void ( *Callback_TempEntPlaySound )( struct tempent_s *pTemp, float damp ) );
	struct cl_entity_s *( *HUD_GetUserEntity ) ( int index );
	/*37*/int ( *HUD_VoiceStatus ) ( int entindex, qboolean bTalking );
	int ( *HUD_DirectorMessage ) ( unsigned char command, unsigned int firstObject, unsigned int secondObject, unsigned int flags );
	/*39*/int ( *HUD_GetStudioModelInterface ) ( int version, struct r_studio_interface_s **ppinterface, struct engine_studio_api_s *pstudio );
	void ( *HUD_CHATINPUTPOSITION_FUNCTION ) ( int *x, int *y );
	int ( *HUD_GETPLAYERTEAM_FUNCTION ) ( int iplayer );
	void ( *CLIENTFACTORY ) ( void );
} cl_clientfunc_t;

//-------------------------------------------------------------------//

//extern cl_clientfunc_t *g_pClient;
//extern cl_clientfunc_t g_Client;

//-------------------------------------------------------------------//

typedef struct ClientDll_s
{
	/*0*/int		(*Initialize)( cl_enginefunc_t *pEnginefuncs, int iVersion );
	/*1*/void	(*HUD_Init)( void );
	/*2*/int		(*HUD_VidInit)( void );
	/*3*/int		(*HUD_Redraw)( float flTime, int intermission );
	/*4*/int		(*HUD_UpdateClientData)( client_data_t *cdata, float flTime );
	void	(*HUD_Reset) ( void );
	/*6*/void	(*HUD_PlayerMove)( struct playermove_s *ppmove, int server );
	/*7*/void	(*HUD_PlayerMoveInit)( struct playermove_s *ppmove );
	char	(*HUD_PlayerMoveTexture)( char *name );
	void	(*IN_ActivateMouse)( void );
	void	(*IN_DeactivateMouse)( void );
	void	(*IN_MouseEvent)(int mstate);
	void	(*IN_ClearStates)(void);
	void	(*IN_Accumulate)(void);
	/*14*/void	(*CL_CreateMove) ( float frametime, struct usercmd_s *cmd, int active );
	int		(*CL_IsThirdPerson)( void );
	void	(*CL_CameraOffset)( float *ofs );
	struct	kbutton_s* (*KB_Find)( const char *name );
	void	(*CAM_Think)( void );
	/*19*/void	(*V_CalcRefdef)(struct ref_params_s *pparams);
	/*20*/int		(*HUD_AddEntity)(int type, struct cl_entity_s *ent, const char *modelname);
	void	(*HUD_CreateEntities)(void);
	void	(*HUD_DrawNormalTriangles)(void);
	void	(*HUD_DrawTransparentTriangles)(void);
	void	(*HUD_StudioEvent)(const struct mstudioevent_s *, const struct cl_entity_s *);
	/*25*/void	(*HUD_PostRunCmd)( struct local_state_s *from, struct local_state_s *to, struct usercmd_s *cmd, int runfuncs, double time, unsigned int random_seed);
	void	(*HUD_Shutdown)( void );
	void	(*HUD_TxferLocalOverrides)(struct entity_state_s *, const struct clientdata_s *);
	void	(*HUD_ProcessPlayerState)(struct entity_state_s *, const struct entity_state_s *);
	void	(*HUD_TxferPredictionData)(struct entity_state_s *, const struct entity_state_s *, struct clientdata_s *, const struct clientdata_s *, struct weapon_data_s *, const struct weapon_data_s *);
	void	(*Demo_ReadBuffer)(int, unsigned char *);
	int		(*HUD_ConnectionlessPacket)( const struct netadr_s *net_from, const char *args, char *response_buffer, int *response_buffer_size );
	int		(*HUD_GetHullBounds)( int hullnumber, float *mins, float *maxs );
	/*33*/void	(*HUD_Frame)( double time );
	/*34*/int		(*HUD_Key_Event)( int eventcode, int keynum, const char *pszCurrentBinding );
	/*35*/void	(*HUD_TempEntUpdate)(double, double, double, struct tempent_s **, struct tempent_s **, int(*Callback_AddVisibleEntity)(struct cl_entity_s*), void(*Callback_TempEntPlaySound)(struct tempent_s *pTemp, float damp ));
	struct cl_entity_s* (*HUD_GetUserEntity)(int index);
	/*37*/void	(*HUD_VoiceStatus)(int entindex, qboolean bTalking);
	int		(*HUD_DirectorEvent) (unsigned char, unsigned int, unsigned int, unsigned int);
	/*39*/int		(*HUD_GetStudioModelInterface)(int, struct r_studio_interface_s**, struct engine_studio_api_s*);
	unsigned long (*ClientFactory )(void);
} ClientDll_t;

//-------------------------------------------------------------------//

//extern ClientDll_t gClientDll;

//-------------------------------------------------------------------//

extern SCREENINFO g_Screen;
extern bool g_Screen_Updated;
extern float g_displayCenterX;
extern float g_displayCenterY;
extern bool bDraw;

//-------------------------------------------------------------------//

bool LoadHack();

//-------------------------------------------------------------------//

