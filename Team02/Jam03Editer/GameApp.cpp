/*************************************************************************//*!

					@file	GameApp.cpp
					@brief	基本ゲームアプリ。

															@author	濱田　享
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"
#include "Image.h"
#include "FileDialog.h"
#include "Button.h"

constexpr int PanelCenterY = 260;

CImage g_BackImage;
std::string g_OpenFileName = "";
CButton g_BtnAdd;
CButton g_BtnClear;

int g_BlockCount = 1;

enum BlockType
{
    BT_Triangle,
    BT_Squere,

    BT_MaxCount,
};

struct Panel
{
    int     rotate = 0;
    int     texNo  = 1;
    int     margin = 0;

    Panel(void) = default;

    Panel(int r, int t, int m) : rotate(r), texNo(t), margin(m)
    {
    }
};

CDynamicArray<Panel> g_StageData;

CFont g_Font;

CTexture g_Panel[BT_MaxCount];
CTexture g_BtnPlate;
CTexture g_ClearTexture;
CTexture g_AddTexture;

const Panel PanelInfo[6] = 
{
    Panel(0,  1,  0),
    Panel(0,  0,  0),
    Panel(1,  0,  0),
    Panel(2,  0,  0),
    Panel(3,  0,  0),
    Panel(0, -1, 10),
};

const Vector2 SceneSize(1280, 720);

const Vector2 WindowSize(1920, 1080);

const Vector2 ResizeScale = SceneSize / WindowSize;

int g_SelectNo = 0;
int g_DataSelectNo = -1;


float GetPanelWidth(void)
{
    float w = 0;
    int panelArrayCont = g_StageData.GetArrayCount();
    for (int i = 0; i < panelArrayCont; i++)
    {
        int texNo = g_StageData[i].texNo;
        if (texNo != -1)
        {
            w += g_Panel[texNo].GetWidth() * ResizeScale.x;
        }
        w += g_StageData[i].margin * ResizeScale.x;
    }
    return w;
}

/*************************************************************************//*!
		@brief			アプリケーションの初期化
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void) {

    sip::CFileDialog::SetProjectDirectory(CUtilities::GetCurrentDirectory());

    CUtilities::SetCurrentDirectory("EditorResource");

    {

        FILE* fp = fopen("stage_data1.stage", "wb");

        int datacount = 7;
        fwrite(&datacount, sizeof(int), 1, fp);
        for (int i = 0; i < datacount; i++)
        {
            Panel data;
            fwrite(&data.texNo, sizeof(int), 1, fp);
            fwrite(&data.rotate, sizeof(int), 1, fp);
            fwrite(&data.margin, sizeof(int), 1, fp);
        }
        fclose(fp);


        fp = fopen("stage_data2.stage", "wb");

        datacount = 4;
        Panel data;
        data.texNo = 0;
        fwrite(&datacount, sizeof(int), 1, fp);
        for (int i = 0; i < datacount; i++)
        {
            fwrite(&data.texNo , sizeof(int), 1, fp);
            fwrite(&data.rotate, sizeof(int), 1, fp);
            fwrite(&data.margin, sizeof(int), 1, fp);
            data.rotate++;
        }
        fclose(fp);
    }
    g_Panel[0].Load("三角ベース.png");
    g_Panel[1].Load("四角ベース.png");
    g_BtnPlate.Load("プレート5.png");
    g_ClearTexture.Load("クリア.png");
    g_AddTexture.Load("追加.png");
    g_BtnAdd.Initialize(Vector2(500, 600), &g_BtnPlate, &g_AddTexture, Vector2(0.5f, 0.5f));
    g_BtnClear.Initialize(Vector2(800, 600), &g_BtnPlate, &g_ClearTexture, Vector2(0.5f, 0.5f));

    g_BackImage.Load("背景.png");
    g_BackImage.SetMoveEnable(false);

    Vector2 scale = SceneSize / WindowSize;
    g_BackImage.SetScale(Vector3(scale.x, scale.y, 1.0f));
	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの更新
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Update(void) {
	//キーの更新
	g_pInput->RefreshKey();

    g_BackImage.Update();

    if (g_BtnAdd.IsPull())
    {
        g_DataSelectNo = g_StageData.GetArrayCount();
        Panel data = PanelInfo[g_SelectNo];
        g_StageData.Add(data);
    }
    if (g_BtnClear.IsPull())
    {
        g_StageData.Delete(g_DataSelectNo);
        g_DataSelectNo = MOF_CLIPING(g_DataSelectNo, -1, g_StageData.GetArrayCount() - 1);
    }
    if (g_DataSelectNo != -1)
    {
        if (g_pInput->IsKeyHold(MOFKEY_LEFT))
        {
            g_StageData[g_DataSelectNo].margin--;
        }
        if (g_pInput->IsKeyHold(MOFKEY_RIGHT))
        {
            g_StageData[g_DataSelectNo].margin++;
        }
    }

    if (g_pInput->IsKeyHold(MOFKEY_S))
    {
        SaveMapData(g_pMainWindow->GetWindowHandle());
    }

	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの描画
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Render(void) {
	//描画開始
	g_pGraphics->RenderStart();
	//画面のクリア
	g_pGraphics->ClearTarget(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0);

    g_BackImage.Render();
    g_BtnAdd.Render();
    g_BtnClear.Render();

    CGraphicsUtilities::RenderString(0, 0, "MARGIN : %d", (g_DataSelectNo != -1) ? g_StageData[g_DataSelectNo].margin : INT32_MAX);
    int cnt = g_StageData.GetArrayCount();
    const float offsetX = (SceneSize.x - GetPanelWidth()) * 0.5f;
    float posx = offsetX;
    Vector2 size(g_Panel[0].GetWidth()* ResizeScale.x, g_Panel[0].GetHeight() * ResizeScale.y);
    Vector2 rectPos(posx, PanelCenterY * ResizeScale.y - size.y * 0.5f);
    CRectangle rect(rectPos, rectPos + size);
    for (int i = 0; i < cnt; i++)
    {
        Panel& data = g_StageData.GetData(i);
        bool bRender = true;
        posx += data.margin * ResizeScale.x;
        rect.SetPosition(Vector2(posx, rect.Top));
        if (data.texNo != -1)
        {
            posx += g_Panel[data.texNo].GetWidth() * ResizeScale.x * 0.5f;
        }
        else
        {
            bRender = false;
        }

        Vector2 mp;
        g_pInput->GetMousePos(mp);
        if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON) && rect.CollisionPoint(mp))
        {
            g_DataSelectNo = i;
        }
        if (i == g_DataSelectNo)
        {
            CGraphicsUtilities::RenderRect(rect, MOF_COLOR_GREEN);
        }

        if (!bRender)
        {
            continue;
        }
        g_Panel[data.texNo].RenderScaleRotate(posx, PanelCenterY * ResizeScale.y, ResizeScale.x, ResizeScale.y, MOF_ToRadian(90 * data.rotate), TEXALIGN_CENTERCENTER);
        posx += g_Panel[data.texNo].GetWidth() * ResizeScale.x * 0.5f;
    }

    {
        Vector2 startPos(100, 400);
        Vector2 rectSize1 = Vector2(g_Panel[1].GetWidth(), g_Panel[1].GetHeight()) * ResizeScale;
        Vector2 rectSize2 = Vector2(g_Panel[0].GetWidth(), g_Panel[0].GetHeight()) * ResizeScale;
        CRectangle rect(startPos, startPos + rectSize1);
        Vector2 mp;
        g_pInput->GetMousePos(mp);
        if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON) && rect.CollisionPoint(mp))
        {
            g_SelectNo = 0;
        }
        CGraphicsUtilities::RenderTexture(rect, &g_Panel[1]);
        if (g_SelectNo == 0)
        {
            CRectangle br = rect;
            br.Expansion(1);
            CGraphicsUtilities::RenderRect(br, MOF_COLOR_GREEN);
        }
        rect.SetWidth(rectSize2.x);
        for (int i = 1; i < 6; i++)
        {
            rect.SetPosition(Vector2(rect.Left + rectSize2.x, rect.Top));
            if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON) && rect.CollisionPoint(mp))
            {
                g_SelectNo = i;
            }
            if (i != 5)
            {
                g_Panel[0].RenderScaleRotate(rect.GetCenter().x, rect.GetCenter().y, ResizeScale.x, ResizeScale.y, MOF_ToRadian(90 * (i - 1)), TEXALIGN_CENTERCENTER);
            }
            if (g_SelectNo == i)
            {
                CRectangle br = rect;
                br.Expansion(1);
                CGraphicsUtilities::RenderRect(br, MOF_COLOR_GREEN);
            }
        }
    }

	//描画の終了
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの解放
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Release(void) {

    CloseData(NULL);

	return TRUE;
}

void LoadMapData(HWND hWnd)
{
    g_OpenFileName;
}

void CloseData(HWND hWnd)
{
    g_BackImage.Release();
    g_BtnAdd.Release();
    g_BtnClear.Release();
    g_Panel[0].Release();
    g_Panel[1].Release();
    g_BtnPlate.Release();
    g_ClearTexture.Release();
    g_AddTexture.Release();
    g_StageData.ReSize(0);
}

void SaveMapData(HWND hWnd, bool over)
{
    bool out;
    char path[MAX_PATH];

    std::function<void(LPCMofChar)> save = [](LPCMofChar str)
    {
        FILE* fp = fopen(str, "wb");
        if (fp == NULL)
        {
            return;
        }
        int cnt = g_StageData.GetArrayCount();
        fwrite(&cnt, sizeof(int), 1, fp);
        for (int i = 0; i < cnt; i++)
        {
            Panel data = g_StageData[i];
            fwrite(&data.texNo , sizeof(int), 1, fp);
            fwrite(&data.rotate, sizeof(int), 1, fp);
            fwrite(&data.margin, sizeof(int), 1, fp);
        }
        fclose(fp);
    };
    if (over && g_OpenFileName.length() > 0)
    {
        save(g_OpenFileName.c_str());
    }
    else
    {
        if (sip::CFileDialog::Open(hWnd, sip::CFileDialog::Mode::Save, "ステージデータの保存", "*.stage", "stage", path, out))
        {
            save(path);
        }
    }
}

void LoadBackTexture(HWND hWnd)
{
    bool out;
    char path[MAX_PATH];
    if (sip::CFileDialog::Open(hWnd, sip::CFileDialog::Mode::Open, "背景の読み込み", "*.png", "png", path, out))
    {
        g_BackImage.Release();
        g_BackImage.Load(path);
    }
}

void LoadChipTexture(HWND hWnd)
{
}
