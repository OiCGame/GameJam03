#pragma once
#pragma once

#include	"Mof.h"
#include	"Bullet.h"

constexpr auto STG1JUDGECNT = 7;	// Stage 1 Judge Count
constexpr auto STG2JUDGECNT = 0;
constexpr auto STG3JUDGECNT = 0;
constexpr auto JUDGECNT = 10;

enum StageNumber {
	STAGE1,
	STAGE2,
	STAGE3
};

class CPanel {
private:
	CDynamicArray<CBullet>	Bullet;
	CTexture	m_PanelTexture;
	CTexture*	�l�pTexture;
	CTexture*	�O�pTexture;
	bool		m_SingleOk[JUDGECNT];			// ��
	bool		m_SingleConfirm[JUDGECNT];			// ��
	bool		m_Clear;
	int			m_StgNum;		//�X�e�[�W�ԍ�
	int			m_JudgeCnt;		//�X�e�[�W���Ƃ̔���p��g��
	bool		m_MultiCollision;
	float		m_JdgA, m_JdgB;
public:
	CPanel();
	~CPanel();
	void Initialize(int stagenum);
	void Update(CRectangle rec, float px, int bt);
	void Render();
	void RenderDebug();
	void Release();
	//��g�̃p�l����(��ނ�)��Ԃ��L�q
	int SingleState_Stg1[STG1JUDGECNT] = { Square,Square,Square,Square,Square,Square,Square };		//�l�p : 0 / �O�p : 1 �ŋL�q
	//�p�l�����ǂ����ɂ��傫���ڂ��Ă��邩(�߂���)�𔻒肷�邽�߂Ɏg���A���E��
	float FrontLine_Stg1[STG1JUDGECNT] = { 124, 387 ,634, 881, 1129 ,1376, 1610 };
	CVector2   SinglePos_Stg1[STG1JUDGECNT] = {
		Vector2(14,13),
		Vector2(263,13),
		Vector2(511,13),
		Vector2(757,13),
		Vector2(1006,13),
		Vector2(1253,13),
		Vector2(1500,13)
	};
	CRectangle SingleRect_Stg1[STG1JUDGECNT] = {
		// �y�C���g�ɂđ傫���𑪂�����
		CRectangle(14,13, 261,262),
		CRectangle(263,13, 509,262),
		CRectangle(511,13, 755,262),
		CRectangle(757,13,1004,262),
		CRectangle(1006,13,1252,262),
		CRectangle(1253,13,1497,262),
		CRectangle(1500,13,1748,262),
	};
	CRectangle SingleRect_Stg2[2] = {
		CRectangle(0,0,0,0),
		CRectangle(0,0,0,0)
	};
	CRectangle SingleRect_Stg3[2] = {
		CRectangle(0,0,0,0),
		CRectangle(0,0,0,0)
	};
};