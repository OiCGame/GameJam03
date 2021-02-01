#pragma once

#include <Mof.h>

enum class BulletTeamType {
	Player,
	Enemy,
};

class Bullet {
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
	BulletTeamType _team_type;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Bullet();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Bullet();
    /// <summary>
    /// セッター
    /// </summary>
    void SetTexture(Mof::CTexture* ptr);
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
    /// 解放
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Release(void);
};