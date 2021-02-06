#pragma once
#include <vector>
#include <memory>
#include "Enemy.h"
#include "EnemyBulletManager.h"

class CEnemyManager
{
private:
	std::vector<std::shared_ptr<CEnemy>> m_pEnemyArray;
	std::vector<CVector2> m_MovePosArray;
	std::vector<int> m_EnemyMovePosArray;

	float m_MoveTime;
	CVector2 m_MoveSpeed;
	int m_MoveType;
	float m_TeleportInterval;

	// コンストラクタ
	CEnemyManager();

	//デストラクタ
	~CEnemyManager();
public:
	// シングルトン
	static CEnemyManager& Singleton(void);

	// 初期化
	void Initialize(void);

	// 更新
	void Update(void);

	// 描画
	void Render(void);

	// 解放
	void Release(void);

	// 移動の開始
	void StartMove(float Time,CVector2 speed,int type, float TeleportInterval);

	// 弾の発射
	void StartShot(const LauncherInit_Line & init);
	void StartShot(const LauncherInit_Polygon & init);
	void StartShot(const LauncherInit_PolygonRotation & init);

	// 登録
	void AddEnemy(const std::shared_ptr<CEnemy> & penemy);

	// 移動位置の登録
	void AddMovePos(CVector2 mPos);

	// 取得
	std::shared_ptr<CEnemy> GetEnemy(int i) const;

	// 敵数の取得
	int GetEnemyCount(void);

	bool IsMoveEnd(void);

	bool IsShotEnd(void);
};

