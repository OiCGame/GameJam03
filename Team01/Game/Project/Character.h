#pragma once


#include <array>

#include "GameDefine.h"
#include "UICanvas.h"
#include "Bullet.h"


class CCharacter {
protected:
	//! 位置
	Mof::CVector2 m_Position;
	Mof::CVector2 m_InitPos;
	//! 移動
	Mof::CVector2 m_Move;
	//! 移動
	Mof::CVector2 m_Speed;
	//! テクスチャ
	Mof::CTexture* m_pTexture;
	//! Bulletテクスチャ
	Mof::CTexture* m_pBulletTexture;
	//! HP
	int m_HP;
	//! 表示
	bool m_bShow;
	//! 残機
	uint32_t m_RevivalCount;
	//! 連射
	bool m_bAutoShot;
	//! 発射間隔 アイテム取得時にインターバルを短くする
	int m_ShotInterval;
	//! 発射間隔カウント
	int m_ShotIntervalCount;
	//! 3Way
	bool m_b3WayShot;
	//! 弾の攻撃力
	uint32_t m_BulletLevel;

	int m_BulletNo;

	int m_Invincible;
	int m_RemInvincible;

	UICanvas* m_pCanvas;
	/// <summary>
	/// 移動
	/// </summary>
	/// <param name=""></param>
	virtual void Move(void);
	/// <summary>
	/// 撃つ
	/// </summary>
	/// <param name=""></param>
	virtual bool Shot(std::array<CBullet, 256>& bullet_container);
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CCharacter();
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CCharacter();
	/// <summary>
	/// セッター
	/// </summary>
	void SetTexture(Mof::CTexture* ptr);
	void SetBulletTexture(Mof::CTexture* ptr);
	void SetCanvas(UICanvas* ptr);
	/// <summary>
	/// ゲッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Mof::CVector2 GetPosition(void) const;
	/// <summary>
	/// ゲッター
	/// </summary>
	Mof::CRectangle GetCollisionRectangle(void) const;
	/// <summary>
	/// ゲッター
	/// </summary>
	uint32_t GetRevivalCount(void) const;
	/// <summary>
	/// ゲッター
	/// </summary>
	uint32_t GetBulletShotLevel(void) const;
	/// <summary>
	/// ゲッター
	/// </summary>
	bool IsShow(void) const;
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Initialize(Mof::CVector2 init_pos);
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Update(std::array<CBullet, 256>& bullet_container, int pha);
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Render(void);
	/// <summary>
	/// 解放
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Release(void);
	/// <summary>
	/// ダメージ
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Damage(void);
	/// <summary>
	/// 復活
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Revival(void);
	bool OutTop()const { return m_Position.y + m_pTexture->GetHeight() < 0.0f; }
	/// <summary>
	/// アイテム使用
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool OnUses(const std::shared_ptr<class CItem>& ptr);
	/// <summary>
	/// 復活数追加
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void AddRevivalCount(void);
	void BulletPowerUp(int level);
	void AttachAutoShot(void);
	void Attach3WayShot(void);

	int GetInvincible() { return m_RemInvincible; }
};