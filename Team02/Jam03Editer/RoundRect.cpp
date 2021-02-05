#include "RoundRect.h"

namespace sip
{
	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::RoundRect(void)
		: Rectangle()
		, r(0.0f)
	{
	}

	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="left">��</param>
	/// <param name="top">��</param>
	/// <param name="right">�E</param>
	/// <param name="bottom">��</param>
	/// <param name="r">�p�ۃ|�C���g</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::RoundRect(MofFloat left, MofFloat top, MofFloat right, MofFloat bottom, MofFloat r)
		: Rectangle(left, top, right, bottom)
		, r(r)
	{
	}

	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="lt">����</param>
	/// <param name="rb">�E��</param>
	/// <param name="r">�p�ۃ|�C���g</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::RoundRect(const Vector2 & lt, const Vector2 & rb, MofFloat r)
		: Rectangle(lt, rb)
		, r(r)
	{
	}

	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="rect">��`</param>
	/// <param name="r">�p�ۃ|�C���g</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::RoundRect(const Mof::Rectangle & rect, MofFloat r)
		: Rectangle(rect)
		, r(r)
	{
	}

	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="pv">�p�����[�^�z��</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::RoundRect(LPMofFloat pv)
		: Rectangle(pv)
		, r(pv[4])
	{
	}

	// ********************************************************************************
	/// <summary>
	/// �R�s�[�R���X�g���N�^
	/// </summary>
	/// <param name="pObj">�R�s�[�p�ۋ�`</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::RoundRect(const sip::RoundRect & pObj)
		: Rectangle(pObj)
		, r(pObj.r)
	{
	}

	// ********************************************************************************
	/// <summary>
	/// MofFloat�z��Ƃ��Ď擾
	/// </summary>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::operator LPMofFloat(void)
	{
		return (LPMofFloat)&Left;
	}

	// ********************************************************************************
	/// <summary>
	/// Rectangle�Ƃ��Ď擾
	/// </summary>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	RoundRect::operator Mof::Rectangle(void)
	{
		return Rectangle(Left, Top, Right, Bottom);
	}

	// ********************************************************************************
	/// <summary>
	/// ==���f
	/// </summary>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	bool RoundRect::operator==(const RoundRect & v) const
	{
		return Left == v.Left && Top == v.Top && Right == v.Right && Bottom == v.Bottom && r == v.r;
	}

