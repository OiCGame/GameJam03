#pragma once
#include "GameDefine.h"

class CSceneBase
{
private:
	typedef struct {
		int					m_RemainVerticalGap = 0;
		int					m_RemainHorizontalGap = 0;
		int					m_ContinuousVerticalCount = 0;
		int					m_ContinuousHorizontalCount = 0;
	}Select_No;
	int					m_SelectGap[3] = { 25,15,5 };

	Select_No			m_Select;

protected:
	bool				m_bEnd;					// シーンの終了判定に使用
	int					m_NextSceneNo;			// 次に遷移するシーンの番号
	int					m_Scene;				// いるかどうか不明
	int					m_StageNo;				// いるかどうか不明
	CTexture			m_BackImage;			// 画像を用意できる気がしない




	int					m_SelectNo;

	void SelectVertical(int& no, int count, bool loop);
	void SelectHorizontal(int& no, int count, bool loop);

public:
	CSceneBase();
	virtual ~CSceneBase() {};
	virtual void Initialize(void) = 0;
	virtual void Update(void) = 0;
	virtual void Render(void) = 0;
	virtual void RenderDebug(void) = 0;
	virtual void Release(void) = 0;

	void SetScene(int scene) { m_Scene = scene; }
	int GetScene() { return m_Scene; }
	int GetNextScene(void) { return m_NextSceneNo; }
	int GetSelectNo() { return m_SelectNo; }
	void SetSelectNo(int no) { m_SelectNo = no; }
	bool IsEnd(void) { return m_bEnd; }

};

