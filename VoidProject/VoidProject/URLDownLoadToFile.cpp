//ָ��ָ��URL��ַ��ȡ���ݲ�����ȡ�������ݱ��浽�ض����ļ��
#include <Windows.h>
#include <tchar.h>
#pragma comment(lib,"Urlmon.lib")//��urlmon.h

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