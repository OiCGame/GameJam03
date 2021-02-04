
#include	"Panel.h"

CPanel::CPanel() {
}

CPanel::~CPanel() {
}

void CPanel::SetTexture(CTexture ** pTextureArray)
{
    m_pTryangleTexture = pTextureArray[0];
    m_pSquareTexture = pTextureArray[1];
}

void CPanel::Initialize(int stagenum) {
	m_StgNum = stagenum;
	Release();	//一度素材の開放を挟む
	switch (m_StgNum) {		//ステージ番号に応じてロードする枠を変更(3つ分用意)
	case STAGE1:			//取得するpngがすべて同じサイズの場合はこのままでよきが、違う場合Renderの修正が必須
		m_PanelTexture.Load("UI/ゲーム本編/上枠.png");
		m_JudgeCnt = STG1JUDGECNT;
		//各パネルの「弾がはまった」判定をfalse
		for (int i = 0; i < STG1JUDGECNT; i++) {
			m_SingleOk[i] = false;
			m_SingleConfirm[i] = false;
			//全て四角のためRotate情報はどれでもいい
			m_Rotate[i][STAGE1] = Up;
		}
		break;
	case STAGE2:
		m_PanelTexture.Load("UI/ゲーム本編/上枠2.png");
		m_JudgeCnt = STG2JUDGECNT;
		for (int i = 0; i < STG1JUDGECNT; i++) {
			m_SingleOk[i] = false;
			m_SingleConfirm[i] = false;
		}
		break;
	case STAGE3:
		m_PanelTexture.Load("UI/ゲーム本編/上枠3.png");
		m_JudgeCnt = STG3JUDGECNT;
		for (int i = 0; i < STG1JUDGECNT; i++) {
			m_SingleOk[i] = false;
			m_SingleConfirm[i] = false;
		}
		break;
	}
	m_Clear = false;
	for (int i = 0; i < STG1JUDGECNT; i++)
	{
		m_SingleOk[i] = false;
	}
}

void CPanel::Update() {
	
	for (int i = 0; i < STG1JUDGECNT; i++) {
		if (m_SingleOk[i]) {
			m_SingleConfirm[i] = true;
		}
	}

	//Debug
	if (g_pInput->IsKeyPush(MOFKEY_NUMPAD1))
	{
		m_SingleConfirm[0] = true;
	}
	if (g_pInput->IsKeyPush(MOFKEY_NUMPAD2))
	{
		for (int i = 0; i < STG1JUDGECNT; i++)
		{
			m_SingleConfirm[i] = true;
		}
	}
	CheckClear();
}

void CPanel::Render(void) {
	switch (m_StgNum) {
	case STAGE1:
		//位置を中央に修正、画面上部にUIを表示するので位置変更 by 深山 2021/02/03 14:03
		m_PanelTexture.Render((g_pGraphics->GetTargetWidth() - m_PanelTexture.GetWidth()) * 0.5, 130);
		for (int i = 0; i < STG1JUDGECNT; i++)
		{
			if (m_SingleConfirm[i])
			{
                m_pSquareTexture->Render(SinglePos_Stg1[i].x + (245 - (float)m_pSquareTexture->GetWidth()) * 0.5f,
					SinglePos_Stg1[i].y + (259 - (float)m_pSquareTexture->GetHeight()) * 0.5f);
			}
		}
		break;
	case STAGE2:
		break;
	case STAGE3:
		break;
	}
}

void CPanel::RenderDebug(void) {
	// DEBUG
	switch (m_StgNum) {
	case STAGE1:
		for (int i = 0; i < STG1JUDGECNT; i++) {
			//m_SingleOk[i] = true;
			if (m_SingleConfirm[i]) {
				CGraphicsUtilities::RenderFillRect(SingleRect_Stg1[i], MOF_COLOR_RED);
			}
		}
		break;
	case STAGE2:
		for (int i = 0; i < STG2JUDGECNT; i++) {
			if (m_SingleOk[i]) {
				CGraphicsUtilities::RenderFillRect(SingleRect_Stg2[i], MOF_COLOR_BLACK);
			}
		}
		break;
	case STAGE3:
		for (int i = 0; i < STG3JUDGECNT; i++) {
			if (m_SingleOk[i]) {
				CGraphicsUtilities::RenderFillRect(SingleRect_Stg3[i], MOF_COLOR_BLACK);
			}
		}
		break;
	}

	CGraphicsUtilities::RenderString(0,1000, "描画位置 X ： %f", SinglePos_Stg1[0].x + (245 - m_pSquareTexture->GetWidth()) * 0.5f);
}

void CPanel::Release(void) {
	m_PanelTexture.Release();
	//一時的なもの、記述変更の後削除すること
    m_pSquareTexture = nullptr;
	m_pTryangleTexture= nullptr;
}

void CPanel::CheckClear()
{
	int count = 0;
	for (int i = 0; i < STG1JUDGECNT; i++)
	{
		if (m_SingleConfirm[i])
		{
			count++;
		}
	}
	if (count == STG1JUDGECNT)
	{
		m_Clear = true;
	}
	else
	{
		m_Clear = false;
	}
}

bool CPanel::CheckHitCollision(CRectangle rec, float px, int bt , int rotate)
{
	//戻り値用
	bool IsHit = false;
	//複数接触判定フラグをfalse
	m_MultiCollision = false;
	switch (m_StgNum) {
	case STAGE1:
		for (int i = 0; i < STG1JUDGECNT; i++) {
			// 各上枠パネルと打ち出された弾との当たり判定と、パネルの種類と弾の種類が一致するなら...
			if (SingleRect_Stg1[i].CollisionRect(rec) &&
				SingleState_Stg1[i] == bt) {
				
				//ネストが深くなりすぎているため対策したい
				if (SingleState_Stg1[i] != Square)
				{
					if (m_Rotate[i][STAGE1] != rotate)
					{
						continue;
					}
				}

				if (m_SingleConfirm[i])
				{
					continue;
				}

				// i > 0でしか判定できない処理
				// 既に、接触判定が出ていた( i - 1 番目が接触判定を起こしていた場合)
				if (m_MultiCollision && i > 0) {
					// 今回の判定の「X座標と前回のX座標との絶対値」を比べ、今回の方が少なければ(近ければ)下記の処理を行う
					m_JdgA = FrontLine_Stg1[i] - px;
					m_JdgB = FrontLine_Stg1[i - 1] - px;
					if (abs(m_JdgA) <= abs(m_JdgB)) {
						m_SingleOk[i] = true;
						m_SingleOk[i - 1] = false;	// 前回(i - 1)で得たm_SingleOkをfalseにする...
					}
				}
				else {
					m_MultiCollision = true;
					m_SingleOk[i] = true;
				}
				IsHit = true;
			}
		}
		return IsHit;
	case STAGE2:
		for (int i = 0; i < STG2JUDGECNT; i++) {
			if (SingleRect_Stg2[i].CollisionRect(rec)/* &&
				SingleState_Stg2[i] == bt*/) {

			}
		}
		return IsHit;
	case STAGE3:
		for (int i = 0; i < STG3JUDGECNT; i++) {
			if (SingleRect_Stg3[i].CollisionRect(rec)/* &&
				SingleState_Stg3[i] == bt*/) {

			}
		}
		return IsHit;
	}
}
