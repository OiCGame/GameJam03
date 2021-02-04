#include "MyTime.h"

namespace sip
{
	// ********************************************************************************
	/// <summary>
	/// �N�����ɌĂяo���Ă����B�v���O�������N���������Ԃ̎擾
	/// </summary>
	/// <returns>�v���O�������N����������</returns>
	/// <created>���̂���,2020/12/07</created>
	/// <changed>���̂���,2020/12/07</changed>
	// ********************************************************************************
	std::chrono::system_clock::duration CMyTime::InitTime(void)
	{
		static auto init = std::chrono::system_clock::now().time_since_epoch();
		return init;
	}

	// ********************************************************************************
	/// <summary>
	/// ���݂̃V�X�e�����Ԃ̎擾
	/// </summary>
	/// <returns>���݂̃V�X�e������</returns>
	/// <created>���̂���,2020/12/07</created>
	/// <changed>���̂���,2020/12/07</changed>
	// ********************************************************************************
	std::chrono::system_clock::duration CMyTime::NowTime(void)
	{
		return std::chrono::system_clock::now().time_since_epoch();
	}

	// ********************************************************************************
	/// <summary>
	/// �N�����Ă���̌o�ߎ��Ԃ̎擾(�b)
	/// </summary>
	/// <returns>�N�����Ă���̌o�ߎ���(�b)</returns>
	/// <created>���̂���,2020/12/07</created>
	/// <changed>���̂���,2020/12/07</changed>
	// ********************************************************************************
	float CMyTime::Time(void)
	{
		auto elapsed = NowTime() - InitTime();
		auto millisec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed);
		auto t = millisec.count();
		return (float)t / 1000.0f;
	}
}