#pragma once

#include	<Mof.h>

struct EffectStatus {
	CTexture* texture;
	CVector2	position;
	int			t{ 0 }; // 0 ≦ t ≦ 1000
	bool			end_flag{ false };
};

class CEffectManager
{
private:
	// 管理配列
	std::vector<EffectStatus> m_EffectList;

public:
	// シングルトン
	static CEffectManager& Singleton();

	// 弾の単体追加
	void addEffect(CTexture* ptex, const CVector2 & pos);

	// 全てのeffectが終了している = true
	bool FinishedAll();

	// Get
	std::vector<EffectStatus>* GeteffectList();



	// 更新
	void Update();

	// 描画
	void Render();

	// 開放
	void Release();
};

