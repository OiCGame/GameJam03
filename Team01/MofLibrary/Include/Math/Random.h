/*************************************************************************//*!
					
					@file	Random.h
					@brief	XorShiftアルゴリズムを使用した乱数生成を行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__RANDOM__H__

#define		__RANDOM__H__

//INCLUDE
#include	"MathCommon.h"
#include	"../Common/Allocator.h"

namespace Mof {
	
	/*******************************//*!
	@brief	XorShiftアルゴリズムを使用した乱数生成クラス

			XorShiftアルゴリズムを使用した乱数生成クラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CRandom : public IMofBase {
	private:
		/*******************//*!
		種
		*//********************/
		MofU32					sx;
		/*******************//*!
		種
		*//********************/
		MofU32					sy;
		/*******************//*!
		種
		*//********************/
		MofU32					sz;
		/*******************//*!
		種
		*//********************/
		MofU32					sw;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CRandom();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		s				種

				@return			None
		*//**************************************************************************/
		CRandom(MofU32 s);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj			コピーオブジェクト

				@return			None
		*//**************************************************************************/
		CRandom(const CRandom& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CRandom();

		/*************************************************************************//*!
				@brief			乱数生成
				@param			None

				@return			発生した乱数を返す
		*//**************************************************************************/
		MofU32 Random(void);
		/*************************************************************************//*!
				@brief			乱数生成<br>
								0〜引数の最大値未満の範囲の乱数が発生する
				@param[in]		h				最大値

				@return			発生した乱数を返す
		*//**************************************************************************/
		MofU32 Random(MofU32 h);
		/*************************************************************************//*!
				@brief			乱数生成<br>
								引数の最少値〜引数の最大値未満の範囲の乱数が発生する
				@param[in]		l				最少値
				@param[in]		h				最大値

				@return			発生した乱数を返す
		*//**************************************************************************/
		MofU32 Random(MofU32 l,MofU32 h);
		
		/*************************************************************************//*!
				@brief			(0.0f〜1.0f)の範囲の乱数生成
				@param			None

				@return			発生した乱数を返す
		*//**************************************************************************/
		MofFloat RandomFloat(void);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			乱数の種を設定する
				@param[in]		s				種

				@return			None
		*//**************************************************************************/
		void SetSeed(MofU32 s);
		
		//クラス基本定義
		MOF_LIBRARYCLASS(CRandom,MOF_RANDOMCLASS_ID);
	};
	
	//ポインタ置き換え
	typedef CRandom*			LPRandom;

	//INLINE INCLUDE
	#include	"Random.inl"

}

#endif

//[EOF]