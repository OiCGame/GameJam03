#pragma once
#include "Mof.h"
#include "EnemyBulletManager.h"

#define		AFTERIMAGE_INTERVAL		5

enum EnemyType
{
	TYPE_TELEPORT,
	TYPE_MOVE,
	TYPE_ALL,
};
enum EnemyPhase
{
	PHASE_MOVE,
	PHASE_ATTACK,
};

class CEnemy
{
private:
	CVector2 m_Position;	// 位置
	CVector2 m_MoveSpeed;		// 移動量
	CVector2 m_MovePos;		// 移動先の位置
	CVector2 m_OldPos[5];	// 移動した位置の保存
	CTexture* m_EnemyTexture;// テクスチャ
	int m_Type;
	bool m_bShow;
	int m_AfterimageInterval;
	bool m_MoveEnd;
	float m_TeleportInterval;
public:
	// コンストラクタ
	CEnemy();

	// デストラクタ
	~CEnemy();

	// 初期化
	bool Initialize();

	// 更新
	void Update(void);

	// 描画
	void Render(void);
	
	// 解放
	void Release(void);

	// 移動の更新
	void UpdateMove(void);

	// 弾の発射
	void Shot(const LauncherInit_Line & init);
	void Shot(const LauncherInit_Polygon & init);
	void Shot(const LauncherInit_PolygonRotation & init);
	

	// 移動に必要なパラメーターを設定
	void SetMoveParameter(CVector2 mPos, int type, CVector2 speed);

	// 矩形の取得
	CRectangle GetRectangle(void);

	// 円の取得
	CCircle GetCircle(void);
	
	// 中心座標の取得
	CVector2 GetCenterPos(void);

	bool IsShow(void);
	void SetShow(bool b) { m_bShow = b; }

	bool IsMoveEnd(void);
};