	// ********************************************************************************
	/// <summary>
	/// !=���f
	/// </summary>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	bool RoundRect::operator!=(const RoundRect & v) const
	{
		return Left != v.Left || Top != v.Top || Right != v.Right || Bottom != v.Bottom || r != v.r;
	}

	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	CRoundRect::CRoundRect(void)
		: RoundRect()
	{
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="left">��</param>
	/// <param name="top">��</param>
	/// <param name="right">�E</param>
	/// <param name="bottom">��</param>
	/// <param name="r">�p�ۃ|�C���g</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	CRoundRect::CRoundRect(MofFloat left, MofFloat top, MofFloat right, MofFloat bottom, MofFloat r)
		: RoundRect(left, top, right, bottom, r)
	{
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="lt">����</param>
	/// <param name="rb">�E��</param>
	/// <param name="r">�p�ۃ|�C���g</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	CRoundRect::CRoundRect(const Vector2 & lt, const Vector2 & rb, MofFloat r)
		: RoundRect(lt, rb, r)
	{
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="rect">��`</param>
	/// <param name="r">�p�ۃ|�C���g</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	CRoundRect::CRoundRect(const Mof::Rectangle & rect, MofFloat r)
		: RoundRect(rect, r)
	{
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="pv">�p�����[�^�z��</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	CRoundRect::CRoundRect(LPMofFloat pv)
		: RoundRect(pv)
	{
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// �R�s�[�R���X�g���N�^
	/// </summary>
	/// <param name="pObj">�R�s�[�p�ۋ�`</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	CRoundRect::CRoundRect(const RoundRect & pObj)
		: RoundRect(pObj)
	{
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// ��`�g��<br>
	/// Left, Top�� - e�ARight, Bottom�� + e�Athis->r�� + r���s��
	/// </summary>
	/// <param name="e">�g���T�C�Y</param>
	/// <param name="r">���a�̊g���T�C�Y</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
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
	/// ��`�g��<br>
	/// Left, Top�� - ex�ARight, Bottom�� + ey�Athis->r�� + r���s��
	/// </summary>
	/// <param name="ex">X�g���T�C�Y</param>
	/// <param name="ey">Y�g���T�C�Y</param>
	/// <param name="r">���a�̊g���T�C�Y</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
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
	/// ��`�̕��ƍ��������̂܂܂�m�ړ�����B
	/// </summary>
	/// <param name="m">�ړ���</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
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
	/// ��`�̕��ƍ��������̂܂܂�pos�̈ʒu�Ɉړ�����B
	/// </summary>
	/// <param name="pos">�ʒu</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
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
	/// ���̐ݒ�
	/// </summary>
	/// <param name="w">�ݒ肷�镝</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRect::SetWidth(const MofFloat & w)
	{
		Right = Left + w;
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// �����̐ݒ�
	/// </summary>
	/// <param name="h">�ݒ肷�鍂��</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRect::SetHeight(const MofFloat & h)
	{
		Bottom = Top + h;
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// ���a�̐ݒ�
	/// </summary>
	/// <param name="r">�ݒ肷�锼�a</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRect::SetRadius(const MofFloat & r)
	{
		this->r = r;
		CalcRectCircle();
	}

	// ********************************************************************************
	/// <summary>
	/// ���W�Ƃ̓����蔻��
	/// </summary>
	/// <param name="px">�����蔻����Ƃ�X���W</param>
	/// <param name="py">�����蔻����Ƃ�Y���W</param>
	/// <returns>�����������ǂ���</returns>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
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
	/// ���W�Ƃ̓����蔻��
	/// </summary>
	/// <param name="p">�����蔻����Ƃ���W</param>
	/// <returns>�����������ǂ���</returns>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	MofBool CRoundRect::CollisionPoint(const Vector2 & p) const
	{
		return CollisionPoint(p.x, p.y);
	}

	// ********************************************************************************
	/// <summary>
	/// �l�̐ݒ�
	/// </summary>
	/// <param name="left">��</param>
	/// <param name="top">��</param>
	/// <param name="right">�E</param>
	/// <param name="bottom">��</param>
	/// <param name="r">�p�۔��a</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
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
	/// �`��
	/// </summary>
	/// <param name="color">�`��F</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRect::Render(const MofU32 & color)
	{
		// �~�̕`��
		for (int i = 0; i < 4; i++)
		{
			if (m_CircleArray[i] == NoneCircle)
			{
				break;
			}
			CGraphicsUtilities::RenderFillCircle(m_CircleArray[i], color);
		}
		// ��`�̕`��
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
	/// ���̎擾
	/// </summary>
	/// <returns>��</returns>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	MofFloat CRoundRect::GetWidth(void) const
	{
		return Right - Left;
	}

	// ********************************************************************************
	/// <summary>
	/// �����̎擾
	/// </summary>
	/// <returns>����</returns>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	MofFloat CRoundRect::GetHeight(void) const
	{
		return Bottom - Top;
	}

	// ********************************************************************************
	/// <summary>
	/// �p�۔��a�̏���
	/// </summary>
	/// <returns>�p�۔��a</returns>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	MofFloat CRoundRect::GetRadius(void) const
	{
		return r;
	}

	// ********************************************************************************
	/// <summary>
	/// ���S���W�̎擾
	/// </summary>
	/// <returns>���S���W</returns>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	Vector2 CRoundRect::GetCenter(void) const
	{
		return Vector2((Left + Right) * 0.5f, (Top + Bottom) * 0.5f);
	}

	// ********************************************************************************
	/// <summary>
	/// RoundRect�Ƃ��Ď擾
	/// </summary>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	CRoundRect::operator sip::RoundRect(void)
	{
		return sip::RoundRect(Left, Top, Right, Bottom, r);
	}

	// ********************************************************************************
	/// <summary>
	/// �p�ۂ̌v�Z
	/// </summary>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRect::CalcRectCircle(void)
	{
		// �z��̏�����
		for (int i = 0; i < 4; i++)
		{
			m_CircleArray[i] = NoneCircle;
			if (i >= 2) continue;
			m_RectArray[i] = NoneRect;
		}

		// �����Ɣ��a�̃`�F�b�N
		bool bLessW = (GetWidth() <= r * 2);
		// �����Ɣ��a�̃`�F�b�N
		bool bLessH = (GetHeight() <= r * 2);

		// ���a�̐���
		r = MOF_CLIPING(r, 0, MOF_MIN(GetHeight(), GetWidth()) * 0.5f);

		// �����A���̗����𔼌a�������Ă���ꍇ�A�~�̂݁B
		if (bLessW && bLessH)
		{
			m_CircleArray[0] = Mof::Circle(GetCenter(), r);
		}
		// �ǂ��炩�Е������Ă���ꍇ�A�g�p����z������炷�B
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
	/// ���W�Ƃ̓����蔻��
	/// </summary>
	/// <param name="rrect">������Ƃ�p�ۋ�`</param>
	/// <param name="px">�����蔻����Ƃ�X���W</param>
	/// <param name="py">�����蔻����Ƃ�Y���W</param>
	/// <returns>�����������ǂ���</returns>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	MofBool CRoundRectUtilities::CollisionPoint(const sip::RoundRect & rrect, const MofFloat & px, const MofFloat & py)
	{
		const CRoundRect r(rrect);
		return r.CollisionPoint(px, py);
	}

	// ********************************************************************************
	/// <summary>
	/// ���W�Ƃ̓����蔻��
	/// </summary>
	/// <param name="rrect">������Ƃ�p�ۋ�`</param>
	/// <param name="p">�����蔻����Ƃ���W</param>
	/// <returns>�����������ǂ���</returns>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	MofBool CRoundRectUtilities::CollisionPoint(const sip::RoundRect & rrect, const Vector2 & p)
	{
		return CollisionPoint(rrect, p.x, p.y);
	}

	// ********************************************************************************
	/// <summary>
	/// �p�ۋ�`�̕`��
	/// </summary>
	/// <param name="rrect">�`�悷��p�ۋ�`</param>
	/// <param name="color">�`��F</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
	// ********************************************************************************
	void CRoundRectUtilities::Render(const sip::RoundRect & rrect, const MofU32 & color)
	{
		CRoundRect r(rrect);
		r.Render(color);
	}

	// ********************************************************************************
	/// <summary>
	/// �摜���p�ۋ�`�̒��ɔ[�߂ĕ`��
	/// </summary>
	/// <param name="rrect">�}�X�N�ɂȂ�p�ۋ�`</param>
	/// <param name="pTexture">�`�悷��摜�|�C���^</param>
	/// <param name="color">�`�悷��摜�̐F</param>
	/// <created>���̂���,2020/10/30</created>
	/// <changed>���̂���,2020/10/30</changed>
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
