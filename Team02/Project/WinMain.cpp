#include	"GameApp.h"
#include    "MyTime.h"
#include    "resource.h"

int WINAPI _tWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow )
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	Mof::LPFramework pFrame = new Mof::CDX11GameFramework(); 
	Mof::WINDOWSGAMEFRAMEWORKINITIALIZEINFO Info;
	Info.pApplication = new CGameApp();
    Info.WindowCreateInfo.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    Info.WindowCreateInfo.Title = "シューティングパズル";
    sip::CMyTime::InitTime();

    // 初期ウィンドウを仮想フルスクリーンに変更
    Info.WindowCreateInfo.Width  = 1920;
    Info.WindowCreateInfo.Height = 1080;

    Info.WindowCreateInfo.Style  = WS_POPUP | WS_VISIBLE;
#ifdef _DEBUG
    Info.WindowCreateInfo.Style  = WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_VISIBLE | WS_THICKFRAME;
#endif //_DEBUG
    if ( pFrame->Initialize(&Info) )
	{
		pFrame->Run();
	}
	MOF_SAFE_DELETE(pFrame);
	return 0;
}