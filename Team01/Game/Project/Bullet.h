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
	Mof::CVector2 _position;
	//! 更新時に足しこまれる移動量
	Mof::CVector2 _move;
	//! 表示画像
	Mof::CTexture* _texture;
	//! 表示フラグ
	bool _show;
	//! 所属
	TeamType _team_type;
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
	/// ゲッター
	/// </summary>
	Mof::CVector2 GetTextureSize(void) const;
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
};