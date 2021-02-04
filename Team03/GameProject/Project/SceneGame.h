#pragma once
#include	 "Mof.h"
#include	 "SceneBase.h"
#include	 "EnemyBulletManager.h"
#include	 "Player.h"

class CSceneGame : public CSceneBase
{
private:

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
		},
		// wave5
		{
			{163,	259},
			{629,	559},
			{133,	739},
			{425,	989},
			{957,	989},
			{1283,	793},
			{1677,	985},
			{1799,	695},
			{1501,	385},
			{1757,	105},
		},
		// wave6
		{
			{165,	267},
			{649,	391},
			{323,	627},
			{195,	971},
			{751,	983},
			{1021,	641},
			{1201,	283},
			{1373,	895},
			{1759,	983},
			{1729,	561},
			{1605,	189}
		}
};

	int m_EnemyCount[6] = { 1,1,2,2,3,3 };
	std::string m_WaveBackground[6] = {
		"wave1",
		"wave2",
		"wave3",
		"wave4",
		"wave5",
		"wave6",
	};

	CTexture* m_pCloudTexture;
	CTexture* m_pBackgroundTexture;
	int m_WaveNo{ 0 };

	CPlayer m_Player;
	
	void NextWave(int wave_no);

public:
	void Initialize() override;
	void Update()  override;
	void Render()  override;
	void RenderDebug() override;
	void Release()  override;
};

