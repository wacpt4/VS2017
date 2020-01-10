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
	//CreateDirectory(_T("D:\\我爱学习VC驿站的课程\\hello\\123\\456"), NULL);
	
	//【】一次性创建三级目录是不允许的 但是一级一级是可以的可以for
	//所以创建句柄查看错误值
	//BOOL bCreateOK = CreateDirectory(_T("D:\\我爱学习VC驿站的课程\\hello\\123\\456\\789"), NULL);
	
	
	//空目录删除多级目录失败
	RemoveDirectory(_T("D:\\我爱学习VC驿站的课程"));
	//SHFileOperation("D:\\我爱学习VC驿站的课程");
	//【待调试】1>c:\users\lyh\desktop\github\win32project\win32project\createdirectory.cpp(24) : error C2664 : “int SHFileOperationA(LPSHFILEOPSTRUCTA)” : 无法将参数 1 从“const char[24]”转换为“LPSHFILEOPSTRUCTA”


	//直接退出了
	return 0;

	HANDLE hFile = CreateFile(_T("D:\\VC驿站ok.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
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
	hFile = CreateFile(_T("D:\\VC驿站ok.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
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

	//SetFilePointer(hFile, sizeof(int) + sizeof(char), NULL, FILE_BEGIN);
	SetFilePointer(hFile, -32 - sizeof(Student), NULL, FILE_END);

	char szTextRet[32] = { 0 };
	bRet = ReadFile(hFile, szTextRet, sizeof(szTextRet), &dwRealRead, NULL);

	Student stud2;
	bRet = ReadFile(hFile, &stud2, sizeof(Student), &dwRealRead, NULL);
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