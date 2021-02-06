#pragma once

#include	<Mof.h>

struct EffectStatus {
	CTexture* texture;
	CVector2	position;
	int			t{ 0 }; // 0 �� t �� 1000
	bool			end_flag{ false };
};

class CEffectManager
{
private:
	// �Ǘ��z��
	std::vector<EffectStatus> m_EffectList;

public:
	// �V���O���g��
	static CEffectManager& Singleton();

	// �e�̒P�̒ǉ�
	void addEffect(CTexture* ptex, const CVector2 & pos);

	// �S�Ă�effect���I�����Ă��� = true
	bool FinishedAll();

	// Get
	std::vector<EffectStatus>* GeteffectList();



	// �X�V
	void Update();

	// �`��
	void Render();

	// �J��
	void Release();
};

