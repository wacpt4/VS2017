////if else��ô�ɶԣ����汬�˴���ֻ�������ñ���������ʶ���ǶԵ�
////д������������ΪҪ�ö����ƺ�ʮ�����ƴ�
////�����CloseHandle ��ûд��Ͷ�ȡ�����������ս̴̳���
//#include <Windows.h>
//#include <tchar.h>
//#include <iostream>
//using namespace std;
//
//struct Student{
//	int age;
//	char sex;
//	char name[32];
//};
//
//
//
//int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE PreInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	HANDLE hFile = CreateFile(_T("D://U����Щû������.txt"), GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//	if (hFile == INVALID_HANDLE_VALUE)
//	{
//		MessageBox(NULL, _T("�ļ���ʧ�ܣ�"), _T("TIP"), MB_OK);
//		return -1;
//	}
//
//	DWORD dwRealWrite = 0;
//	////����int д���ĸ��ֽ� ����  UltraEdit 7B 00 00 00     16������Ϊ123
//	int num = 123;
//	BOOL bRet1 = WriteFile(hFile, &num, sizeof(int),&dwRealWrite, NULL);
//	
////����ֻ��һ��BOOL���ɣ������������ظ���
//	char ch = 'q';
//	BOOL bRet2 = WriteFile(hFile, &ch, sizeof(char),&dwRealWrite, NULL);
//	////����char�ַ� ����һ����Ҫ�����顾��char sizeof��int����������ֽ� 71=q ASCII��
//
//
//	char szText[]= "������" ;
//	////���������׵�ַ����&      ��ס�޸ĵڶ��������͵�����������  �����׵�ַ������ռ������ ��������BOOLҪ��ͬ�ľ��
//	BOOL bRet3 = WriteFile(hFile, szText, sizeof(szText), &dwRealWrite, NULL);
//
//	//д�����������
//	Student stud;
//	stud.age = 20;
//	
//	//stud.name = 's';���� �����ǿ��޸ĵ���ֵ
//	strcpy(stud.name, "����");//�����ֽ�Ҫ˫����
//	stud.sex = 'f';
//
//	BOOL bRet4 = WriteFile(hFile, &stud, sizeof(stud), &dwRealWrite, NULL);
//	if (bRet4)
//	{
//			MessageBox(NULL, _T("����д��ɹ���"), _T("TIP"), MB_OK);
//	}
//	else
//	{
//			MessageBox(NULL, _T("����д��ʧ�ܣ�"), _T("TIP"), MB_OK);
//	}
//	//ˢ���ļ�����֮һ  �����ַ�һ�������Ǳ��벻�ɹ�
//	FlushFileBuffers(hFile);
//
//	CloseHandle(hFile);
//
//
//	HANDLE hFile1 = CreateFile(_T("D://U����Щû������.txt"), GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//	int ret_num = 0;
//	DWORD dwRealRead = 0;
//	BOOL bRet = ReadFile(hFile, &ret_num, sizeof(ret_num), &dwRealRead, NULL);
//	if (bRet)
//	{
//		MessageBox(NULL, _T("���ݶ�ȡ�ɹ���"), _T("TIP"), MB_OK);
//	}
//	else
//	{
//		MessageBox(NULL, _T("���ݶ�ȡʧ�ܣ�"), _T("TIP"), MB_OK);
//	}
//
//	//ˢ���ļ�����֮��
//	CloseHandle(hFile);
//	return 0;
//}
//

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
	HANDLE hFile = CreateFile(_T("D://U����Щû������.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
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
	hFile = CreateFile(_T("D://U����Щû������.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("�ļ���ʧ�ܣ�"), _T("Tip"), MB_OK);
		return -1;
	}

	//���ļ��ж����� ��������ִ��F11  Ctrl+Alt+W �ٰ�1�򿪼��Ӵ���
	int ret_num = 0;
	DWORD dwRealRead = 0;
	bRet = ReadFile(hFile, &ret_num, sizeof(ret_num), &dwRealRead, NULL);

	char cha = 0;
	bRet = ReadFile(hFile, &cha, sizeof(cha), &dwRealRead, NULL);

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