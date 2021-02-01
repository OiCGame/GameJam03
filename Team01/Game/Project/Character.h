#pragma once


#include <Mof.h>


class Character {
private:
    //! 位置
    Mof::CVector2 _position;
    //! テクスチャ
    Mof::CTexture* _texture;
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
    void Shot(void);
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Character();
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~Character();
    /// <summary>
    /// セッター
    /// </summary>
    void SetTexture(Mof::CTexture* ptr);
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