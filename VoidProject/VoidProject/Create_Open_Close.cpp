#include <Windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdline, int nCmdShow){
	//����ѡ�������|��������
	//HANDLE ������Ҫ��Ϊ���ж�
	/*�����µĿհ��ļ�
	HANDLE hFile = CreateFile(_T("D:\\ab.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("SUCCESS!"), _T("TIP"), MB_OK);
	}*/
	/*���Ѿ����ڵ��ļ�*/
	HANDLE hFile = CreateFile(_T("D:\\ab.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("OPEN SUCCESS!"), _T("TIP"), MB_OK);
	}
	else{
		DWORD dwErr = GetLastError();
		MessageBox(NULL, _T("OPEN FAIL!"), _T("TIP"), MB_OK);
	}
	/*���Ѿ����ڵ��ļ�,�������򴴽��ļ�OPEN_ALWAYS*/
	/*���Ѿ����ڵ��ļ�,������������ݣ��������򴴽���TRUNCATE_EXISTING*/
	return 0;

}