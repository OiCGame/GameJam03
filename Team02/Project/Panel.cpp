
#include	"Panel.h"

CPanel::CPanel() {
}

CPanel::~CPanel() {
}

void CPanel::SetTexture(CTexture ** pTextureArray)
{
    m_pBlletTexture[0] = pTextureArray[0];
    m_pBlletTexture[1] = pTextureArray[1];
}

void CPanel::Initialize(int stagenum) {
	
	m_bClear = false;
}

bool CPanel::Load(LPCMofChar pFile)
{
    FILE* fp = fopen(pFile, "rb");
    if (fp == NULL)
    {
        return false;
    }
    // �t�@�C���\��
    // int �p�l����
    // for(�p�l�������[�v)
    // int �摜�ԍ�(0:�O�p 1:�l�p -1:margin)
    // int ��]����(0 ~ 3)
    // int �]��

    int datacount;
    fread(&datacount, sizeof(int), 1, fp);
    for (int i = 0; i < datacount; i++)
    {
        Panel data;
        fread(&data.texNo , sizeof(int), 1, fp);
        fread(&data.rotate, sizeof(int), 1, fp);
        fread(&data.margin, sizeof(int), 1, fp);
        m_PanelArray.Add(data);
    }

    fclose(fp);
    
    CUtilities::SetCurrentDirectory("UI/�Q�[���{��");
    m_PanelTexture[0].Load("�O�p�x�[�X.png");
    m_PanelTexture[1].Load("�l�p�x�[�X.png");
    CUtilities::SetCurrentDirectory("../../");
    return true;
}

void CPanel::Update() {
	
	CheckClear();
}

void CPanel::Render(void) {
    // �p�l����
    const int panelArrayCont = m_PanelArray.GetArrayCount();
    const float offsetX = (g_pGraphics->GetTargetWidth() - GetPanelWidth()) * 0.5f;
    float posx = offsetX;
    for (int i = 0; i < panelArrayCont; i++)
    {
        // �摜�̓Y�������画��ʒu�̌v�Z
        int texNo = m_PanelArray[i].texNo;
        if (texNo != -1)
        {
            posx += m_PanelTexture[texNo].GetWidth() * 0.5f;
            posx += m_PanelArray[i].margin;
        }
        else
        {
            posx += m_PanelArray[i].margin;
            continue;
        }
        m_PanelTexture[texNo].RenderRotate(posx, PanelCenterY, MOF_ToRadian(90 * m_PanelArray[i].rotate), TEXALIGN_CENTERCENTER);
        posx += m_PanelTexture[texNo].GetWidth() * 0.5f;
    }

    const int bulletCount = m_BulletArray.GetArrayCount();
    for (int i = 0; i < bulletCount; i++)
    {
        m_BulletArray[i].second.Render();
    }
}

void CPanel::RenderDebug(void) {
	// DEBUG
    // �p�l����
    const int panelArrayCont = m_PanelArray.GetArrayCount();
    // �J�n�I�t�Z�b�g�ʒu
    const float offsetX = (g_pGraphics->GetTargetWidth() - GetPanelWidth()) * 0.5f;
    float posx = offsetX;
    for (int i = 0; i < panelArrayCont; i++)
    {
        // �摜�̓Y�������画��ʒu�̌v�Z
        int texNo = m_PanelArray[i].texNo;
        if (texNo != -1)
        {
            posx += m_PanelTexture[texNo].GetWidth() * 0.5f;
            posx += m_PanelArray[i].margin;
        }
        else
        {
            posx += m_PanelArray[i].margin;
            continue;
        }
        // �����蔻��p�~�̍쐬
        const float radius = m_PanelTexture[0].GetHeight() * 0.3f;
        CCircle cir(posx, PanelCenterY, radius);
        CGraphicsUtilities::RenderCircle(cir, MOF_COLOR_GREEN);
        posx += m_PanelTexture[texNo].GetWidth() * 0.5f;
    }
}

