#pragma once
#include	 "Mof.h"
#include	 "SceneBase.h"
#include	 "EnemyBulletManager.h"
#include	 "Player.h"
#include	"StageData.h"

enum class GameFlow {
	Enemy_SetMove,
	Enemy_Moving,
	Player_SetShot,
	Player_Shooting,
	Enemy_SetShot,
	Enemy_Shots,
};


class CSceneGame : public CSceneBase
{
private:
	// 最大ウェーブ数
	int m_MaxWave = 6;

	StageData stageData;

	// 雲の(大体の)中心座標
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
	float m_EnemySpeed[6] = { 20,20,20,20,20,20 };

	std::string m_WaveBackground[6] = {
		"wave1",
		"wave2",
		"wave3",
		"wave4",
		"wave5",
		"wave6",
	};

	CTexture* m_pCloudTexture_left;
	CTexture* m_pCloudTexture_right;
	CTexture* m_pBackgroundTexture;
	int m_WaveNo{ 0 };

	GameFlow	m_NowGameFlow{GameFlow::Enemy_SetMove};
	const float cm_WaitTime{ 20 };
	float	m_FlowWaitTime{0};

	// 音
	CSoundBuffer* m_pBGM;
	CSoundBuffer* m_pSE_Explosion;

	// UI
	std::string m_UI_LifeTexture[6] = {
		"ui_life_0",
		"ui_life_1",
		"ui_life_2",
		"ui_life_3",
		"ui_life_4",
		"ui_life_5",
	};
	CTexture* m_pUI_Life;

	std::string m_UI_WaveTexture[6] = {
		"ui_wave_1",
		"ui_wave_2",
		"ui_wave_3",
		"ui_wave_4",
		"ui_wave_5",
		"ui_wave_6",
	};
	CTexture* m_pUI_Wave;

	CFont font;

	CPlayer m_Player;
	
	void DebugKey();

	void Flow_SetEnemyMove();
	void Flow_EnemyMoving();
	void Flow_SetPlayerShot();
	void Flow_PlayerShooting();
	void Flow_SetEnemyShot();
	void Flow_EnemyShots();

	void NextWave(int wave_no);

public:
	CSceneGame(const StageData& stgData) :
		m_pBGM(NULL),
		m_pSE_Explosion(NULL),
		stageData(stgData)
	{
	};

	void Initialize() override;
	void Update()  override;
	void Render()  override;
	void RenderDebug() override;
	void Release()  override;
};

