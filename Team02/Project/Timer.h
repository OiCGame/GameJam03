#pragma once

#include	"Mof.h"
#include	"StopWatch.h"
#include	"NumericDisplay.h"

class CTimer
{
private:
	CNumericDisplay		NumericDisplay;
	sip::CStopWatch		StopWatch;
	
	CTexture			Texture;
	CVector2			Position;
	int					NowTime;
	int					LimitTime;
	int					BufferTime;
public:
	CTimer();
	~CTimer();

	void		Load();
	void		Initialize(int time , CVector2 position);
	void		Update();
	void		Render();
	void		RenderDebug();
	void		Release();

	int			GetTime() { return NowTime; }
	void		SetTime(int time) { BufferTime += time; }
};