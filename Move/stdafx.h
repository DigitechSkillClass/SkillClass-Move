// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include <iostream>
#include <vector>

using namespace std;

#define SINGLETON(class_name) private:\
class_name();\
~class_name();\
class_name(class_name const&) = delete;\
class_name(class_name&&) = delete;\
class_name& operator=(class_name const&) = delete;\
class_name& operator=(class_name &&) = delete;\
public:\
	static class_name* GetInstance()\
	{\
		static class_name instance;\
		return &instance;\
	}
