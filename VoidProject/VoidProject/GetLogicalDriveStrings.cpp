//�������ŵ��µĴ���
#include <Windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	return 0;
}


////szDrives���� �ڶ�������
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
						cout << "δ֪����" << endl;
						break;
					case DRIVE_NO_ROOT_DIR:
						cout << "·������" << endl;
						break;
					case DRIVE_REMOVABLE:
						cout << "���ƶ�����" << endl;
						break;
					case DRIVE_FIXED:
						cout << "�̶�����" << endl;
						break;
					case DRIVE_REMOTE:
						cout << "�������" << endl;
						break;
					case DRIVE_CDROM:
						cout << "����" << endl;
						break;
					case DRIVE_RAMDISK:
						cout << "RAM����" << endl;
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