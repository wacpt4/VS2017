#include <Windows.h>
#include <tchar.h>
/*
int WINAPI _tWinMain(HANDLE hInstance, HANDLE hPreInstance, LPSTR lpCmdLine, int nCmdShow){

//MessageBox(NULL, lpCmdLine, _T("提示"), MB_OK);
//return 0;
实现弹出的字符串内容通过exe参数传进去 目录下Win32Project.exe
}*/

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MessageBox(NULL, lpCmdLine, _T("提示"), MB_OK);
	return 0;
}