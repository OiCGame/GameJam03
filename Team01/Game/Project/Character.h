#pragma once


#include <array>

#include "GameDefine.h"

#include "Bullet.h"


class CCharacter {
protected:
	//! 位置
	Mof::CVector2 m_Position;
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
	virtual bool Update(std::array<CBullet, 256>& bullet_container);
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
	void Damage(void);
};