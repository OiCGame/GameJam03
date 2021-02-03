#pragma once

#include <Mof.h>


class CBullet {
public:
	enum class TeamType {
		Player,
		Enemy,
	};
private:
	//! 位置
	Mof::CVector2 m_Position;
	//! 更新時に足しこまれる移動量
	Mof::CVector2 m_Move;
	//! 表示画像
	Mof::CTexture* m_pTexture;
	//! 表示フラグ
	bool m_bShow;
	//! 所属
	TeamType m_TeamType;

	int m_BulletNo;
	bool m_bUnDisappear;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CBullet();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~CBullet();
	/// <summary>
	/// セッター
	/// </summary>
	void SetTexture(Mof::CTexture* ptr);
	/// <summary>
	/// セッター
	/// </summary>
	void Hide(void);
	/// <summary>
	/// ゲッター
	/// </summary>
	Mof::CVector2 GetTextureSize(void) const;
	/// <summary>
	/// ゲッター
	/// </summary>
	Mof::CRectangle GetCollisionRectangle(void) const;
	/// <summary>
	/// 判定
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool IsShow(void) const;
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Update(void);
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(void);
	/// <summary>
	/// 撃つ
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Shot(Mof::CVector2 init_pos, TeamType type);

	void SetNo(int no) { m_BulletNo = no; }
	int GetNo() { return m_BulletNo; }
};