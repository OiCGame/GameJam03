#pragma once

#include	"Bullet.h"

// 直線
struct LauncherInit_Line {
	// 位置 
	CVector2 position;
	// 発射ベクトル
	CVector2 vector;
	// テクスチャータイプ
	BulletType type{ BulletType::red };
	//発射回数
	int count{ 1 };
	// 発射間隔 [s]
	float interval{ 0.5f };
};

// 多角形
struct LauncherInit_Polygon {
	// 位置 
	CVector2 position;
	// 発射ベクトル
	CVector2 vector;
	// テクスチャータイプ
	BulletType type{ BulletType::yellow };
	//発射回数
	int count{ 1 };
	// 発射間隔 [s]
	float interval{ 0.5f };
	// 頂点数
	int vertex{ 8 };
};

class CEnemyBulletManager
{
private:
	// 弾の管理配列
	std::vector<CBullet> m_BulletList;

public:
	// シングルトン
	static CEnemyBulletManager& Singleton();

	// 弾の単体追加
	void addBullet(const CBullet & bullet);
	// 弾の複数追加
	void addBulletList(const std::vector<CBullet> & bullets);

	// 弾の発射パターン
	// 指定ベクトルへ単体発射
	void SetLauncher(const LauncherInit_Line & init);
	// 多角形状に発射
	void SetLauncher(const LauncherInit_Polygon & init);

	// 生きている弾の取得 (コストが高い為保留)
	// std::vector<CBullet> GetAliveBulletList();

	std::vector<CBullet>* GetBulletList();

	// 更新
	void Update();

	// 描画
	void Render();

};

