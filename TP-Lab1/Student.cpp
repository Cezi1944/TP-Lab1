#include "Student.h"
#include <iostream>
Student::Student() {
	type = 1;
	cout << endl <<"������� ��� ��������: " ;
	while (!(cin >> Fio) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
	cout << endl << "������� ����� ������: ";
	while (!(cin >> group) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
	cout << endl << "������� �������� �������������: ";
	        while (!(cin >> specialization) || (cin.peek() != '\n'))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "�������� ����!" << endl;
        }
	cout << endl << "������� ����� �����: ";
	while (!(cin >> course) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
	cout << endl << "������� ������� ���: ";
	while (!(cin >> AvScore) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
}
Student::Student(Student& original) {
	Fio = original.Fio;
	group = original.group;
	specialization = original.specialization;
	course = original.course;
	AvScore = original.AvScore;
}