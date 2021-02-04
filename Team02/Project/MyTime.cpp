#include "MyTime.h"

namespace sip
{
	// ********************************************************************************
	/// <summary>
	/// 起動時に呼び出しておく。プログラムが起動した時間の取得
	/// </summary>
	/// <returns>プログラムが起動した時間</returns>
	/// <created>いのうえ,2020/12/07</created>
	/// <changed>いのうえ,2020/12/07</changed>
	// ********************************************************************************
	std::chrono::system_clock::duration CMyTime::InitTime(void)
	{
		static auto init = std::chrono::system_clock::now().time_since_epoch();
		return init;
	}

	// ********************************************************************************
	/// <summary>
	/// 現在のシステム時間の取得
	/// </summary>
	/// <returns>現在のシステム時間</returns>
	/// <created>いのうえ,2020/12/07</created>
	/// <changed>いのうえ,2020/12/07</changed>
	// ********************************************************************************
	std::chrono::system_clock::duration CMyTime::NowTime(void)
	{
		return std::chrono::system_clock::now().time_since_epoch();
	}

	// ********************************************************************************
	/// <summary>
	/// 起動してからの経過時間の取得(秒)
	/// </summary>
	/// <returns>起動してからの経過時間(秒)</returns>
	/// <created>いのうえ,2020/12/07</created>
	/// <changed>いのうえ,2020/12/07</changed>
	// ********************************************************************************
	float CMyTime::Time(void)
	{
		auto elapsed = NowTime() - InitTime();
		auto millisec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed);
		auto t = millisec.count();
		return (float)t / 1000.0f;
	}
}