#include <Windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdline, int nCmdShow){
	//参数选项可以用|并行输入
	//HANDLE 对象主要是为了判断
	/*创建新的空白文件
	HANDLE hFile = CreateFile(_T("D:\\ab.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("SUCCESS!"), _T("TIP"), MB_OK);
	}*/
	/*打开已经存在的文件*/
	HANDLE hFile = CreateFile(_T("D:\\ab.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("OPEN SUCCESS!"), _T("TIP"), MB_OK);
	}
	else{
		DWORD dwErr = GetLastError();
		MessageBox(NULL, _T("OPEN FAIL!"), _T("TIP"), MB_OK);
	}
	/*打开已经存在的文件,不存在则创建文件OPEN_ALWAYS*/
	/*打开已经存在的文件,存在则清空内容，不存在则创建新TRUNCATE_EXISTING*/
	return 0;

}