//指从指定URL地址读取内容并将读取到的内容保存到特定的文件里。
#include <Windows.h>
#include <tchar.h>
#pragma comment(lib,"Urlmon.lib")//在urlmon.h

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE PreInstance, LPSTR lpCmdLine, int hCmdShow)
{
	HRESULT hret = URLDownloadToFile(NULL, "https://s.cctry.com/images/eagle3.png", _T("D:\\s.png"), 0, NULL);
	if (hret == S_OK)
	{
		MessageBox(NULL, _T("success!"), _T("Tip"), MB_OK);
	}
	else
	{
		MessageBox(NULL, _T("failed!"), _T("Tip"), MB_OK);
	}
	return 0;
}