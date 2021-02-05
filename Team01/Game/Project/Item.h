#pragma once


#include <Mof.h>

#include "Character.h"


class CItem {
private:
	//! 位置
	Mof::CVector2 m_Position;
	//! テクスチャ
	Mof::CTexture* m_pTexture;
	//! 表示
	bool m_bShow;
	//! 行先
	CCharacter* m_pTarget;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CItem();
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CItem();
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetPosition(Mof::CVector2 pos);
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetTexture(Mof::CTexture* ptr);
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetShow(bool flag);
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetPlayer(CCharacter* ptr);
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Mof::CRectangle GetRectangle(void) const;
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
	/// 使用
	/// </summary>
    /// <param name=""></param>
    /// <returns></returns>
	virtual bool Use(CCharacter& out) = 0;
};