////if else怎么成对，后面爆了错误只能重新让编译器重新识别到是对的
////写入了乱码是因为要用二进制和十六进制打开
////如果不CloseHandle 就没写入就读取不到【】参照教程代码
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
//	HANDLE hFile = CreateFile(_T("D://U盘有些没读出来.txt"), GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//	if (hFile == INVALID_HANDLE_VALUE)
//	{
//		MessageBox(NULL, _T("文件打开失败！"), _T("TIP"), MB_OK);
//		return -1;
//	}
//
//	DWORD dwRealWrite = 0;
//	////【】int 写入四个字节 乱码  UltraEdit 7B 00 00 00     16进制下为123
//	int num = 123;
//	BOOL bRet1 = WriteFile(hFile, &num, sizeof(int),&dwRealWrite, NULL);
//	
////【】只用一个BOOL即可，再声明就是重复了
//	char ch = 'q';
//	BOOL bRet2 = WriteFile(hFile, &ch, sizeof(char),&dwRealWrite, NULL);
//	////【】char字符 多于一个就要用数组【】char sizeof（int）下填充了字节 71=q ASCII？
//
//
//	char szText[]= "哈哈哈" ;
//	////【】数组首地址不用&      记住修改第二个参数和第三个参数，  就是首地址和申请空间的问题 【】还有BOOL要不同的句柄
//	BOOL bRet3 = WriteFile(hFile, szText, sizeof(szText), &dwRealWrite, NULL);
//
//	//写入二进制数据
//	Student stud;
//	stud.age = 20;
//	
//	//stud.name = 's';报错 必须是可修改的左值
//	strcpy(stud.name, "张三");//中文字节要双引号
//	stud.sex = 'f';
//
//	BOOL bRet4 = WriteFile(hFile, &stud, sizeof(stud), &dwRealWrite, NULL);
//	if (bRet4)
//	{
//			MessageBox(NULL, _T("数据写入成功！"), _T("TIP"), MB_OK);
//	}
//	else
//	{
//			MessageBox(NULL, _T("数据写入失败！"), _T("TIP"), MB_OK);
//	}
//	//刷新文件缓存之一  会有字符一样，但是编译不成功
//	FlushFileBuffers(hFile);
//
//	CloseHandle(hFile);
//
//
//	HANDLE hFile1 = CreateFile(_T("D://U盘有些没读出来.txt"), GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//	int ret_num = 0;
//	DWORD dwRealRead = 0;
//	BOOL bRet = ReadFile(hFile, &ret_num, sizeof(ret_num), &dwRealRead, NULL);
//	if (bRet)
//	{
//		MessageBox(NULL, _T("数据读取成功！"), _T("TIP"), MB_OK);
//	}
//	else
//	{
//		MessageBox(NULL, _T("数据读取失败！"), _T("TIP"), MB_OK);
//	}
//
//	//刷新文件缓存之三
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
	HANDLE hFile = CreateFile(_T("D://U盘有些没读出来.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
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
	hFile = CreateFile(_T("D://U盘有些没读出来.txt"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("文件打开失败！"), _T("Tip"), MB_OK);
		return -1;
	}

	//从文件中读数据 【】单步执行F11  Ctrl+Alt+W 再按1打开监视窗口
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
		MessageBox(NULL, _T("数据读取成功！"), _T("Tip"), MB_OK);
	}
	else
	{
		MessageBox(NULL, _T("数据读取失败！"), _T("Tip"), MB_OK);
	}





	CloseHandle(hFile);
	return 0;
}