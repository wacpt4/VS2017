#include <Windows.h>
#include <tchar.h>
#pragma comment(lib, "Urlmon.lib")



int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE PreInstance, LPSTR lpCmdLine, int nCmdShow){
	HRESULT hret = URLDownloadToFile(NULL, "https://s.cctry.com/images/eagle3.png", _T("D:\\s.png"), 0, NULL);
	/*
	SHELLEXECUTEINFO shellInfo = { 0 };//��ʼ��
	shellInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	//�ļ�����
	shellInfo.lpVerb = _T("open");
	//�ļ�����
	shellInfo.lpFile = _T("D:\\s.png");
	shellInfo.nShow = SW_SHOW;

	BOOL bRetPng = ShellExecuteEx(&shellInfo);
	*/

	/*�Ѽ��ء�C:\Windows\SysWOW64\ntdll.dll�����޷����һ�� PDB �ļ���
	SHELLEXECUTEINFO shellInfoIE = { 0 };
	shellInfoIE.cbSize = sizeof(&shellInfoIE);
	shellInfoIE.lpVerb = _T("open");
	shellInfoIE.lpFile = _T("C:\\Program Files\\internet explorer\\iexplore.exe");
	shellInfoIE.lpParameters = _T("https://www.cctry.com/");
	shellInfoIE.nShow = SW_SHOWNORMAL;
	BOOL bRetIE = ShellExecuteEx(&shellInfoIE);
	*/
	/*һ�����в���*/
	SHELLEXECUTEINFO ShellInfo = { 0 };
	ShellInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShellInfo.lpVerb = _T("open");
	ShellInfo.lpFile = _T("C:\\Program Files\\internet explorer\\iexplore.exe");
	ShellInfo.lpParameters = _T("https://www.cctry.com/");
	ShellInfo.nShow = SW_SHOWNORMAL;
	BOOL bRet = ShellExecuteEx(&ShellInfo);
	return 0;
}