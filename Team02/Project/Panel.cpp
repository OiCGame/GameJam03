
#include	"Panel.h"

CPanel::CPanel() {
}

CPanel::~CPanel() {
}

void CPanel::Initialize(int stagenum) {
	m_StgNum = stagenum;
	Release();	//��x�f�ނ̊J��������
	switch (m_StgNum) {		//�X�e�[�W�ԍ��ɉ����ă��[�h����g��ύX(3���p��)
	case STAGE1:			//�擾����png�����ׂē����T�C�Y�̏ꍇ�͂��̂܂܂ł悫���A�Ⴄ�ꍇRender�̏C�����K�{
		m_PanelTexture.Load("UI/�Q�[���{��/��g.png");
		m_JudgeCnt = STG1JUDGECNT;
		//�e�p�l���́u�e���͂܂����v�����false
		for (int i = 0; i < STG1JUDGECNT; i++) {
			m_SingleOk[i] = false;
			m_SingleConfirm[i] = false;
		}
		break;
	case STAGE2:
		m_PanelTexture.Load("UI/�Q�[���{��/��g2.png");
		m_JudgeCnt = STG2JUDGECNT;
		for (int i = 0; i < STG1JUDGECNT; i++) {
			m_SingleOk[i] = false;
			m_SingleConfirm[i] = false;
		}
		break;
	case STAGE3:
		m_PanelTexture.Load("UI/�Q�[���{��/��g3.png");
		m_JudgeCnt = STG3JUDGECNT;
		for (int i = 0; i < STG1JUDGECNT; i++) {
			m_SingleOk[i] = false;
			m_SingleConfirm[i] = false;
		}
		break;
	}
	�O�pTexture.Load("UI/�Q�[���{��/�~�j�O�p�u���b�N.png");
	�l�pTexture.Load("UI/�Q�[���{��/�~�j�l�p�u���b�N.png");
	m_Clear = false;
	for (int i = 0; i < STG1JUDGECNT; i++)
	{
		m_SingleOk[i] = false;
	}
}

void CPanel::Update(CRectangle rec, float px, int bt) {
	//�����ڐG����t���O��false
	m_MultiCollision = false;
	switch (m_StgNum) {
	case STAGE1:
		for (int i = 0; i < STG1JUDGECNT; i++) {
			// �e��g�p�l���Ƒł��o���ꂽ�e�Ƃ̓����蔻��ƁA�p�l���̎�ނƒe�̎�ނ���v����Ȃ�...
			if (SingleRect_Stg1[i].CollisionRect(rec) &&
				SingleState_Stg1[i] == bt) {
				// i > 0�ł�������ł��Ȃ�����
				// ���ɁA�ڐG���肪�o�Ă���( i - 1 �Ԗڂ��ڐG������N�����Ă����ꍇ)
				if (m_MultiCollision && i > 0) {
					// ����̔���́uX���W�ƑO���X���W�Ƃ̐�Βl�v���ׁA����̕������Ȃ����(�߂����)���L�̏������s��
					m_JdgA = FrontLine_Stg1[i] - px;
					m_JdgB = FrontLine_Stg1[i - 1] - px;
					if (abs(m_JdgA) <= abs(m_JdgB)) {
						m_SingleOk[i] = true;
						m_SingleOk[i - 1] = false;	// �O��(i - 1)�œ���m_SingleOk��false�ɂ���...
					}
				}
				else {
					m_MultiCollision = true;
					m_SingleOk[i] = true;
				}
			}
		}
		break;
	case STAGE2:
		for (int i = 0; i < STG2JUDGECNT; i++) {
			if (SingleRect_Stg2[i].CollisionRect(rec)/* &&
				SingleState_Stg2[i] == bt*/) {

			}
		}
		break;
	case STAGE3:
		for (int i = 0; i < STG3JUDGECNT; i++) {
			if (SingleRect_Stg3[i].CollisionRect(rec)/* &&
				SingleState_Stg3[i] == bt*/) {

			}
		}
		break;
	}
	for (int i = 0; i < STG1JUDGECNT; i++) {
		if (m_SingleOk[i]) {
			m_SingleConfirm[i] = true;
		}
	}

	CheckClear();

	//Debug
	if (g_pInput->IsKeyPush(MOFKEY_NUMPAD1))
	{
		m_SingleOk[0] = true;
	}
	if (g_pInput->IsKeyPush(MOFKEY_NUMPAD2))
	{
		for (int i = 0; i < STG1JUDGECNT; i++)
		{
			m_SingleOk[i] = true;
		}
	}
}

void CPanel::Render(void) {
	switch (m_StgNum) {
	case STAGE1:
		//�ʒu�𒆉��ɏC���A��ʏ㕔��UI��\������̂ňʒu�ύX by �[�R 2021/02/03 14:03
		m_PanelTexture.Render((g_pGraphics->GetTargetWidth() - m_PanelTexture.GetWidth()) * 0.5, 130);
		for (int i = 0; i < STG1JUDGECNT; i++)
		{
			if (m_SingleOk[i])
			{
				�l�pTexture.Render(SinglePos_Stg1[i].x + (245 - (float)�l�pTexture.GetWidth()) * 0.5f,
					SinglePos_Stg1[i].y + (259 - (float)�l�pTexture.GetHeight()) * 0.5f);
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

	CGraphicsUtilities::RenderString(0,1000, "�`��ʒu X �F %f", SinglePos_Stg1[0].x + (245 - �l�pTexture.GetWidth()) * 0.5f);
}

void CPanel::Release(void) {
	m_PanelTexture.Release();
	//�ꎞ�I�Ȃ��́A�L�q�ύX�̌�폜���邱��
	�l�pTexture.Release();
	�O�pTexture.Release();
}

void CPanel::CheckClear()
{
	int count = 0;
	for (int i = 0; i < STG1JUDGECNT; i++)
	{
		if (m_SingleOk[i])
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
