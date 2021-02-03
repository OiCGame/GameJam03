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
	CTexture*	四角Texture;
	CTexture*	三角Texture;
	bool		m_SingleOk[JUDGECNT];			// 個別
	bool		m_SingleConfirm[JUDGECNT];			// 個別
	bool		m_Clear;
	int			m_StgNum;		//ステージ番号
	int			m_JudgeCnt;		//ステージごとの判定用上枠数
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
	//上枠のパネルの(種類の)状態を記述
	int SingleState_Stg1[STG1JUDGECNT] = { Square,Square,Square,Square,Square,Square,Square };		//四角 : 0 / 三角 : 1 で記述
	//パネルがどっちにより大きく接しているか(近いか)を判定するために使う、境界線
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
		// ペイントにて大きさを測ったよ
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