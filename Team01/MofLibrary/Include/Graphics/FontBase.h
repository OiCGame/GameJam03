/*************************************************************************//*!
					
					@file	FontBase.h
					@brief	フォント基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__FONTBASE__H__

#define		__FONTBASE__H__

//INCLUDE
#include	"Font.h"

namespace Mof {
	
	/*******************************//*!
	@brief	フォント基底クラス

			フォントの読み込み、設定を行うための基底クラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CFontBase : public IFont {
	protected:
		/*******************//*!
		フォントサイズ
		*//********************/
		MofS32					m_Size;
		/*******************//*!
		太さ
		*//********************/
		MofS32					m_Bold;
		/*******************//*!
		斜体
		*//********************/
		MofBool					m_bItalic;
		/*******************//*!
		下線
		*//********************/
		MofBool					m_bUnderline;
		/*******************//*!
		打消し線
		*//********************/
		MofBool					m_bStrikeOut;
		/*******************//*!
		フォントタイプ
		*//********************/
		CString					m_Face;
		/*******************//*!
		フォントタイプ
		*//********************/
		MofU32					m_DefaultColor;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CFontBase();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CFontBase();
		
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderFormatString(MofFloat px,MofFloat py,LPCMofChar pText,...);
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		px			描画X座標
				@param[in]		py			描画Y座標
				@param[in]		col			描画色
				@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderFormatString(MofFloat px,MofFloat py,MofU32 col,LPCMofChar pText,...);
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		drec		描画矩形
				@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderFormatString(Rectangle& drec,LPCMofChar pText,...);
		/*************************************************************************//*!
				@brief			文字描画
				@param[in]		drec		描画矩形
				@param[in]		col			描画色
				@param[in]		pText		描画文字列、可変引数によるフォーマット指定
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool RenderFormatString(Rectangle& drec,MofU32 col,LPCMofChar pText,...);

		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			名前設定
				@param[in]		pName			設定する名前
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetName(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			サイズ設定
				@param[in]		s				サイズ
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetSize(MofS32 s);
		/*************************************************************************//*!
				@brief			太さ設定
				@param[in]		s				太さ
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetBold(MofS32 s);
		/*************************************************************************//*!
				@brief			斜体設定
				@param[in]		bi				斜体
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetItalic(MofBool bi);
		/*************************************************************************//*!
				@brief			下線設定
				@param[in]		bi				下線
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetUnderline(MofBool bi);
		/*************************************************************************//*!
				@brief			打消し線設定
				@param[in]		bi				打消し線
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetStrikeOut(MofBool bi);
		/*************************************************************************//*!
				@brief			基本色設定
				@param[in]		c				色
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetDefaultColor(MofU32 c);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			名前取得
				@param			None

				@return			名前の取得
		*//**************************************************************************/
		virtual LPString GetName(void);
		/*************************************************************************//*!
				@brief			フォントサイズ取得
				@param			None

				@return			フォントサイズ
		*//**************************************************************************/
		virtual MofS32 GetSize(void);
		/*************************************************************************//*!
				@brief			フォント太さ取得
				@param			None

				@return			フォント太さ
		*//**************************************************************************/
		virtual MofS32 GetBold(void);
		/*************************************************************************//*!
				@brief			フォント斜体取得
				@param			None

				@return			フォント斜体
		*//**************************************************************************/
		virtual MofBool GetItalic(void);
		/*************************************************************************//*!
				@brief			フォント下線取得
				@param			None

				@return			フォント下線
		*//**************************************************************************/
		virtual MofBool GetUnderline(void);
		/*************************************************************************//*!
				@brief			フォント打消し線取得
				@param			None

				@return			フォント打消し線
		*//**************************************************************************/
		virtual MofBool GetStrikeOut(void);
		/*************************************************************************//*!
				@brief			フォントタイプ名取得
				@param			None

				@return			フォントタイプ名
		*//**************************************************************************/
		virtual LPString GetFontFace(void);
	};
	
	//INCLUDE
	#include	"FontBase.inl"

}

//[EOF]

#endif