#pragma once

#include "Mof.h"

class CNumericDisplay
{
private:
	CTexture			Texture;
	float				TextureWidth;
	CVector2			Position;
	CDynamicArray<int>	NumericBuffer;


public:
	CNumericDisplay();
	~CNumericDisplay();
	void		Load();
	void		Create(int numeric ,CVector2 position);
	void		Render();
	void		RenderDebug();
	void		Release();
	
	void		SetNumeric(int numeric);
	void		SetPosition(CVector2 position) { Position = position; }

};
