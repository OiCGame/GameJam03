#pragma once

#include	"Mof.h"

#define     BLOCK_FALLTIME      2.0f
#define		BLOCK_FALLSPEED		(1080.0f / BLOCK_FALLTIME) //���x(�t���[���Ɉˑ����Ȃ�)
#define		BLOCK_COUNT		    10			//�`�搔
#define		SHOW_MAX	        20			//�ő�`�搔
#define		RADIAN_RANGE		(0,360)		//�p�x�̍Œ�-�ő�
#define		RANDOM_RANGE		(300,1600)	//������
#define		BOTTOM_LIMIT		1500		//y���ɂ�����`����E

class CBlock {
private:

    enum BulletType {
        Triangle,
        Square,
    }               m_BulletType;

	CTexture*		m_pBlockTexture;
	CVector2		m_Pos;
	bool			m_bShow;
	int				m_Timer;
	int				m_FlameTime;
	int				m_DegreeAngle;
public:
	CBlock();
	~CBlock();
	void SetTexture(CTexture* pTexture);
	void Initialize();
	void FallStart(CTexture* pTexture, int bullettype);
	void Update();
	void Render();
	void RenderDebug();
	void Release();

    bool IsShow() const;

    CCircle GetCollisionCircle() const;

    int GetBulletType() const;

	//�֐���ɂ��Ă��� const �̈Ӗ��𗝉����Ă��Ȃ��̂ŁA�K���ǉ����Ă��������B
	void SetShow(bool isShow) { m_bShow = isShow; }
};