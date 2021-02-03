#include "NumericDisplay.h"

CNumericDisplay::CNumericDisplay()
{
}

CNumericDisplay::~CNumericDisplay()
{
}

void CNumericDisplay::Load()
{
	Texture.Load("UI/�Q�[���{��/����.png");
	TextureWidth = (Texture.GetWidth() * 0.1f);
}

void CNumericDisplay::Create(int numeric , CVector2 position)
{
	Position = position;
	SetNumeric(numeric);
}
CRectangle rect;
void CNumericDisplay::Render()
{
	for (int i = 0; i < NumericBuffer.GetArrayCount(); i++)
	{
		CRectangle rec(TextureWidth * NumericBuffer.GetData(i), 0,
			TextureWidth * (NumericBuffer.GetData(i) + 1), Texture.GetHeight());
		rect = rec;
		Texture.Render(Position.x + (TextureWidth * i), Position.y, rec);
	}
}

void CNumericDisplay::RenderDebug()
{
	CGraphicsUtilities::RenderString(500 , 410 , "���l�F%d", NumericBuffer.GetData(0));
	CGraphicsUtilities::RenderString(500 , 440 , "�ŏ��̃e�N�X�`���͈� �c�F%1f �F%2f", 0 , Texture.GetHeight());
	CGraphicsUtilities::RenderString(500 , 470 , "�ŏ��̃e�N�X�`���͈� ���F%1f �F%2f", 
		TextureWidth * NumericBuffer.GetData(0) , TextureWidth * (NumericBuffer.GetData(0) + 1));

}

void CNumericDisplay::Release()
{
	Texture.Release();
}

void CNumericDisplay::SetNumeric(int numeric)
{
	while (NumericBuffer.GetArrayCount() != 0)
	{
		NumericBuffer.DeleteLast();
	}
	
	int digits = (int)log10((double)numeric) + 1;
	while (digits > 0)
	{
		NumericBuffer.AddFast(numeric % 10);
		numeric /= 10;
		digits--;
	}
}
