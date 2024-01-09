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

#include "halflife-master\common\interface.h"
#include "halflife-master\cl_dll\wrect.h"
#include "halflife-master\cl_dll\cl_dll.h"
#include "halflife-master\engine\cdll_int.h"
#include "halflife-master\common\r_studioint.h"
#include "halflife-master\common\com_model.h"
#include "halflife-master\common\cl_entity.h"
#include "halflife-master\common\ref_params.h"
#include "halflife-master\pm_shared\pm_defs.h"
#include "halflife-master\pm_shared\pm_movevars.h"
#include "halflife-master\engine\studio.h"
//#include "halflife-master\parsemsg.h"
#include "parsemsg.h"
#include "halflife-master\common\cvardef.h"
#include "halflife-master\common\triangleapi.h"
#include "halflife-master\common\pmtrace.h"
#include "halflife-master\common\event_api.h"
#include "halflife-master\common\r_efx.h"
#include "halflife-master\common\entity_types.h"
#include "halflife-master\common\screenfade.h"
#include "halflife-master\common\net_api.h"

//#include "halflife-master\common\entity_state.h"

#include "KEYDEFS.h"

#define MAXSTUDIOBONES		128		// total bones actually used
typedef float TransformMatrix[MAXSTUDIOBONES][3][4];

//-------------------------------------------------------------------//

#include "defs.h"

#define pisobre180 0.01745
#define _180sobrepi 57.30659
#define pisobre2 1.570796326795
#define pisobre2sobre360 0.004363323129
#define uno_milveinticuatro 0.0009765625 //(1.0/1024.0)

//-------------------------------------------------------------------//


