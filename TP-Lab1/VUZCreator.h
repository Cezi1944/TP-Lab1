#pragma once
#include "VUZ.h"
#include "Student.h"
#include "Teacher.h"
#include "Administration.h"
#include <iostream>
class VUZCreator {
public:
	VUZ& CreateVUZ(int type) {
		switch (type)
		{
		case 1:
			return *(new Student());
			break;
		case 2:
			return *(new Teacher());
			break;
		case 3:
			return *(new Administration());
			break;
		default:
			throw "�������������� ��� ������ VUZ";
			break;
		}
	}
	VUZ& CreateVUZ() {
		int type = 0;
		cout << "1.�������\n2.�������������\n3.���������������� ��������\n";
		cout << "�������� ��� ������� (1-3): ";
		while (!(cin >> type) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "�������� ����!" << endl;
		}
		return CreateVUZ(type);
	}
};