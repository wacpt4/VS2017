//����ע���ڹ�����������
/*
#include <Windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;


int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR CmdLine, int CmdShow){

	HANDLE hFile = CreateFile(_T("D:\\456.png"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	//�����ʽ
if(hFile != INVALID_HANDLE_VALUE){
	DWORD dwFileSzie = GetFileSize(hFile, NULL);

	TCHAR szFileSize{ 128 } = { 0 };
	_stprintf(szFileSize, _T("�ļ��Ĵ�С�ǣ�&d"), dwFileSzie);
	
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
	//HANDLE hFile = CreateFile(_T("I:\\ϵͳ��װ\\DEEPIN-LITEXP-6.2.iso"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//if (hFile != INVALID_HANDLE_VALUE)
	//{
	//	DWORD dwFileSizeHigh = 0;
	//	DWORD dwFileSize = GetFileSize(hFile, &dwFileSizeHigh);

	//	LONGLONG lFileSize = (((LONGLONG)dwFileSizeHigh) << 32) | dwFileSize;

	//	TCHAR szFileSize[128] = { 0 };
	//	_stprintf(szFileSize, _T("�ļ��Ĵ�С�ǣ�%lld"), lFileSize);
	//	MessageBox(NULL, szFileSize, _T("Tip"), MB_OK);
	//	CloseHandle(hFile);
	//}
	//else
	//{
	//	MessageBox(NULL, _T("�ļ���ʧ�ܣ�"), _T("Tip"), MB_OK);
	//}
	//���Ի�ȡ����4GB
	HANDLE hFile = CreateFile(_T("I:\\ϵͳ��װ\\cn_windows_10_business_editions_version_1809_updated_dec_2018_x64_dvd_f5563b4e.iso"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		LARGE_INTEGER fileSize = { 0 };
		BOOL bRet = GetFileSizeEx(hFile, &fileSize);
		if (bRet)
		{
			TCHAR szFileSize[128] = { 0 };
			_stprintf(szFileSize, _T("�ļ��Ĵ�С�ǣ�%lld"), fileSize.QuadPart);
			MessageBox(NULL, szFileSize, _T("Tip"), MB_OK);
		}

		CloseHandle(hFile);
	}
	else
	{
		MessageBox(NULL, _T("�ļ���ʧ�ܣ�"), _T("Tip"), MB_OK);
	}

	return 0;
}