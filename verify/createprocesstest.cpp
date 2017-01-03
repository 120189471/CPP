//创建线程模板
//摘自http://blog.csdn.net/iphxer/article/details/7254682

#include <Windows.h>
#include <iostream>
#include <process.h>
using namespace std;

struct myelem
{
	int a;
	char ch;
};

void myfun(PVOID arg)
{
	cout << "myfun1 start..." << endl;
	int i = 100000;
	while (1)
	{
		cout << "myfun1： " << ++i << endl;
		Sleep(1000);
	}
}

void myfun2(PVOID arg)
{
	cout << "myfun2 start..."  << endl;
	int i = 500;
	while (1)
	{
		cout << "myfun2： " << ++i << endl;
		Sleep(1000);
		if (i >= 505)ExitThread(10);
	}
}

void myfun3(void *p)
{
	cout << "myfun3 start..."<<endl;
	myelem* myp = (myelem*)p;
	cout << "myfun3： " << myp->a << " " << myp->ch << endl;
	ExitThread(111);//设置退出码
}

int main_createprocesstest()
{
	int i = 0;
	//_beginthread 函数
	HANDLE handle = (HANDLE)_beginthread(myfun, 0, NULL);
	DWORD sid = 0;
	HANDLE handle2 = (HANDLE)CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)myfun2, 0, 0, &sid);
	cout << sid << endl;
	myelem e;
	e.a = 10; e.ch = 'A';

	HANDLE hadle3 = (HANDLE)_beginthread(myfun3, 0, &e);//传入参数
	Sleep(1000);
	if (GetExitCodeThread(hadle3, &sid))
		cout << "sid1: " << sid << endl;
	cout << "线程结束？" << endl;
	TerminateThread(handle2, sid + 10);
	Sleep(2000);

	GetExitCodeThread(handle2, &sid);
	cout << "sid2: " << sid << endl;
	cout << "线程被挂起" << endl;
	SuspendThread(handle);//suspend
	Sleep(2000);
	while (1)
	{
		cout << ++i << endl;
		Sleep(1000);
		if (i > 2)
			ResumeThread(handle);//resume
	}
	return 1;
}
