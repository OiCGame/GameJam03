#pragma once
#include "SceneDefine.h"

// ********************************************************************************
/// <summary>
/// ゲームシーンクラス
/// </summary>
// ********************************************************************************
class CGame : public MyApp::CScene
{
private:

public:

    // ********************************************************************************
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="data">共通データ</param>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    explicit CGame(const InitData& data);
    
    // ********************************************************************************
    /// <summary>
    /// デストラクタ
    /// </summary>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    ~CGame(void);

    // ********************************************************************************
    /// <summary>
    /// 初期化
    /// </summary>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    void Initialize(void);

    // ********************************************************************************
    /// <summary>
    /// 読み込み
    /// </summary>
    /// <returns>true : 成功, false : 失敗</returns>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    bool Load(void);

    // ********************************************************************************
    /// <summary>
    /// 更新
    /// </summary>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    void Update(void) override;

    // ********************************************************************************
    /// <summary>
    /// 描画
    /// </summary>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    void Render(void) override;

    // ********************************************************************************
    /// <summary>
    /// 解放
    /// </summary>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    void Release(void);
};

