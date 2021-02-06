#pragma once

#include	"Mof.h"
#include	"StopWatch.h"
#include	"NumericDisplay.h"

constexpr	auto	AlphaIncreaseValue = 5;

class CTimer
{
private:
	CNumericDisplay		NumericDisplay;
	sip::CStopWatch		StopWatch;
	
	CTexture			TimerFrameTexture;
	CVector2			Position;
	int					NowTime;
	int					LimitTime;
	int					BufferTime;

	CTexture			TimeDamageTexture;
	int					TimeDamageAlpha;
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
	//ŽÀ‚Í–¼‘O‚ª‚ ‚Ü‚è‚æ‚­‚È‚¢
	void		SetTime(int time) { BufferTime += time; }

	void StartRenderTimeDamage() { TimeDamageAlpha = 255; }
};