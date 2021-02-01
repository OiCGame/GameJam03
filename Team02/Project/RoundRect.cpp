#include "RoundRect.h"

namespace sip
{
	// ********************************************************************************
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::RoundRect(void)
		: Rectangle()
		, r(0.0f)
	{
	}

	// ********************************************************************************
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="left">左</param>
	/// <param name="top">上</param>
	/// <param name="right">右</param>
	/// <param name="bottom">下</param>
	/// <param name="r">角丸ポイント</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::RoundRect(MofFloat left, MofFloat top, MofFloat right, MofFloat bottom, MofFloat r)
		: Rectangle(left, top, right, bottom)
		, r(r)
	{
	}

	// ********************************************************************************
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="lt">左上</param>
	/// <param name="rb">右下</param>
	/// <param name="r">角丸ポイント</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::RoundRect(const Vector2 & lt, const Vector2 & rb, MofFloat r)
		: Rectangle(lt, rb)
		, r(r)
	{
	}

	// ********************************************************************************
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="rect">矩形</param>
	/// <param name="r">角丸ポイント</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::RoundRect(const Mof::Rectangle & rect, MofFloat r)
		: Rectangle(rect)
		, r(r)
	{
	}

	// ********************************************************************************
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pv">パラメータ配列</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::RoundRect(LPMofFloat pv)
		: Rectangle(pv)
		, r(pv[4])
	{
	}

	// ********************************************************************************
	/// <summary>
	/// コピーコンストラクタ
	/// </summary>
	/// <param name="pObj">コピー角丸矩形</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::RoundRect(const sip::RoundRect & pObj)
		: Rectangle(pObj)
		, r(pObj.r)
	{
	}

	// ********************************************************************************
	/// <summary>
	/// MofFloat配列として取得
	/// </summary>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::operator LPMofFloat(void)
	{
		return (LPMofFloat)&Left;
	}

	// ********************************************************************************
	/// <summary>
	/// Rectangleとして取得
	/// </summary>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::operator Mof::Rectangle(void)
	{
		return Rectangle(Left, Top, Right, Bottom);
	}

	// ********************************************************************************
	/// <summary>
	/// ==判断
	/// </summary>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	bool RoundRect::operator==(const RoundRect & v) const
	{
		return Left == v.Left && Top == v.Top && Right == v.Right && Bottom == v.Bottom && r == v.r;
	}

	// ********************************************************************************
	/// <summary>
	/// !=判断
	/// </summary>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	bool RoundRect::operator!=(const RoundRect & v) const
	{
		return Left != v.Left || Top != v.Top || Right != v.Right || Bottom != v.Bottom || r != v.r;
	}

