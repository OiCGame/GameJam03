#include "AnimationData.h"

namespace sip
{

	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <created>���̂���,2020/09/10</created>
	/// <changed>���̂���,2020/09/10</changed>
	// ********************************************************************************
	CAnimationData::CAnimationData(void) :
		m_pAnim(nullptr),
		m_AnimCount(0),
		m_TextureFileName("")
	{
	}

	// ********************************************************************************
	/// <summary>
	/// �R�s�[�R���X�g���N�^
	/// </summary>
	/// <param name="obj">�R�s�[����f�[�^</param>
	/// <created>���̂���,2020/09/10</created>
	/// <changed>���̂���,2020/09/10</changed>
	// ********************************************************************************
	CAnimationData::CAnimationData(const CAnimationData & obj)
	{
		m_pAnim     = obj.m_pAnim;
		m_AnimCount = obj.m_AnimCount;
	}

	// ********************************************************************************
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	/// <created>���̂���,2020/09/10</created>
	/// <changed>���̂���,2020/09/10</changed>
	// ********************************************************************************
	CAnimationData::~CAnimationData(void)
	{
		Release();
	}

	// ********************************************************************************
	/// <summary>
	/// operator=
	/// </summary>
	/// <param name="obj">�R�s�[�f�[�^</param>
	/// <created>���̂���,2020/09/10</created>
	/// <changed>���̂���,2020/09/10</changed>
	// ********************************************************************************
	void CAnimationData::operator=(const CAnimationData & obj)
	{
		m_pAnim     = obj.m_pAnim;
		m_AnimCount = obj.m_AnimCount;
	}

	// ********************************************************************************
	/// <summary>
	/// �A�j���[�V�����f�[�^���t�@�C������ǂݍ��݂��鏈���B
	/// </summary>
	/// <param name="fileName">�t�@�C����</param>
	/// <returns>����ɓǂݍ��߂��ꍇ true ����ȊO false </returns>
	/// <created>���̂���,2020/04/26</created>
	/// <changed>���̂���,2020/04/26</changed>
	// ********************************************************************************
	bool CAnimationData::Load(LPCMofChar fileName)
	{
		FILE* filePointer = fopen(fileName, "rb");

		//�t�@�C�����J���Ȃ������ꍇ�A�G���[�ő����^�[���B
		if (filePointer == NULL)
		{
			return false;
		}

		/// ###          �ǂݍ��ރf�[�^�̏��Ԃ͈ȉ��̒ʂ�          ###
		//     �E�e�N�X�`���̃t�@�C�����̒���( int   )
		//     �E�e�N�X�`���̃t�@�C����      ( char  )
		//     �E�A�j���[�V�����̐�          ( int   )
		/// ##��������A�j���[�V�����̐��������[�v
		//     �E�A�j���[�V�������̒���      ( int   )
		//     �E�A�j���[�V������            ( char  )
		//     �E�I�t�Z�b�gX                 ( float )
		//     �E�I�t�Z�b�gY                 ( float )
		//     �E����                        ( float )
		//     �E����                        ( float )
		//     �E���[�v�t���O                ( char  )
		//     �E�A�j���[�V�����p�^�[����    ( int   )
		///  #��������p�^�[���̐��������[�v
		//     �E�ҋ@�t���[��                ( float ) 
		//     �ENo                          ( int   )
		//     �EStep                        ( int   )
		///  #�����܂Ńp�^�[���̐��������[�v
		/// ##�����܂ŃA�j���[�V�����̐��������[�v
		//     �E�e�L�X�g�t�@�C�����̒���    ( int   ) #�ǂݍ��܂Ȃ�
		//     �E�e�L�X�g�t�@�C����          ( char  ) #�ǂݍ��܂Ȃ�
		//     �EEOF
		/// ###          �����܂�.anim�t�@�C��                     ###


		//�E�e�N�X�`���̃t�@�C�����̒����擾�B
		int textureFileNameLength;
		fread(&textureFileNameLength, sizeof(int), 1, filePointer);

		//�E�e�N�X�`���̃t�@�C�����̎擾�B
		char* textureFileName = new char[textureFileNameLength + 1];
		fread(textureFileName, sizeof(char), textureFileNameLength, filePointer);
	
		//�擾�����當����I�[���������ɂ���B
		textureFileName[textureFileNameLength] = '\0';

		//�����o�ϐ��ɕۑ����Ă����B
		m_TextureFileName = textureFileName;

		//���I�m�ۂ���������̂�Y��Ȃ��悤�ɁB
		MOF_SAFE_DELETE_ARRAY(textureFileName);

		//�E�A�j���[�V�����̐��擾�B
		int animationCount;
		fread(&animationCount, sizeof(int), 1, filePointer);

		//�����o�ϐ��ɕۑ����Ă����B
		m_AnimCount = animationCount;

		//�A�j���[�V�����̐������\���̂��m�ۂ���B(��d�ō쐬���Ȃ��悤�ɉ���������ɂ���B)
		MOF_SAFE_DELETE_ARRAY(m_pAnim);
		m_pAnim = new SpriteAnimationCreate[m_AnimCount];

		//�A�j���[�V�����̐��������[�v����B
		for (int i = 0; i < m_AnimCount; i++)
		{
			//�A�j���[�V�����f�[�^�̊ԐڎQ�ƁB(�Ăяo���񐔂��ŏ����ɂ��邽��)
			SpriteAnimationCreate* pAnim = &(m_pAnim[i]);

			//�A�j���[�V�������̒����擾�B
			int animNameLength;
			fread(&animNameLength, sizeof(int), 1, filePointer);

			//�A�j���[�V�������̎擾�B
			char* animName = new char[animNameLength + 1];
			fread(animName, sizeof(char), animNameLength, filePointer);

			//���O���擾�����炯�ɕ�����I�[������t����B
			animName[animNameLength] = '\0';

			//�f�[�^�ɃR�s�[����B
			pAnim->Name = animName;

			//�p���I������瑁�߂ɉ�����Ă��B
			MOF_SAFE_DELETE_ARRAY(animName);

			//�e�f�[�^�̎擾�B
			char loop;
			fread(&(pAnim->OffsetX), sizeof(float), 1, filePointer);
			fread(&(pAnim->OffsetY), sizeof(float), 1, filePointer);
			fread(&(pAnim->Width  ), sizeof(float), 1, filePointer);
			fread(&(pAnim->Height ), sizeof(float), 1, filePointer);
			fread(&loop            , sizeof(char ), 1, filePointer);
            pAnim->bLoop = loop;
            
			//�A�j���[�V�����p�^�[���̐����擾�B
			int patternCount;
			fread(&patternCount, sizeof(int), 1, filePointer);

			//�p�^�[���̐��������[�v����B
			for (int j = 0; j < patternCount; j++)
			{
				//�Ăяo���񐔂��Ȃ�ׂ����炻���B
				SpriteAnimationCreatePattern* pPattern = &(pAnim->Pattern[j]);

				//�e�f�[�^�̎擾�B
				fread(&(pPattern->Wait), sizeof(float), 1, filePointer);
				fread(&(pPattern->No  ), sizeof(int  ), 1, filePointer);
				fread(&(pPattern->Step), sizeof(int  ), 1, filePointer);
			}
		}

		//�J������߂悤�B�Y���Ȃ�B
		fclose(filePointer);

		return true;
	}

