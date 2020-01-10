//【顺序一致】
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


	HANDLE hFile = CreateFile(_T("D:\\U盘有些没读出来.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("文件打开失败！"), _T("Tip"), MB_OK);
		return -1;
	}
	int num = 123;
	DWORD dwRealWrite = 0;
	BOOL bRet = WriteFile(hFile, &num, sizeof(int), &dwRealWrite, NULL);

	char ch = 'q';
	bRet = WriteFile(hFile, &ch, sizeof(char), &dwRealWrite, NULL);

	char szText[32] = "我是VC驿站的粉丝！";
	bRet = WriteFile(hFile, szText, sizeof(szText), &dwRealWrite, NULL);

	Student stud;
	stud.age = 20;
	stud.sex = 'm';
	strcpy(stud.name, "zhangsan");

	bRet = WriteFile(hFile, &stud, sizeof(stud), &dwRealWrite, NULL);
	if (bRet)
	{
		MessageBox(NULL, _T("数据写入成功！"), _T("Tip"), MB_OK);
	}
	else
	{
		MessageBox(NULL, _T("数据写入失败！"), _T("Tip"), MB_OK);
	}

	CloseHandle(hFile);
	////////////////////////////////////////////////////////////////
	hFile = CreateFile(_T("D:\\U盘有些没读出来.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("文件打开失败！"), _T("Tip"), MB_OK);
		return -1;
	}

	//从文件中读数据
	//int ret_num = 0;
	DWORD dwRealRead = 0;
	//bRet = ReadFile(hFile, &ret_num, sizeof(ret_num), &dwRealRead, NULL);

	//char cha = 0;
	//bRet = ReadFile(hFile, &cha, sizeof(cha), &dwRealRead, NULL);
	
	
	//读出的顺序要是想要不一致 直接读第三个参数VC驿站的粉丝，
	//所以注释前面的int和char 
	//第二个参数，一个int和char的空间大小
	//第四个参数，开始或者结束只能写一个
	//SetFilePointer(hFile, sizeof(int) + sizeof(char), NULL, FILE_BEGIN);
	SetFilePointer(hFile, -32 - sizeof(Student), NULL, FILE_END);

	char szTextRet[32] = { 0 };
	bRet = ReadFile(hFile, szTextRet, sizeof(szTextRet), &dwRealRead, NULL);

	Student stud2;
	bRet = ReadFile(hFile, &stud2, sizeof(Student), &dwRealRead, NULL);
//【】F10单步执行，然后到if那里才赋值成功
	if (bRet)
	{
		MessageBox(NULL, _T("数据读取成功！"), _T("Tip"), MB_OK);
	}
	else
	{
		MessageBox(NULL, _T("数据读取失败！"), _T("Tip"), MB_OK);
	}

	CloseHandle(hFile);
	return 0;
}