	// ********************************************************************************
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	CRoundRect::CRoundRect(void)
		: RoundRect()
	{
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="left">左</param>
	/// <param name="top">上</param>
	/// <param name="right">右</param>
	/// <param name="bottom">下</param>
	/// <param name="r">角丸ポイント</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	CRoundRect::CRoundRect(MofFloat left, MofFloat top, MofFloat right, MofFloat bottom, MofFloat r)
		: RoundRect(left, top, right, bottom, r)
	{
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="lt">左上</param>
	/// <param name="rb">右下</param>
	/// <param name="r">角丸ポイント</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	CRoundRect::CRoundRect(const Vector2 & lt, const Vector2 & rb, MofFloat r)
		: RoundRect(lt, rb, r)
	{
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="rect">矩形</param>
	/// <param name="r">角丸ポイント</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	CRoundRect::CRoundRect(const Mof::Rectangle & rect, MofFloat r)
		: RoundRect(rect, r)
	{
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pv">パラメータ配列</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	CRoundRect::CRoundRect(LPMofFloat pv)
		: RoundRect(pv)
	{
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// コピーコンストラクタ
	/// </summary>
	/// <param name="pObj">コピー角丸矩形</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	CRoundRect::CRoundRect(const RoundRect & pObj)
		: RoundRect(pObj)
	{
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// 矩形拡張<br>
	/// Left, Topに - e、Right, Bottomに + e、this->rに + rを行う
	/// </summary>
	/// <param name="e">拡張サイズ</param>
	/// <param name="r">半径の拡張サイズ</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRect::Expansion(const MofFloat & e, const MofFloat & r)
	{
		Left -= e;
		Top -= e;
		Right += e;
		Bottom += e;
		this->r += r;
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// 矩形拡張<br>
	/// Left, Topに - ex、Right, Bottomに + ey、this->rに + rを行う
	/// </summary>
	/// <param name="ex">X拡張サイズ</param>
	/// <param name="ey">Y拡張サイズ</param>
	/// <param name="r">半径の拡張サイズ</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRect::Expansion(const MofFloat & ex, const MofFloat & ey, const MofFloat & r)
	{
		Left -= ex;
		Top -= ey;
		Right += ex;
		Bottom += ey;
		this->r += r;
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// 矩形の幅と高さをそのままにm移動する。
	/// </summary>
	/// <param name="m">移動量</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRect::Translation(const Vector2 & m)
	{
		MofFloat w = Right - Left;
		MofFloat h = Bottom - Top;
		Left += m.x;
		Top += m.y;
		Right = Left + w;
		Bottom = Top + h;
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// 矩形の幅と高さをそのままにposの位置に移動する。
	/// </summary>
	/// <param name="pos">位置</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRect::SetPosition(const Vector2 & pos)
	{
		MofFloat w = Right - Left;
		MofFloat h = Bottom - Top;
		Left = pos.x;
		Top = pos.y;
		Right = Left + w;
		Bottom = Top + h;
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// 幅の設定
	/// </summary>
	/// <param name="w">設定する幅</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRect::SetWidth(const MofFloat & w)
	{
		Right = Left + w;
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// 高さの設定
	/// </summary>
	/// <param name="h">設定する高さ</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRect::SetHeight(const MofFloat & h)
	{
		Bottom = Top + h;
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// 半径の設定
	/// </summary>
	/// <param name="r">設定する半径</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRect::SetRadius(const MofFloat & r)
	{
		this->r = r;
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// 座標との当たり判定
	/// </summary>
	/// <param name="px">当たり判定をとるX座標</param>
	/// <param name="py">当たり判定をとるY座標</param>
	/// <returns>当たったかどうか</returns>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	MofBool CRoundRect::CollisionPoint(const MofFloat & px, const MofFloat & py) const
	{
		for (int i = 0; i < 4; i++)
		{
			if (m_CircleArray[i] == NoneCircle)
			{
				break;
			}

			if (CCircleUtilities::CollisionPoint(m_CircleArray[i], px, py))
			{
				return TRUE;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			if (m_RectArray[i] == NoneRect)
			{
				break;
			}

			if (CRectangleUtilities::CollisionPoint(m_RectArray[i], px, py))
			{
				return TRUE;
			}
		}
		return FALSE;
	}

	// ********************************************************************************
	/// <summary>
	/// 座標との当たり判定
	/// </summary>
	/// <param name="p">当たり判定をとる座標</param>
	/// <returns>当たったかどうか</returns>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	MofBool CRoundRect::CollisionPoint(const Vector2 & p) const
	{
		return CollisionPoint(p.x, p.y);
	}

	// ********************************************************************************
	/// <summary>
	/// 値の設定
	/// </summary>
	/// <param name="left">左</param>
	/// <param name="top">上</param>
	/// <param name="right">右</param>
	/// <param name="bottom">下</param>
	/// <param name="r">角丸半径</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRect::SetValue(MofFloat left, MofFloat top, MofFloat right, MofFloat bottom, MofFloat r)
	{
		Left = left;
		Top = top;
		Right = right;
		Bottom = bottom;
		this->r = r;
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="color">描画色</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRect::Render(const MofU32 & color)
	{
		// 円の描画
		for (int i = 0; i < 4; i++)
		{
			if (m_CircleArray[i] == NoneCircle)
			{
				break;
			}
			CGraphicsUtilities::RenderFillCircle(m_CircleArray[i], color);
		}
		// 矩形の描画
		for (int i = 0; i < 2; i++)
		{
			if (m_RectArray[i] == NoneRect)
			{
				break;
			}
			CGraphicsUtilities::RenderFillRect(m_RectArray[i], color);
		}
	}

	// ********************************************************************************
	/// <summary>
	/// 幅の取得
	/// </summary>
	/// <returns>幅</returns>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	MofFloat CRoundRect::GetWidth(void) const
	{
		return Right - Left;
	}

	// ********************************************************************************
	/// <summary>
	/// 高さの取得
	/// </summary>
	/// <returns>高さ</returns>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	MofFloat CRoundRect::GetHeight(void) const
	{
		return Bottom - Top;
	}

	// ********************************************************************************
	/// <summary>
	/// 角丸半径の所得
	/// </summary>
	/// <returns>角丸半径</returns>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	MofFloat CRoundRect::GetRadius(void) const
	{
		return r;
	}

	// ********************************************************************************
	/// <summary>
	/// 中心座標の取得
	/// </summary>
	/// <returns>中心座標</returns>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	Vector2 CRoundRect::GetCenter(void) const
	{
		return Vector2((Left + Right) * 0.5f, (Top + Bottom) * 0.5f);
	}

	// ********************************************************************************
	/// <summary>
	/// RoundRectとして取得
	/// </summary>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	CRoundRect::operator sip::RoundRect(void)
	{
		return sip::RoundRect(Left, Top, Right, Bottom, r);
	}

	// ********************************************************************************
	/// <summary>
	/// 角丸の計算
	/// </summary>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRect::CalcRectCircle(void)
	{
		// 配列の初期化
		for (int i = 0; i < 4; i++)
		{
			m_CircleArray[i] = NoneCircle;
			if (i >= 2) continue;
			m_RectArray[i] = NoneRect;
		}

		// 高さと半径のチェック
		bool bLessW = (GetWidth() <= r * 2);
		// 横幅と半径のチェック
		bool bLessH = (GetHeight() <= r * 2);

		// 半径の制御
		r = MOF_CLIPING(r, 0, MOF_MIN(GetHeight(), GetWidth()) * 0.5f);

		// 高さ、幅の両方を半径が超えている場合、円のみ。
		if (bLessW && bLessH)
		{
			m_CircleArray[0] = Mof::Circle(GetCenter(), r);
		}
		// どちらか片方超えている場合、使用する配列を減らす。
		else if (bLessW || bLessH)
		{
			if (bLessW)
			{
				m_RectArray[0] = Mof::Rectangle(Left, Top + r, Right, Bottom - r);
			}
			else
			{
				m_RectArray[0] = Mof::Rectangle(Left + r, Top, Right - r, Bottom);
			}
			m_CircleArray[0] = Mof::Circle(Left  + r, Top    + r, r);
			m_CircleArray[1] = Mof::Circle(Right - r, Bottom - r, r);
		}
		else
		{
			m_RectArray[0] = Mof::Rectangle(Left, Top + r, Right, Bottom - r);
			m_RectArray[1] = Mof::Rectangle(Left + r, Top, Right - r, Bottom);

			m_CircleArray[0] = Mof::Circle(Left  + r, Top    + r, r);
			m_CircleArray[1] = Mof::Circle(Right - r, Top    + r, r);
			m_CircleArray[2] = Mof::Circle(Left  + r, Bottom - r, r);
			m_CircleArray[3] = Mof::Circle(Right - r, Bottom - r, r);
		}
	}

	// ********************************************************************************
	/// <summary>
	/// 座標との当たり判定
	/// </summary>
	/// <param name="rrect">判定をとる角丸矩形</param>
	/// <param name="px">当たり判定をとるX座標</param>
	/// <param name="py">当たり判定をとるY座標</param>
	/// <returns>当たったかどうか</returns>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	MofBool CRoundRectUtilities::CollisionPoint(const sip::RoundRect & rrect, const MofFloat & px, const MofFloat & py)
	{
		const CRoundRect r(rrect);
		return r.CollisionPoint(px, py);
	}

	// ********************************************************************************
	/// <summary>
	/// 座標との当たり判定
	/// </summary>
	/// <param name="rrect">判定をとる角丸矩形</param>
	/// <param name="p">当たり判定をとる座標</param>
	/// <returns>当たったかどうか</returns>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	MofBool CRoundRectUtilities::CollisionPoint(const sip::RoundRect & rrect, const Vector2 & p)
	{
		return CollisionPoint(rrect, p.x, p.y);
	}

	// ********************************************************************************
	/// <summary>
	/// 角丸矩形の描画
	/// </summary>
	/// <param name="rrect">描画する角丸矩形</param>
	/// <param name="color">描画色</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRectUtilities::Render(const sip::RoundRect & rrect, const MofU32 & color)
	{
		CRoundRect r(rrect);
		r.Render(color);
	}

	// ********************************************************************************
	/// <summary>
	/// 画像を角丸矩形の中に納めて描画
	/// </summary>
	/// <param name="rrect">マスクになる角丸矩形</param>
	/// <param name="pTexture">描画する画像ポインタ</param>
	/// <param name="color">描画する画像の色</param>
	/// <created>いのうえ,2020/10/30</created>
	/// <changed>いのうえ,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRectUtilities::Render(const sip::RoundRect & rrect, const LPTexture & pTexture, const MofU32 & color)
	{
		CRoundRect r(rrect);
		g_pGraphics->SetStencilEnable(TRUE);
		g_pGraphics->SetStencilValue(1);
		g_pGraphics->SetStencilControl(COMPARISON_ALWAYS, STENCIL_REPLACE, STENCIL_REPLACE, STENCIL_REPLACE);
		r.Render(MOF_ARGB(0, 0, 0, 0));
		g_pGraphics->SetStencilControl(COMPARISON_EQUAL, STENCIL_KEEP, STENCIL_KEEP, STENCIL_KEEP);
		pTexture->Render(rrect, color);
		g_pGraphics->SetStencilEnable(FALSE);
	}
}
