/*************************************************************************//*!
					
					@file	ShaderEffect_ToonShader.h
					@brief	トゥーンレンダリングシェーダークラス。

															@author	CDW
															@date	2015.05.27
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_TOONSHADER__H__

#define		__SHADEREFFECT_TOONSHADER__H__

//INCLUDE
#include	"ShaderEffect_3DBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	マルチレンダリングによる深度テクスチャ描画シェーダークラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_ToonShader : public CShaderEffect_3DBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_ToonShader();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_ToonShader();
		
		/*************************************************************************//*!
				@brief			シェーダーエフェクトの作成。
				@param			None

				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create();
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		/*************************************************************************//*!
				@brief			開始
				@param			None
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Begin();
		/*************************************************************************//*!
				@brief			終了
				@param			None
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool End();

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			トゥーンマップテクスチャ設定
				@param[in]		pTex			トゥーンマップテクスチャ
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetToonMapTexture(LPTexture pTex);
		/*************************************************************************//*!
				@brief			マスク値設定
				@param[in]		Mask			マスク値
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetMaskValue(MofFloat Mask);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------

		//クラス基本定義
		MOF_LIBRARYCLASS(CShaderEffect_ToonShader,MOF_SHADEREFFECTTOONSHADERCLASS_ID);
	};

	// 置き換え
	typedef CShaderEffect_ToonShader*			LPShaderEffect_ToonShader;

#include	"ShaderEffect_ToonShader.inl"

}

#endif

//[EOF]