/*************************************************************************//*!
					
					@file	ShaderEffect_CascadeVarianceRenderer.h
					@brief	シャドウマップによる影描画シェーダークラス。

															@author	CDW
															@date	2015.06.10
*//**************************************************************************/

/*************************************************************************//*!
		@brief			シェーダーエフェクトの作成。
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
FORCE_INLINE MofBool CShaderEffect_CascadeVarianceRenderer::Create(){
	return Create(TRUE);
}

//[EOF]
