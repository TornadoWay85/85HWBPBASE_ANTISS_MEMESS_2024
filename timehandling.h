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

#ifndef TIMEHANDLING_H
#define TIMEHANDLING_H

//-------------------------------------------------------------------//

class ClientTime 
{
public:
	static void   reportMapTime(float newMapTime);
	static float  mapTime;
	static void   updateCurrentTime();
	static double current;   
	static DWORD  current_ms;
protected:
};

//-------------------------------------------------------------------//

class StopTimer
{
public:

	StopTimer() :expirationTime(0)
	{
	}

	void  countdown( double seconds ) { expirationTime = ClientTime::current + seconds; }
	bool  running () { return (ClientTime::current<=expirationTime); }
	bool  expired () { return (ClientTime::current> expirationTime); }
	float timeleft() { return float(expirationTime-ClientTime::current);  }
	void  setExpired() { expirationTime=0;                           }
	void  setRunning() { expirationTime=1000000;                     }
protected:
	double expirationTime;
};

//-------------------------------------------------------------------//

class RunningStopTimer : public StopTimer { 

public: 
	
	RunningStopTimer(){
	} 
};

//-------------------------------------------------------------------//

template < short Interval, int MaxEvents = 12 >

//-------------------------------------------------------------------//

class EventCounter
{
public:
	int  get()
	{
		register int n = 0;
		while(reftime<ClientTime::current)
		{
			reftime += Interval;
			++n;
			if(n>MaxEvents) { reset(); return 1; }
		}
		return n;
	}
	EventCounter()  {reset();}
protected:
	void   reset() {reftime = ClientTime::current;}
	double reftime;
};

//-------------------------------------------------------------------//

#endif

//-------------------------------------------------------------------//

