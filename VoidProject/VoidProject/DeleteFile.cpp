/*#include <Windows.h>
#include <tchar.h>*/
/*以下两行没包括进去直接失败，编译通过*/

//#include <iostream>
/*
using namespace std;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE PreInstance, LPSTR lpCmdLine, int hCmdShow)
{
	BOOL bRet = DeleteFile(_T("‪D:\\s.png"));
	if (bRet)
	{
		MessageBox(NULL, _T("删除成功"), _T("Tip"), MB_OK);
	}
	else
	{
		MessageBox(NULL, _T("删除失败"), _T("Tip"), MB_OK);
	}
	return 0;
}*/


#include <windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
//	BOOL bRet = DeleteFile(_T("D:\\789.txt"));
//	if (bRet)
//	{
//		MessageBox(NULL, _T("删除成功！"), _T("Tip"), MB_OK);
//	}
//	else
//	{
//		MessageBox(NULL, _T("删除失败！"), _T("Tip"), MB_OK);
//	}


	BOOL bRet = CopyFile(_T("D:\\s.png"), _T("C:\\Users\\lyh\\Desktop\\s.png"), FALSE);
	if (bRet)
	{
	MessageBox(NULL, _T("拷贝成功！"), _T("Tip"), MB_OK);
	}
else
	{
		MessageBox(NULL, _T("拷贝失败！"), _T("Tip"), MB_OK);
	}

	//BOOL bRet = MoveFile(_T("D:\\cctry.com.txt"), _T("C:\\Users\\Syc\\Desktop\\cctry.bat"));
	//if (bRet)
	//{
	//	MessageBox(NULL, _T("移动成功！"), _T("Tip"), MB_OK);
	//}
	//else
	//{
	//	MessageBox(NULL, _T("移动失败！"), _T("Tip"), MB_OK);
	//}

	return 0;
}