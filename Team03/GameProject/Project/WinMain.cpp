#include	"GameApp.h"

int WINAPI _tWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow )
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	Mof::LPFramework pFrame = new Mof::CDX11GameFramework(); 
	Mof::WINDOWSGAMEFRAMEWORKINITIALIZEINFO Info;
	Info.pApplication = new CGameApp();
	//Info.WindowCreateInfo.px = 0;
	//Info.WindowCreateInfo.py = 0;
	//Info.WindowCreateInfo.Width = 1920;
	//Info.WindowCreateInfo.Height = 1080;
	//Info.WindowCreateInfo.Style = (WS_VISIBLE | WS_POPUP);
	if ( pFrame->Initialize(&Info) )
	{
		pFrame->Run();
	}
	MOF_SAFE_DELETE(pFrame);
	return 0;
}