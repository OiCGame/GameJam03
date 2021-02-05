#pragma once
#include "SceneBase.h"

//#include <Mof.h>
class CSceneTitle : public CSceneBase {
private:
	//! �e�N�X�`��
	Mof::CTexture m_Texture;
	Mof::CTexture m_ShopTexture;
	//! ����
	Mof::CFont m_Font;

	static const int m_MessageCount = 3;
//	std::string		m_Message[m_MessageCount] = { "�A������V���[�e�B���O","�Q�[���X�^�[�g", "�����L���O" };
	std::string		m_Message[m_MessageCount] = { "","�Q�[���X�^�[�g", "�����L���O" };
public:
	CSceneTitle();
	~CSceneTitle();
	bool Load(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Release(void);
};