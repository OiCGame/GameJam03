#pragma once

#include	"Mof.h"

#define     BLOCK_FALLTIME      2.0f
#define		BLOCK_FALLSPEED		(1080.0f / BLOCK_FALLTIME) //速度(フレームに依存しない)
#define		BLOCK_COUNT		    10			//描画数
#define		SHOW_MAX	        20			//最大描画数
#define		RADIAN_RANGE		(0,360)		//角度の最低-最大
#define		RANDOM_RANGE		(300,1600)	//乱数幅
#define		BOTTOM_LIMIT		1500		//y軸における描画限界

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

	//関数後についている const の意味を理解していないので、適時追加してください。
	void SetShow(bool isShow) { m_bShow = isShow; }
};