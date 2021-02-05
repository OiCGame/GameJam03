#pragma once
#pragma once

#include	"Mof.h"
#include	"Bullet.h"

//�ł����BulletManager�̂悤�ɂ���ׂ�����
//#include	"Player.h"

constexpr auto STG1JUDGECNT = 7;	// Stage 1 Judge Count
constexpr auto STG2JUDGECNT = 11;
constexpr auto STG3JUDGECNT = 1;
constexpr auto JUDGECNT = 15;

enum StageNumber {
	STAGE1,
	STAGE2,
	STAGE3,

	STAGECOUNT
};

class CPanel {
private:
	CDynamicArray<CBullet>	Bullet;
	//CPlayer					Player;
	CTexture	m_PanelTexture;
	CTexture*	m_pSquareTexture;
	CTexture*	m_pTriangleTexture;
	bool		m_SingleOk[JUDGECNT];			// ��
	bool		m_SingleConfirm[JUDGECNT];			// ��
	bool		m_Clear;
	int			m_StgNum;		//�X�e�[�W�ԍ�
	int			m_JudgeCnt;		//�X�e�[�W���Ƃ̔���p��g��
	bool		m_MultiCollision;
	float		m_JdgA, m_JdgB;
	//��]�����i�[���Ă�������
	int			m_Rotate[STAGECOUNT][JUDGECNT]	=
	{
		{Up,Up,Up,Up,Up,Up,Up},
		{Right,Up,Down,Up,Down,Up,Down,Up,Down,Up,Left},
		{}
	};
public:
	CPanel();
	~CPanel();
    void SetTexture(CTexture** pTextureArray);
	void Initialize(int stagenum);
	void Update();
	void Render();
	void RenderDebug();
	void Release();
	//��g�̃p�l����(��ނ�)��Ԃ��L�q
	int SingleState_Stg1[STG1JUDGECNT] = { Square,Square,Square,Square,Square,Square,Square };
	int SingleState_Stg2[STG2JUDGECNT] = { Triangle,Triangle,Triangle ,Triangle ,Triangle ,
								Triangle ,Triangle ,Triangle ,Triangle ,Triangle ,Triangle };
	//�p�l�����ǂ����ɂ��傫���ڂ��Ă��邩(�߂���)�𔻒肷�邽�߂Ɏg���A���E��
	float FrontLine_Stg1[STG1JUDGECNT] = { 215, 460 ,705, 950, 1195 ,1440, 1685 };
	float FrontLine_Stg2[STG2JUDGECNT] = { 315,464,588,712,835,959,1082,1206,1329,1452,1633	};
	//�ȉ��p�l��1�ɂ��āA�`��ʒu�ύX�ɂ��������܂����B
	CVector2   SinglePos_Stg1[STG1JUDGECNT] = {
		Vector2(90,140),
		Vector2(342,140),
		Vector2(589,140),
		Vector2(836,140),
		Vector2(1083,140),
		Vector2(1330,140),
		Vector2(1577,140)
	};
	CVector2   SinglePos_Stg2[STG2JUDGECNT] = {
		Vector2(315,247.5),
		Vector2(464,247.5),
		Vector2(588,247.5),
		Vector2(712,247.5),
		Vector2(835,247.5),
		Vector2(959,247.5),
		Vector2(1082,247.5),
		Vector2(1206,247.5),
		Vector2(1329,247.5),
		Vector2(1452,247.5),
		Vector2(1633,247.5)
	};	

	CVector2   SinglePos_Stg3[STG3JUDGECNT] = {
		
	};
	CRectangle SingleRect_Stg1[STG1JUDGECNT] = {
		// �y�C���g�ɂđ傫���𑪂�����
		CRectangle(90,140, 340,399),
		CRectangle(342,140, 587,399),
		CRectangle(589,140, 834,399),
		CRectangle(836,140,1081,399),
		CRectangle(1083,140,1328,399),
		CRectangle(1330,140,1575,399),
		CRectangle(1577,140,1822,399)
	};	

	CRectangle SingleRect_Stg2[STG2JUDGECNT] = {
		CRectangle(191 ,140,439,399),
		CRectangle(340 ,140,588,399),
		CRectangle(464 ,140,712,399),
		CRectangle(588 ,140,836,399),
		CRectangle(711 ,140,959,399),
		CRectangle(835 ,140,1083,399),
		CRectangle(958 ,140,1206,399),
		CRectangle(1082,140,1330,399),
		CRectangle(1205,140,1453,399),
		CRectangle(1328,140,1576,399),
		CRectangle(1509,140,1757,399)
	};
	CRectangle SingleRect_Stg3[2] = {
		CRectangle(0,0,0,0),
		CRectangle(0,0,0,0)
	};

	void	CheckClear();
	bool	IsClear() { return m_Clear; }

	int	CheckHitCollision(CRectangle rec, float px, int bt , int rotate);

	//�����X�e�[�W�ɑΉ������`�ɕύX�\��
	CVector2	GetPanelPosition(int panelnum);
};