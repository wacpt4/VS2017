//快速注释在工具栏那里里 获取大于4GB
/*
#include <Windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;


int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR CmdLine, int CmdShow){

	HANDLE hFile = CreateFile(_T("D:\\456.png"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	//句柄形式
if(hFile != INVALID_HANDLE_VALUE){
	DWORD dwFileSzie = GetFileSize(hFile, NULL);

	TCHAR szFileSize{ 128 } = { 0 };
	_stprintf(szFileSize, _T("文件的大小是：&d"), dwFileSzie);
	
	CloseHandle(hFile);
}
else
{
	MessageBox(NULL, _T("OPENFAILD!"), _T("TIP"), MB_OK);
}
return 0;
}*/
#include <windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//HANDLE hFile = CreateFile(_T("I:\\系统重装\\DEEPIN-LITEXP-6.2.iso"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//if (hFile != INVALID_HANDLE_VALUE)
	//{
	//	DWORD dwFileSizeHigh = 0;
	//	DWORD dwFileSize = GetFileSize(hFile, &dwFileSizeHigh);

	//	LONGLONG lFileSize = (((LONGLONG)dwFileSizeHigh) << 32) | dwFileSize;

	//	TCHAR szFileSize[128] = { 0 };
	//	_stprintf(szFileSize, _T("文件的大小是：%lld"), lFileSize);
	//	MessageBox(NULL, szFileSize, _T("Tip"), MB_OK);
	//	CloseHandle(hFile);
	//}
	//else
	//{
	//	MessageBox(NULL, _T("文件打开失败！"), _T("Tip"), MB_OK);
	//}
	//可以获取大于4GB
	HANDLE hFile = CreateFile(_T("I:\\系统重装\\cn_windows_10_business_editions_version_1809_updated_dec_2018_x64_dvd_f5563b4e.iso"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		LARGE_INTEGER fileSize = { 0 };
		BOOL bRet = GetFileSizeEx(hFile, &fileSize);
		if (bRet)
		{
			TCHAR szFileSize[128] = { 0 };
			_stprintf(szFileSize, _T("文件的大小是：%lld"), fileSize.QuadPart);
			MessageBox(NULL, szFileSize, _T("Tip"), MB_OK);
		}

		CloseHandle(hFile);
	}
	else
	{
		MessageBox(NULL, _T("文件打开失败！"), _T("Tip"), MB_OK);
	}

	return 0;
}
