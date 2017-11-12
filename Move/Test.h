#pragma once
class Test
{
public:
	char *data;
	char name;
	int id;

public:

	//������
	Test(char _name)
	{
		//������ ����
		data = new char[1000000];
		id = cnt++;
		name = _name;

		cout << "id : " << id << "name : " << name << " ������ ȣ�� - �޸��� �ּ� : " << (void*)data << endl;
	}

	//��������� (Deep Copy)
	Test(const Test &other)
	{
		data = new char[1000000];
		memcpy(data, other.data, 1000000);
		id = cnt++;
		name = other.name;

		cout << "id : " << id << "name : " << name << " ��������� ȣ�� - �޸��� �ּ� : " << (void*)data << endl;
	}

	//�Ҵ翬����
	Test& operator =(const Test &other)
	{
		if (this == &other)
			return *this;
		delete[] data; // ���� �޸� �Ҹ�
		data = new char[1000000];
		memcpy(data, other.data, 1000000);
		name = other.name;

		cout << "id : " << id << "name : " << name << " �Ҵ翬���� - �޸��� �ּ� : " << (void*)data << endl;
		return *this;
	}

	Test(Test &&other)
	{
		id = other.id;
		data = other.data;
		other.data = nullptr;
		cout << id << " �̵������� - �޸����ּ� : " << (void *)data << endl;
	}



	//�Ҹ���
	~Test()
	{
		cout << "id : " << id << "name : " << name << " �Ҹ��� ȣ�� - �޸��� �ּ� : " << (void*)data << endl;
		delete[]data;
	}

	static int cnt;


};

