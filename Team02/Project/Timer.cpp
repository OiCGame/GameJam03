#include "Timer.h"



CTimer::CTimer()
{
}

CTimer::~CTimer()
{
}

void CTimer::Load()
{
	Texture.Load("UI/ゲーム本編/TIMEプレート.png");
	NumericDisplay.Load();
}

void CTimer::Initialize(int time, CVector2 position)
{
	LimitTime		= time;
	NowTime			= time;
	Position		= position;
	NumericDisplay.Create(NowTime, CVector2(position.x + Texture.GetWidth() * 0.6, position.y + Texture.GetHeight() * 0.4));
	StopWatch.Start();
}

void CTimer::Update()
{
	StopWatch.Update();

	NowTime = LimitTime - (int)StopWatch.GetTime();

	if (NowTime <= 0)
	{
		NowTime = 0;
		StopWatch.Stop();
	}

	NumericDisplay.SetNumeric(NowTime);
}

void CTimer::Render()
{
	Texture.Render(Position.x , Position.y);
	NumericDisplay.Render();
	
}

void CTimer::RenderDebug()
{
	NumericDisplay.RenderDebug();
	CGraphicsUtilities::RenderString(1000, 100 , MOF_COLOR_GREEN , "残り時間：%f", StopWatch.GetTime());
}

void CTimer::Release()
{
	Texture.Release();
	NumericDisplay.Release();
}
