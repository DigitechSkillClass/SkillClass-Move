// Move.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Test.h"
#include <utility>
#include <thread>
#include <Windows.h>
#include "cKeyManager.h"

int n이전온도 = 0;
int n현재온도 = 0;
bool is확인중 = false;

CRITICAL_SECTION cs;

void 온도체크()
{
	cKeyManager::GetInstance();
	while (true)
	{
		EnterCriticalSection(&cs);
		//is확인중 = true;
		//n이전온도 = n현재온도;
		n현재온도 = rand() % 100;
		n이전온도 = n현재온도 - 1;
		//is확인중 = false;
		LeaveCriticalSection(&cs);
	}
}

void 보일러가동()
{
	cKeyManager::GetInstance();
	while (true)
	{
		EnterCriticalSection(&cs);
		if (n현재온도 < n이전온도)
		{
			cout << "보일러가동" << endl;
		}
		LeaveCriticalSection(&cs);
	}
}

int main()
{
	int a = 3;
	int b = 2;
	volatile int c = 1;
	int d = b + c;

	/*
	F	D	E	W
	1	2	3	4
		1	2	3	4
			1	2	3	4
				1	2	3	4
	*/

	cKeyManager::GetInstance();
	cKeyManager::GetInstance();
	InitializeCriticalSection(&cs);

	thread t1(온도체크);
	thread t2(보일러가동);

	t1.join();
	t2.join();

	DeleteCriticalSection(&cs);
	//cin <<
	//scanf
	//recv
	Test a('a');
	Test b('b');
	vector<Test> vec;
	vec.push_back(move(a));
	vec.push_back(move(b));

    return 0;
}

