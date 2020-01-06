#include <Windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

//空格
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdline, int nCmdShow){
	//如何查看DeleteFile是bool类型
	
	//DeleteFile(_T("D:\\7289.txt"));
	BOOL DRet = DeleteFile(_T("D:\\7289.txt"));
	//C语言里面使用0代表逻辑假，非0代表逻辑真。	if (n)这种写法和if(n != 0)是完全等价的。
	if (DRet)
	{
		MessageBox(NULL, _T("删除文件成功"), _T("TIP"), MB_OK);
	}
	else
	{	
		DWORD dwError = GetLastError();
		//if (dwError == 2) 因为数值会变改用宏定义 System error code https://docs.microsoft.com/zh-cn/windows/win32/debug/system-error-codes
		if (dwError == ERROR_FILE_NOT_FOUND)
		{
			MessageBox(NULL,_T("文件不存在,请确认"), _T("TIP"), MB_OK);
		}
		//断点打在下面获取GetLastError的值  点击工具错误查找输入值
		MessageBox(NULL, _T("删除文件失败"), _T("TIP"), MB_OK);
	}
	return 0;
}