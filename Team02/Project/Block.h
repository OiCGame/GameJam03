#pragma once

#include	"Mof.h"

#define		SPEED		10			//‘¬“x
#define		SHOW		10			//•`‰æ”
#define		SHOW_MAX	20			//Å‘å•`‰æ”
#define		RADIAN		(0,360)		//Šp“x‚ÌÅ’á-Å‘å
#define		RANDOM		(300,1000)	//—”•
#define		BOTTOM		1500			//y²‚É‚¨‚¯‚é•`‰æŒÀŠE

class CBlock {
private:
	CTexture		g_Block;
	CVector2		g_BlPos[SHOW_MAX];
	CTexture		g_UpRect;
	CVector2		g_UpPos;
	bool			g_Show[SHOW_MAX];
	int				timer;
	int				t;
	int				rad[SHOW_MAX];
public:
	CBlock();
	~CBlock();
	bool Load();
	void Initialize();
	void BlockSet(int i);
	void Update();
	void Render();
	void RenderBlock();
	void Release();
};