#include "Teacher.h"
#include <iostream>
Teacher::Teacher() {
	type = 2;
	cout << endl << "������� ��� �������������: ";
	while (!(cin >> Fio) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
	cout << endl << "������� ���������� �����: ";
	while (!(cin >> NumOfGroups) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
	groups = new string[NumOfGroups];
	for (int i = 0; i < NumOfGroups;i++) {
		cout << endl << "������� ����� ������: ";
		while (!(cin >> groups[i]) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "�������� ����!" << endl;
		}
	}

	cout << endl << "������� ���������� ���������: ";
	while (!(cin >> NumOfSubjects) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
	subjects = new string[NumOfSubjects];
	for (int i = 0;i < NumOfSubjects;i++) {
		cout << endl << "������� �������� ��������: ";
		while (!(cin >> subjects[i]) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "�������� ����!" << endl;
		}
	}

}