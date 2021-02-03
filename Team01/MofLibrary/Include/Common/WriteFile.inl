/*************************************************************************//*!
					
					@file	WriteFile.inl
					@brief	�t�@�C���o�͂���舵���N���X

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//--------------------------------------------------------------------------------------------
//CWriteFile
//--------------------------------------------------------------------------------------------
/*************************************************************************//*!
		@brief			�t�@�C���I�t�Z�b�g���擾����
		@param			None
				
		@return			�t�@�C���I�t�Z�b�g
*//**************************************************************************/
FORCE_INLINE MofS32 CWriteFile::Tell(void){
	return m_Offset;
}
/*************************************************************************//*!
		@brief			���O�ݒ�
		@param[in]		pName			�ݒ肷�閼�O
				
		@return			TRUE			����I��<br>
						����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
*//**************************************************************************/
FORCE_INLINE MofBool CWriteFile::SetName(LPCMofChar pName){
	return m_Name.SetString(pName);
}
/*************************************************************************//*!
		@brief			���O�擾
		@param			None

		@return			���O�̎擾
*//**************************************************************************/
FORCE_INLINE LPString CWriteFile::GetName(void){
	return &m_Name;
}
/*************************************************************************//*!
		@brief			�t�@�C���|�C���^�擾
		@param			None

		@return			�t�@�C���|�C���^�̎擾
*//**************************************************************************/
FORCE_INLINE FILE* CWriteFile::GetFilePointer(void){
	return m_pFile;
}
/*************************************************************************//*!
		@brief			�t�@�C���o�b�t�@�T�C�Y�擾
		@param			None

		@return			�t�@�C���o�b�t�@�T�C�Y�̎擾
*//**************************************************************************/
FORCE_INLINE MofU32 CWriteFile::GetBufferSize(void){
	return m_Size;
}
/*************************************************************************//*!
		@brief			�t�@�C���o�b�t�@�Q�ƃI�t�Z�b�g�擾
		@param			None

		@return			�t�@�C���o�b�t�@�Q�ƃI�t�Z�b�g�̎擾
*//**************************************************************************/
FORCE_INLINE MofU32 CWriteFile::GetOffset(void){
	return m_Offset;
}

//[EOF]