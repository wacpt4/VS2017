#include <windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

struct Student
{
	int age;
	char sex;
	char name[32];
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//CreateDirectory(_T("D:\\�Ұ�ѧϰVC��վ�Ŀγ�\\hello\\123\\456"), NULL);
	
	//����һ���Դ�������Ŀ¼�ǲ������ ����һ��һ���ǿ��ԵĿ���for
	//���Դ�������鿴����ֵ
	//BOOL bCreateOK = CreateDirectory(_T("D:\\�Ұ�ѧϰVC��վ�Ŀγ�\\hello\\123\\456\\789"), NULL);
	
	
	//��Ŀ¼ɾ���༶Ŀ¼ʧ��
	RemoveDirectory(_T("D:\\�Ұ�ѧϰVC��վ�Ŀγ�"));
	//SHFileOperation("D:\\�Ұ�ѧϰVC��վ�Ŀγ�");
	//�������ԡ�1>c:\users\lyh\desktop\github\win32project\win32project\createdirectory.cpp(24) : error C2664 : ��int SHFileOperationA(LPSHFILEOPSTRUCTA)�� : �޷������� 1 �ӡ�const char[24]��ת��Ϊ��LPSHFILEOPSTRUCTA��


	//ֱ���˳���
	return 0;

	HANDLE hFile = CreateFile(_T("D:\\VC��վok.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("�ļ���ʧ�ܣ�"), _T("Tip"), MB_OK);
		return -1;
	}

	int num = 123;
	DWORD dwRealWrite = 0;
	BOOL bRet = WriteFile(hFile, &num, sizeof(int), &dwRealWrite, NULL);

	char ch = 'q';
	bRet = WriteFile(hFile, &ch, sizeof(char), &dwRealWrite, NULL);

	char szText[32] = "����VC��վ�ķ�˿��";
	bRet = WriteFile(hFile, szText, sizeof(szText), &dwRealWrite, NULL);

	Student stud;
	stud.age = 20;
	stud.sex = 'm';
	strcpy(stud.name, "zhangsan");

	bRet = WriteFile(hFile, &stud, sizeof(stud), &dwRealWrite, NULL);
	if (bRet)
	{
		MessageBox(NULL, _T("����д��ɹ���"), _T("Tip"), MB_OK);
	}
	else
	{
		MessageBox(NULL, _T("����д��ʧ�ܣ�"), _T("Tip"), MB_OK);
	}

	CloseHandle(hFile);

	////////////////////////////////////////////////////////////////
	hFile = CreateFile(_T("D:\\VC��վok.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("�ļ���ʧ�ܣ�"), _T("Tip"), MB_OK);
		return -1;
	}

	//���ļ��ж�����
	//int ret_num = 0;
	DWORD dwRealRead = 0;
	//bRet = ReadFile(hFile, &ret_num, sizeof(ret_num), &dwRealRead, NULL);

	//char cha = 0;
	//bRet = ReadFile(hFile, &cha, sizeof(cha), &dwRealRead, NULL);

	//SetFilePointer(hFile, sizeof(int) + sizeof(char), NULL, FILE_BEGIN);
	SetFilePointer(hFile, -32 - sizeof(Student), NULL, FILE_END);

	char szTextRet[32] = { 0 };
	bRet = ReadFile(hFile, szTextRet, sizeof(szTextRet), &dwRealRead, NULL);

	Student stud2;
	bRet = ReadFile(hFile, &stud2, sizeof(Student), &dwRealRead, NULL);
	if (bRet)
	{
		MessageBox(NULL, _T("���ݶ�ȡ�ɹ���"), _T("Tip"), MB_OK);
	}
	else
	{
		MessageBox(NULL, _T("���ݶ�ȡʧ�ܣ�"), _T("Tip"), MB_OK);
	}

	CloseHandle(hFile);
	return 0;
}