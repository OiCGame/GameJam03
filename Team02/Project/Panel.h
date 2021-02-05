#pragma once

#include	"Mof.h"
#include	"Bullet.h"

constexpr int PanelCenterY = 260;

enum StageNumber {
	STAGE1,
	STAGE2,
	STAGE3,

	STAGECOUNT
};

class CPanel {
private:
	CDynamicArray<std::pair<int, CBullet>>	m_BulletArray;
	CTexture*	m_pBlletTexture[BULLET_CATEGORY];
	CTexture	m_PanelTexture[BULLET_CATEGORY];
	bool		m_bClear;
	int			m_StgNum;		//ステージ番号
	
    struct Panel
    {
        int     rotate;
        int     texNo;
        int     margin;
    };

    CDynamicArray<Panel> m_PanelArray;
	
public:
	CPanel();
	~CPanel();
    void SetTexture(CTexture** pTextureArray);
	void Initialize(int stagenum);
    bool Load(LPCMofChar pFile);
	void Update();
	void Render();
	void RenderDebug();
	void Release();

    float GetPanelWidth(void) const;

	void	CheckClear();
	bool	IsClear() { return m_bClear; }

	int	CheckHitCollision(CBullet& bullet);

	//複数ステージに対応した形に変更予定
	CVector2	GetPanelPosition(int panelnum);
};