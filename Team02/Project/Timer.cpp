#include "Timer.h"



CTimer::CTimer()
{
}

CTimer::~CTimer()
{
}

void CTimer::Load()
{
	TimerFrameTexture.Load("UI/ゲーム本編/TIMEプレート.png");
	TimeDamageTexture.Load("UI/ゲーム本編/タイムダメージ.png"),
	NumericDisplay.Load();
}

void CTimer::Initialize(int time, CVector2 position)
{
	LimitTime		= time;
	NowTime			= time;
	BufferTime		= 0;
	Position		= position;
	NumericDisplay.Create(NowTime, CVector2(position.x + TimerFrameTexture.GetWidth() * 0.6, position.y + TimerFrameTexture.GetHeight() * 0.4));
	StopWatch.Start();
	TimeDamageAlpha = 0;
}

void CTimer::Update()
{
	StopWatch.Update();

	NowTime = LimitTime - (int)StopWatch.GetTime() + BufferTime;

	if (NowTime <= 0)
	{
		NowTime = 0;
		StopWatch.Stop();
	}

	if (TimeDamageAlpha > 0)
	{
		TimeDamageAlpha -= AlphaIncreaseValue;
		if (TimeDamageAlpha <= 0)
		{
			TimeDamageAlpha = 0;
		}
	}

	NumericDisplay.SetNumeric(NowTime);
}

void CTimer::Render()
{
	TimerFrameTexture.Render(Position.x , Position.y);
	NumericDisplay.Render();
	TimeDamageTexture.Render(Position.x - TimerFrameTexture.GetWidth(), Position.y + 10, MOF_ARGB(TimeDamageAlpha, 255, 255, 255));
	
}

void CTimer::RenderDebug()
{
	NumericDisplay.RenderDebug();
	CGraphicsUtilities::RenderString(1000, 100 , MOF_COLOR_GREEN , "残り時間：%f", StopWatch.GetTime());
}

void CTimer::Release()
{
	TimerFrameTexture.Release();
	NumericDisplay.Release();
}