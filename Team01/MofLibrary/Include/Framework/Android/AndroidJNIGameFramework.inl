/*************************************************************************//*!
					
					@file	AndroidJNIGameFramework.h
					@brief	AndroidJNIでのゲームフレームワークを提供するクラス。

															@author	濱田　享
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			フレームワークハンドル取得
		@param			None
				
		@return			ハンドル
*//**************************************************************************/
FORCE_INLINE MofInstanceHandle CAndroidJNIGameFramework::GetHandle(void){
	return 0;
}
/*************************************************************************//*!
		@brief			フレームワークウインドウ取得
		@param			None
				
		@return			ウインドウ
*//**************************************************************************/
FORCE_INLINE LPWindow CAndroidJNIGameFramework::GetWindow(void){
	return NULL;
}
		
//[EOF]
