#pragma once
class Test
{
public:
	char *data;
	char name;
	int id;

public:

	//생성자
	Test(char _name)
	{
		//데이터 생성
		data = new char[1000000];
		id = cnt++;
		name = _name;

		cout << "id : " << id << "name : " << name << " 생성자 호출 - 메모리의 주소 : " << (void*)data << endl;
	}

	//복사생성자 (Deep Copy)
	Test(const Test &other)
	{
		data = new char[1000000];
		memcpy(data, other.data, 1000000);
		id = cnt++;
		name = other.name;

		cout << "id : " << id << "name : " << name << " 복사생성자 호출 - 메모리의 주소 : " << (void*)data << endl;
	}

	//할당연산자
	Test& operator =(const Test &other)
	{
		if (this == &other)
			return *this;
		delete[] data; // 기존 메모리 소멸
		data = new char[1000000];
		memcpy(data, other.data, 1000000);
		name = other.name;

		cout << "id : " << id << "name : " << name << " 할당연산자 - 메모리의 주소 : " << (void*)data << endl;
		return *this;
	}

	Test(Test &&other)
	{
		id = other.id;
		data = other.data;
		other.data = nullptr;
		cout << id << " 이동생성자 - 메모리의주소 : " << (void *)data << endl;
	}



	//소멸자
	~Test()
	{
		cout << "id : " << id << "name : " << name << " 소멸자 호출 - 메모리의 주소 : " << (void*)data << endl;
		delete[]data;
	}

	static int cnt;


};

