//中文括号导致的错误
#include <Windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	return 0;
}


////szDrives监视 第二个参数
//int _tmain(int argc, char* argv[])
//{
//	TCHAR szDrives[MAX_PATH] = { 0 };
//	DWORD dwRet = GetLogicalDriveStrings(MAX_PATH, szDrives);
//	return 0;
//}
int _tmain(int argc, TCHAR* argv[])
{
	DWORD dwRet = GetLogicalDriveStrings(0, NULL);
	if (dwRet > 0)
	{
		TCHAR* pBuffer = new TCHAR[dwRet + 10];
		ZeroMemory(pBuffer, (dwRet + 10) * sizeof(TCHAR));

		dwRet = GetLogicalDriveStrings(dwRet + 10, pBuffer);
		if (dwRet > 0)
		{
			TCHAR* pSignal = pBuffer;

			do
			{
				if (*pSignal)
				{
					wcout << pSignal;

					UINT nDriveType = GetDriveType(pSignal);
					switch (nDriveType)
					{
					case DRIVE_UNKNOWN:
						cout << "未知类型" << endl;
						break;
					case DRIVE_NO_ROOT_DIR:
						cout << "路径错误" << endl;
						break;
					case DRIVE_REMOVABLE:
						cout << "可移动磁盘" << endl;
						break;
					case DRIVE_FIXED:
						cout << "固定磁盘" << endl;
						break;
					case DRIVE_REMOTE:
						cout << "网络磁盘" << endl;
						break;
					case DRIVE_CDROM:
						cout << "光驱" << endl;
						break;
					case DRIVE_RAMDISK:
						cout << "RAM磁盘" << endl;
						break;
					default:
						break;
					}

					cout << endl;
				}

				pSignal += _tcslen(pSignal) + 1;

			} while (*pSignal);
		}
	}
	getchar();
	return 0;
}