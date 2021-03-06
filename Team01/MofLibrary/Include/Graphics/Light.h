/*************************************************************************//*!
					
					@file	Light.h
					@brief	ライト基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__LIGHT__H__

#define		__LIGHT__H__

//INCLUDE
#include	"Graphics.h"

namespace Mof {
	
	/*******************************//*!
	@brief	ライトタイプ列挙

			ライトタイプの列挙

	@author	CDW
	*//********************************/
	typedef enum LightType {
		LIGHTTYPE_DIRECTION,					//!<平行光源
		LIGHTTYPE_POINT,						//!<点光源
		LIGHTTYPE_SPOT,							//!<スポットライト
	}LightType;
	
	/*******************************//*!
	@brief	ライト基底インターフェイス

			ライト基底となるインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API ILight : public IMofNamedObject {
	protected:
	public:
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			ライト方向設定
				@param[in]		v			方向
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetDirection(const Vector3& v) = 0;
		/*************************************************************************//*!
				@brief			ディフューズ色設定
				@param[in]		c			色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetDiffuse(const Vector4& c) = 0;
		/*************************************************************************//*!
				@brief			ディフューズ色設定
				@param[in]		c			色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetDiffuse(const MofU32 c) = 0;
		/*************************************************************************//*!
				@brief			アンビエント色設定
				@param[in]		c			色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetAmbient(const Vector4& c) = 0;
		/*************************************************************************//*!
				@brief			アンビエント色設定
				@param[in]		c			色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetAmbient(const MofU32 c) = 0;
		/*************************************************************************//*!
				@brief			スペキュラ色設定
				@param[in]		c			色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetSpeculer(const Vector4& c) = 0;
		/*************************************************************************//*!
				@brief			スペキュラ色設定
				@param[in]		c			色
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetSpeculer(const MofU32 c) = 0;
		
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			ライトタイプ取得
				@param			None

				@return			ライトタイプ
		*//**************************************************************************/
		virtual LightType GetType(void) const = 0;
		/*************************************************************************//*!
				@brief			ライト方向取得
				@param			None

				@return			ライト方向
		*//**************************************************************************/
		virtual CVector3& GetDirection(void) = 0;
		/*************************************************************************//*!
				@brief			ライト方向取得
				@param			None

				@return			ライト方向
		*//**************************************************************************/
		virtual const CVector3& GetDirection(void) const = 0;
		/*************************************************************************//*!
				@brief			ディフューズ色取得
				@param			None

				@return			ディフューズ色
		*//**************************************************************************/
		virtual CVector4& GetDiffuse(void) = 0;
		/*************************************************************************//*!
				@brief			ディフューズ色取得
				@param			None

				@return			ディフューズ色
		*//**************************************************************************/
		virtual const CVector4& GetDiffuse(void) const = 0;
		/*************************************************************************//*!
				@brief			ディフューズ色取得
				@param			None

				@return			ディフューズ色
		*//**************************************************************************/
		virtual MofU32 GetDiffuseU32(void) const = 0;
		/*************************************************************************//*!
				@brief			アンビエント色取得
				@param			None

				@return			アンビエント色
		*//**************************************************************************/
		virtual CVector4& GetAmbient(void) = 0;
		/*************************************************************************//*!
				@brief			アンビエント色取得
				@param			None

				@return			アンビエント色
		*//**************************************************************************/
		virtual const CVector4& GetAmbient(void) const = 0;
		/*************************************************************************//*!
				@brief			アンビエント色取得
				@param			None

				@return			アンビエント色
		*//**************************************************************************/
		virtual MofU32 GetAmbientU32(void) const = 0;
		/*************************************************************************//*!
				@brief			スペキュラ色取得
				@param			None

				@return			スペキュラ色
		*//**************************************************************************/
		virtual CVector4& GetSpeculer(void) = 0;
		/*************************************************************************//*!
				@brief			スペキュラ色取得
				@param			None

				@return			スペキュラ色
		*//**************************************************************************/
		virtual const CVector4& GetSpeculer(void) const = 0;
		/*************************************************************************//*!
				@brief			スペキュラ色取得
				@param			None

				@return			スペキュラ色
		*//**************************************************************************/
		virtual MofU32 GetSpeculerU32(void) const = 0;
	};
	
	//ポインタ置き換え
	typedef ILight*				LPLight;
}

#endif

//[EOF]