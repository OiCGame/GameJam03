#pragma once
#include	 "Mof.h"
#include	 "SceneBase.h"
#include	 "EnemyBulletManager.h"
#include	 "Player.h"

class CSceneGame : public CSceneBase
{
private:
	CTexture* m_pCloudTexture;
	int m_WaveNo{ 0 };
	// â_ÇÃ(ëÂëÃÇÃ)íÜêSç¿ïW
	std::vector<std::vector<std::vector<int>>> m_CloudPositions = {
		// wave1
		{
			{152,	320},
			{183,	777},
			{630,	960},
			{1423,	967},
			{1795,	689},
			{1792,	275}
		},
		// wave2
		{
			{247,	341},
			{143,	793},
			{153,	1005},
			{1293,	965},
			{1741,	821},
			{1743,	926},
			{1445,	137},
		},
		// wave3
		{
			{335,	207},
			{129,	451},
			{133,	841},
			{475,	985},
			{1095,	977},
			{1625,	959},
			{1791,	723},
			{1757,	315},
			{1403,	121},
		},
		// wave4
		{
			{143,	361},
			{363,	627},
			{141,	981},
			{705,	979},
			{1331,	773},
			{1767,	989},
			{1791,	679},
			{1513,	311},
			{1779,	107},
		}

	};
	int m_EnemyCount[6] = { 1,1,2,2,3,3 };

	CPlayer m_Player;
	
	void ResetEnemies(int wave_no);

public:
	void Initialize() override;
	void Update()  override;
	void Render()  override;
	void RenderDebug() override;
	void Release()  override;
};

