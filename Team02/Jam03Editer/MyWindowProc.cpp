#include "MyWindowProc.h"
#include "resource.h"
#include "GameApp.h"

#define MSG_TITLE               TEXT("アプリケーションのバージョン情報")
#define MSG_VERSION             TEXT("Ver. 1.0.0 (jam03Team2Editor.exe)")
#define MSG_CAPTION             MSG_TITLE TEXT("#") MSG_VERSION
#define MSG_COPYRIGHT           TEXT("Copyright(C) 2021-02-02 by inoue")

MofProcResult CMyWindowProc::WindowProc(MofWindowHandle hWnd, MofUInt msg, MofProcParamW wpar, MofProcParamL lpar)
{
    switch (msg)
    {
    case WM_CREATE:
    {
        //メニューを設定
        SetMenu(hWnd, LoadMenu(NULL, MAKEINTRESOURCE(IDR_MENU1)));
        int w = 1280 + GetSystemMetrics(SM_CXFIXEDFRAME) * 2;
        int h = 720  + GetSystemMetrics(SM_CYFIXEDFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CYMENU);
        SetWindowPos(hWnd, NULL, 0, 0, w, h, SWP_NOZORDER | SWP_NOMOVE);
        break;
    }

    case WM_COMMAND:
        //メニュー選択
        switch (LOWORD(wpar))
        {
        case ID_NEWFILE:
            break;
        case ID_OPENFILE:
            LoadMapData(hWnd);				//マップ読み込み
            break;
        case ID_EXITFILE:
            CloseData(hWnd);
            break;
        case ID_SAVE:
            SaveMapData(hWnd);				//マップ保存
            break;
        case ID_SAVEOVER:
            SaveMapData(hWnd, true);		//マップ保存
            break;

        case ID_EDITBACKTEXTURE:
            LoadBackTexture(hWnd);			//背景画像読み込み
            break;
        case ID_EDITPANELTEXTURE:
            LoadChipTexture(hWnd);			//チップ画像読み込み
            break;

        case ID_SHOWBLOCKINFO:
            break;

        case ID_EXIT:						//終了
            PostQuitMessage(0);
            break;

        case ID_VERSION:					//バージョン
            ShellAbout(hWnd, MSG_CAPTION, MSG_COPYRIGHT, NULL);
            break;
        }
        break;

    default:									//デフォルト処理
        return CDefWindowProc::WindowProc(hWnd, msg, wpar, lpar);
    }
    return DefWindowProc(hWnd, msg, wpar, lpar);
}
