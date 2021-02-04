#pragma once
#include "Mof.h"
#include "MyTime.h"

namespace sip
{
	// ********************************************************************************
	/// <summary>
	/// 定期的な値を取得するスタティッククラス
	/// </summary>
	// ********************************************************************************
	class CPeriodic
	{
	private:
		
		CPeriodic(void) = delete;
		~CPeriodic(void) = delete;

	public:
		// ********************************************************************************
		/// <summary>
		/// サイン波の動きするやつ
		/// </summary>
		/// <param name="periodSec">周期する秒</param>
		/// <param name="t">経過時間</param>
		/// <returns>経過時間での量</returns>
		/// <created>いのうえ,2020/12/04</created>
		/// <changed>いのうえ,2020/12/04</changed>
		// ********************************************************************************
		inline static float Sine0_1(const float& periodSec, const float& t = CMyTime::Time());

		// ********************************************************************************
		/// <summary>
		/// 01交互やつ
		/// </summary>
		/// <param name="periodSec">周期する秒</param>
		/// <param name="t">経過時間</param>
		/// <returns>経過時間での量</returns>
		/// <created>いのうえ,2020/12/04</created>
		/// <changed>いのうえ,2020/12/04</changed>
		// ********************************************************************************
		inline static float Square0_1(const float& periodSec, const float& t = CMyTime::Time());
		
		// ********************************************************************************
		/// <summary>
		/// 行って帰ってくるやつ
		/// </summary>
		/// <param name="periodSec">周期する秒</param>
		/// <param name="t">経過時間</param>
		/// <returns>経過時間での量</returns>
		/// <created>いのうえ,2020/12/04</created>
		/// <changed>いのうえ,2020/12/04</changed>
		// ********************************************************************************
		inline static float Triangle0_1(const float& periodSec, const float& t = CMyTime::Time());

		// ********************************************************************************
		/// <summary>
		/// 一方通行やつ(のこぎり波)
		/// </summary>
		/// <param name="periodSec">周期する秒</param>
		/// <param name="t">経過時間</param>
		/// <returns>経過時間での量</returns>
		/// <created>いのうえ,2020/12/04</created>
		/// <changed>いのうえ,2020/12/04</changed>
		// ********************************************************************************
		inline static float Sawtooth0_1(const float& periodSec, const float& t = CMyTime::Time());

		// ********************************************************************************
		/// <summary>
		/// ジャンプ的なやつ
		/// </summary>
		/// <param name="periodSec">周期する秒</param>
		/// <param name="t">経過時間</param>
		/// <returns>経過時間での量</returns>
		/// <created>いのうえ,2020/12/04</created>
		/// <changed>いのうえ,2020/12/04</changed>
		// ********************************************************************************
		inline static float Jump0_1(const float& periodSec, const float& t = CMyTime::Time());
	};
}

#include "Periodic.inl"