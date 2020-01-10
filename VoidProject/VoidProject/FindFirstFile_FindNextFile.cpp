////API阅读【参数->返回值，若是句柄类型则要关闭句柄】
////wcout  宽字节的cout  cout是输出在控制台的
//
//#include <Windows.h>
//#include <tchar.h>
//#include <iostream>
//using namespace std;
//
//BOOL EnumFiles(LPCTSTR lpszPath, LPCTSTR lpszType)
//{
//	TCHAR szPath[MAX_PATH] = { 0 };
//	_stprintf(szPath, _T("%s\\s"), lpszPath, lpszType);
//
//	WIN32_FIND_DATA FindData = { 0 };
//	HANDLE hFind = FindFirstFile(szPath, &FindData);
//	if (hFind == INVALID_HANDLE_VALUE) return FALSE;
//	
//
//	BOOL bRet = FALSE;
//	do
//	{
//		WIN32_FIND_DATA FindData = { 0 };
//		FindNextFile(hFind, &FindData);
//		if (!bRet) break;
//		//工程属性-连接器-系统-改成控制台 【】此时要加上int main0
//
//		cout << FindData.cFileName << endl;
//	
//	} while (bRet);
//
//	return TRUE;
//}
//
//int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR lpCmdLine, int nCmdShow)
//{
//	EnumFiles(_T("C:\\Windows"), _T("*.*"));
//	return 0;
//}
//
//int _tmain(int argc, TCHAR* argv)
//{
//	getchar();
//	return 0;
//}

#include <windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

BOOL EnumFiles(LPCTSTR lpszPath, LPCTSTR lpszType)
{
	TCHAR szPath[MAX_PATH] = { 0 };
	_stprintf(szPath, _T("%s\\%s"), lpszPath, lpszType);

	WIN32_FIND_DATA FindData = { 0 };
	HANDLE hFind = FindFirstFile(szPath, &FindData);
	if (hFind == INVALID_HANDLE_VALUE) return FALSE;

	BOOL bRet = FALSE;
	do
	{
		bRet = FindNextFile(hFind, &FindData);
		if (!bRet) break;

		if ((FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) > 0)
		{
			if (_tcscmp(FindData.cFileName, _T(".")) == 0 || _tcscmp(FindData.cFileName, _T("..")) == 0) continue;

			//文件夹
			cout << "文件夹：";

		}
		else
		{
			if ((FindData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) > 0)
			{
				//
			}

			//文件
			cout << "文件：";
		}

		wcout << FindData.cFileName << endl;

	} while (bRet);

	return TRUE;
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	EnumFiles(_T("C:\\Windows"), _T("*.*"));
	return 0;
}

int _tmain(int argc, TCHAR* argv[])
{
	EnumFiles(_T("C:\\Windows"), _T("*.*"));
	getchar();
	return 0;
}