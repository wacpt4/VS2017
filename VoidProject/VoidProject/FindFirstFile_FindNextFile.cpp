////API�Ķ�������->����ֵ�����Ǿ��������Ҫ�رվ����
////wcout  ���ֽڵ�cout  cout������ڿ���̨��
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
//		//��������-������-ϵͳ-�ĳɿ���̨ ������ʱҪ����int main0
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

			//�ļ���
			cout << "�ļ��У�";

		}
		else
		{
			if ((FindData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) > 0)
			{
				//
			}

			//�ļ�
			cout << "�ļ���";
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