#include "Periodic.h"

namespace sip
{

	// ********************************************************************************
	/// <summary>
	/// �T�C���g�̓���������
	/// </summary>
	/// <param name="periodSec">��������b</param>
	/// <param name="t">�o�ߎ���</param>
	/// <returns>�o�ߎ��Ԃł̗�</returns>
	/// <created>���̂���,2020/12/04</created>
	/// <changed>���̂���,2020/12/04</changed>
	// ********************************************************************************
	inline float CPeriodic::Sine0_1(const float & periodSec, const float & t)
	{
		const float x = std::fmodf(t, periodSec) / (periodSec * (1 / MOF_MATH_2PI));

		return std::sinf(x) * 0.5f + 0.5f;
	}

	// ********************************************************************************
	/// <summary>
	/// 01���݂��
	/// </summary>
	/// <param name="periodSec">��������b</param>
	/// <param name="t">�o�ߎ���</param>
	/// <returns>�o�ߎ��Ԃł̗�</returns>
	/// <created>���̂���,2020/12/04</created>
	/// <changed>���̂���,2020/12/04</changed>
	// ********************************************************************************
	inline float CPeriodic::Square0_1(const float & periodSec, const float & t)
	{
		return (std::fmodf(t, periodSec) < (periodSec * 0.5f)) ? 1.0f : 0.0f;
	}

	// ********************************************************************************
	/// <summary>
	/// �s���ċA���Ă�����
	/// </summary>
	/// <param name="periodSec">��������b</param>
	/// <param name="t">�o�ߎ���</param>
	/// <returns>�o�ߎ��Ԃł̗�</returns>
	/// <created>���̂���,2020/12/04</created>
	/// <changed>���̂���,2020/12/04</changed>
	// ********************************************************************************
	inline float CPeriodic::Triangle0_1(const float & periodSec, const float & t)
	{
		const float x = std::fmodf(t, periodSec) / (periodSec * 0.5f);

		return x <= 1.0f ? x : 2.0f - x;
	}

	// ********************************************************************************
	/// <summary>
	/// ����ʍs���(�̂�����g)
	/// </summary>
	/// <param name="periodSec">��������b</param>
	/// <param name="t">�o�ߎ���</param>
	/// <returns>�o�ߎ��Ԃł̗�</returns>
	/// <created>���̂���,2020/12/04</created>
	/// <changed>���̂���,2020/12/04</changed>
	// ********************************************************************************
	inline float CPeriodic::Sawtooth0_1(const float & periodSec, const float & t)
	{
		return std::fmodf(t, periodSec) / periodSec;
	}

	// ********************************************************************************
	/// <summary>
	/// �W�����v�I�Ȃ��
	/// </summary>
	/// <param name="periodSec">��������b</param>
	/// <param name="t">�o�ߎ���</param>
	/// <returns>�o�ߎ��Ԃł̗�</returns>
	/// <created>���̂���,2020/12/04</created>
	/// <changed>���̂���,2020/12/04</changed>
	// ********************************************************************************
	inline float CPeriodic::Jump0_1(const float & periodSec, const float & t)
	{
		float x = std::fmodf(t, periodSec) / (periodSec * 0.5f);

		if (1.0f < x)
		{
			x = 2.0f - x;
		}

		return 2 * x - (x * x);
	}
}