	// ********************************************************************************
	/// <summary>
	/// �A�j���[�V�����f�[�^�̉���B
	/// </summary>
	/// <created>���̂���,2020/04/26</created>
	/// <changed>���̂���,2020/04/26</changed>
	// ********************************************************************************
	void CAnimationData::Release(void)
	{
		MOF_SAFE_DELETE_ARRAY(m_pAnim);
	}

	// ********************************************************************************
	/// <summary>
	/// �A�j���[�V�����\���̂̃|�C���^�擾�B
	/// </summary>
	/// <returns>�A�j���[�V�����\���̂̃|�C���^</returns>
	/// <created>���̂���,2020/04/26</created>
	/// <changed>���̂���,2020/04/26</changed>
	// ********************************************************************************
	SpriteAnimationCreate * CAnimationData::GetAnim(void)
	{
		return m_pAnim;
	}

	// ********************************************************************************
	/// <summary>
	/// �A�j���[�V�����̐����擾����B
	/// </summary>
	/// <returns>�A�j���[�V�����̐�</returns>
	/// <created>���̂���,2020/04/26</created>
	/// <changed>���̂���,2020/04/26</changed>
	// ********************************************************************************
	int CAnimationData::GetAnimationCount(void) const
	{
		return m_AnimCount;
	}

	// ********************************************************************************
	/// <summary>
	/// �A�j���[�V�����ɑΉ������摜�t�@�C�������擾����B
	/// </summary>
	/// <returns>�摜�t�@�C����</returns>
	/// <created>���̂���,2020/04/26</created>
	/// <changed>���̂���,2020/04/26</changed>
	// ********************************************************************************
	std::string CAnimationData::GetTextureFileName(void) const
	{
		return m_TextureFileName;
	}
}
