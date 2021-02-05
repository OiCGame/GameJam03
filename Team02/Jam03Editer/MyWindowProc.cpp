#include "MyWindowProc.h"
#include "resource.h"
#include "GameApp.h"

#define MSG_TITLE               TEXT("�A�v���P�[�V�����̃o�[�W�������")
#define MSG_VERSION             TEXT("Ver. 1.0.0 (jam03Team2Editor.exe)")
#define MSG_CAPTION             MSG_TITLE TEXT("#") MSG_VERSION
#define MSG_COPYRIGHT           TEXT("Copyright(C) 2021-02-02 by inoue")

MofProcResult CMyWindowProc::WindowProc(MofWindowHandle hWnd, MofUInt msg, MofProcParamW wpar, MofProcParamL lpar)
{
    switch (msg)
    {
    case WM_CREATE:
    {
        //���j���[��ݒ�
        SetMenu(hWnd, LoadMenu(NULL, MAKEINTRESOURCE(IDR_MENU1)));
        int w = 1280 + GetSystemMetrics(SM_CXFIXEDFRAME) * 2;
        int h = 720  + GetSystemMetrics(SM_CYFIXEDFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CYMENU);
        SetWindowPos(hWnd, NULL, 0, 0, w, h, SWP_NOZORDER | SWP_NOMOVE);
        break;
    }

    case WM_COMMAND:
        //���j���[�I��
        switch (LOWORD(wpar))
        {
        case ID_NEWFILE:
            break;
        case ID_OPENFILE:
            LoadMapData(hWnd);				//�}�b�v�ǂݍ���
            break;
        case ID_EXITFILE:
            CloseData(hWnd);
            break;
        case ID_SAVE:
            SaveMapData(hWnd);				//�}�b�v�ۑ�
            break;
        case ID_SAVEOVER:
            SaveMapData(hWnd, true);		//�}�b�v�ۑ�
            break;

        case ID_EDITBACKTEXTURE:
            LoadBackTexture(hWnd);			//�w�i�摜�ǂݍ���
            break;
        case ID_EDITPANELTEXTURE:
            LoadChipTexture(hWnd);			//�`�b�v�摜�ǂݍ���
            break;

        case ID_SHOWBLOCKINFO:
            break;

        case ID_EXIT:						//�I��
            PostQuitMessage(0);
            break;

        case ID_VERSION:					//�o�[�W����
            ShellAbout(hWnd, MSG_CAPTION, MSG_COPYRIGHT, NULL);
            break;
        }
        break;

    default:									//�f�t�H���g����
        return CDefWindowProc::WindowProc(hWnd, msg, wpar, lpar);
    }
    return DefWindowProc(hWnd, msg, wpar, lpar);
}