void CPanel::Release(void) {
	//�ꎞ�I�Ȃ��́A�L�q�ύX�̌�폜���邱��
    m_pBlletTexture[0] = nullptr;
    m_pBlletTexture[1] = nullptr;
	m_PanelTexture[0].Release();
	m_PanelTexture[1].Release();
}

float CPanel::GetPanelWidth(void)
{
    float w = 0;
    int panelArrayCont = m_PanelArray.GetArrayCount();
    for (int i = 0; i < panelArrayCont; i++)
    {
        int texNo = m_PanelArray[i].texNo;
        if (texNo != -1)
        {
            w += m_PanelTexture[texNo].GetWidth();
        }
        w += m_PanelArray[i].margin;
    }
    return w;
}

void CPanel::CheckClear()
{
    const int panelCount = m_PanelArray.GetArrayCount();
    const int bulletCount = m_BulletArray.GetArrayCount();
    m_bClear = (panelCount == bulletCount);
}

int CPanel::CheckHitCollision(CBullet& bullet)
{
    // �p�l����
    const int panelArrayCount = m_PanelArray.GetArrayCount();
    // �J�n�I�t�Z�b�g�ʒu
    const float offsetX = (g_pGraphics->GetTargetWidth() - GetPanelWidth()) * 0.5f;
    float posx = offsetX;
    for (int i = 0; i < panelArrayCount; i++)
    {
        // �摜�̓Y�������画��ʒu�̌v�Z
        int texNo = m_PanelArray[i].texNo;
        if (texNo != -1)
        {
            posx += m_PanelTexture[texNo].GetWidth() * 0.5f;
            posx += m_PanelArray[i].margin;
        }
        else
        {
            posx += m_PanelArray[i].margin;
            continue;
        }
        // �����蔻��p�~�̍쐬
        const float radius = m_PanelTexture[0].GetHeight() * 0.3f;
        CCircle cir(posx, PanelCenterY, radius);
        // �e�ƃp�l���̓����蔻��
        if (cir.CollisionCircle(bullet.GetCollisionCircle()) &&
            m_PanelArray[i].texNo  == bullet.GetBulletType())
        {
			if (m_PanelArray[i].rotate != bullet.GetRotate() &&
				m_PanelArray[i].texNo != Square)
			{
				continue;
			}
            // ���łɖ��܂��Ă��邩�̃`�F�b�N
            const int bulletCount = m_BulletArray.GetArrayCount();
            for (int j = 0; j < bulletCount; j++)
            {
                if (i == m_BulletArray[j].first)
                {
                    return -1;
                }
            }
            // �������Ă���΃p�l���ɒe����ǉ�
            m_BulletArray.Add(std::pair<int,CBullet>(i, CBullet()));
            m_BulletArray.GetDataAddress(bulletCount)->second.Create(m_pBlletTexture[texNo], posx, PanelCenterY, bullet.GetBulletType(), bullet.GetRotate());
            return i;
        }
        posx += m_PanelTexture[texNo].GetWidth() * 0.5f;
    }
    return -1;
}

CVector2 CPanel::GetPanelPosition(int panelnum)
{
    // �p�l����
    const int panelArrayCont = m_PanelArray.GetArrayCount();
    // �J�n�I�t�Z�b�g�ʒu
    const float offsetX = (g_pGraphics->GetTargetWidth() - GetPanelWidth()) * 0.5f;
    float posx = offsetX;
    for (int i = 0; i < panelArrayCont; i++)
    {
        // �摜�̓Y�������画��ʒu�̌v�Z
        int texNo = m_PanelArray[i].texNo;
        if (texNo != -1)
        {
            posx += m_PanelTexture[texNo].GetWidth() * 0.5f;
            posx += m_PanelArray[i].margin;
        }
        else
        {
            posx += m_PanelArray[i].margin;
            continue;
        }
        if (i == panelnum)
        {
	        return Vector2(posx, PanelCenterY);
        }
        posx += m_PanelTexture[texNo].GetWidth() * 0.5f;
    }

	return Vector2(-1, -1);
}
