#include <Windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

//�ո�
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdline, int nCmdShow){
	//��β鿴DeleteFile��bool����
	
	//DeleteFile(_T("D:\\7289.txt"));
	BOOL DRet = DeleteFile(_T("D:\\7289.txt"));
	//C��������ʹ��0�����߼��٣���0�����߼��档	if (n)����д����if(n != 0)����ȫ�ȼ۵ġ�
	if (DRet)
	{
		MessageBox(NULL, _T("ɾ���ļ��ɹ�"), _T("TIP"), MB_OK);
	}
	else
	{	
		DWORD dwError = GetLastError();
		//if (dwError == 2) ��Ϊ��ֵ�����ú궨�� System error code https://docs.microsoft.com/zh-cn/windows/win32/debug/system-error-codes
		if (dwError == ERROR_FILE_NOT_FOUND)
		{
			MessageBox(NULL,_T("�ļ�������,��ȷ��"), _T("TIP"), MB_OK);
		}
		//�ϵ���������ȡGetLastError��ֵ  ������ߴ����������ֵ
		MessageBox(NULL, _T("ɾ���ļ�ʧ��"), _T("TIP"), MB_OK);
	}
	return 0;
}