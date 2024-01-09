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

typedef unsigned char byte;
#define true 1
static byte* gpBuf=0;
static int giSize=0;
static int giRead=0;
static int giBadRead=0;

//-------------------------------------------------------------------//

void BEGIN_READ( void *buf, int size )
{
	giRead = 0;
	giBadRead = 0;
	giSize = size;
	gpBuf = (byte*)buf;

	//if(cvar.info==100) logme("BEGIN_READ() %s %i\0", buf, size);
}

//-------------------------------------------------------------------//

int READ_CHAR( void )
{
	int     c = 0;
	if (giRead + 1 > giSize)
	{
		giBadRead = true;
		return -1;
	}
	c = (signed char)gpBuf[giRead];
	giRead++;
	return c;
}

//-------------------------------------------------------------------//

int READ_BYTE( void )
{
	int     c = 0;
	if (giRead+1 > giSize)
	{
		giBadRead = true;
		return -1;
	}	
	c = (unsigned char)gpBuf[giRead];
	giRead++;
	return c;
}

//-------------------------------------------------------------------//

int READ_SHORT( void )
{
	int     c = 0;
	if (giRead+2 > giSize)
	{
		giBadRead = true;
		return -1;
	}
	c = (short)( gpBuf[giRead] + ( gpBuf[giRead+1] << 8 ) );
	giRead += 2;
	return c;
}

//-------------------------------------------------------------------//

int READ_WORD( void )
{
	return READ_SHORT();
}

//-------------------------------------------------------------------//

int READ_LONG( void )
{
	int     c = 0;
	if (giRead+4 > giSize)
	{
		giBadRead = true;
		return -1;
	}	
 	c = gpBuf[giRead] + (gpBuf[giRead + 1] << 8) + (gpBuf[giRead + 2] << 16) + (gpBuf[giRead + 3] << 24);
	giRead += 4;
	return c;
}

//-------------------------------------------------------------------//

float READ_FLOAT( void )
{
	union
	{
		byte    b[4];
		float   f;
		int     l;
	} dat;
	dat.b[0] = gpBuf[giRead];
	dat.b[1] = gpBuf[giRead+1];
	dat.b[2] = gpBuf[giRead+2];
	dat.b[3] = gpBuf[giRead+3];
	giRead += 4;
	return dat.f;   
}

//-------------------------------------------------------------------//

char* READ_STRING( void )
{
	static char     string[2048]="\0";
	int             l = 0,c = 0;
	string[0] = 0;
	l = 0;
	do
	{
		if ( giRead+1 > giSize )
			break;
		c = READ_CHAR();
		if (c == -1 || c == 0)
			break;
		string[l] = c;
		l++;
	} while (l < sizeof(string)-1);
	string[l] = 0;
	return string;
}

//-------------------------------------------------------------------//

float READ_COORD( void )
{
	return (float)(READ_SHORT() * (1.0/8));
}

//-------------------------------------------------------------------//

float READ_ANGLE( void )
{
	return (float)(READ_CHAR() * (360.0/256));
}

//-------------------------------------------------------------------//

float READ_HIRESANGLE( void )
{
	return (float)(READ_SHORT() * (360.0/65536));
}

//-------------------------------------------------------------------//

