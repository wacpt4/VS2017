#include <Windows.h>
#include <tchar.h>
/*
int WINAPI _tWinMain(HANDLE hInstance, HANDLE hPreInstance, LPSTR lpCmdLine, int nCmdShow){

//MessageBox(NULL, lpCmdLine, _T("��ʾ"), MB_OK);
//return 0;
ʵ�ֵ������ַ�������ͨ��exe��������ȥ Ŀ¼��Win32Project.exe
}*/

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MessageBox(NULL, lpCmdLine, _T("��ʾ"), MB_OK);
	return 0;
}