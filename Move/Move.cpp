// Move.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Test.h"
#include <utility>
#include <thread>
#include <Windows.h>
#include "cKeyManager.h"

int n�����µ� = 0;
int n����µ� = 0;
bool isȮ���� = false;

CRITICAL_SECTION cs;

void �µ�üũ()
{
	cKeyManager::GetInstance();
	while (true)
	{
		EnterCriticalSection(&cs);
		//isȮ���� = true;
		//n�����µ� = n����µ�;
		n����µ� = rand() % 100;
		n�����µ� = n����µ� - 1;
		//isȮ���� = false;
		LeaveCriticalSection(&cs);
	}
}

void ���Ϸ�����()
{
	cKeyManager::GetInstance();
	while (true)
	{
		EnterCriticalSection(&cs);
		if (n����µ� < n�����µ�)
		{
			cout << "���Ϸ�����" << endl;
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

	thread t1(�µ�üũ);
	thread t2(���Ϸ�����);

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

