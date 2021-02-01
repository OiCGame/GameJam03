#pragma once


#include <array>

#include "GameDefine.h"

#include "Bullet.h"


class CCharacter {
private:
    //! 位置
    Mof::CVector2 _position;
    //! テクスチャ
    Mof::CTexture* _texture;
    //! Bulletテクスチャ
    Mof::CTexture* _bullet_texture;
protected:
    /// <summary>
    /// 移動
    /// </summary>
    /// <param name=""></param>
    void Move(void);
    /// <summary>
    /// 撃つ
    /// </summary>
    /// <param name=""></param>
    bool Shot(std::array<CBullet, 256>& bullet_container);
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
    /// 初期化
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Initialize(Mof::CVector2 init_pos);
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Update(std::array<CBullet, 256>& bullet_container);
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