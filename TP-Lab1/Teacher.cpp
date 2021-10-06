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
Teacher::Teacher(Teacher& original) {
	Fio = original.Fio;
	NumOfGroups = original.NumOfGroups;
	groups = new string[NumOfGroups];
	for (int i = 0; i < NumOfGroups;i++)
		groups[i] = original.groups[i];
	NumOfSubjects = original.NumOfSubjects;
	subjects = new string[NumOfSubjects];
	for (int i = 0; i < NumOfSubjects;i++)
		subjects[i] = original.subjects[i];
}
Teacher::~Teacher() {
	delete[] groups;
	delete[] subjects;
}
int Teacher::getNumOfGroups() { return NumOfGroups; }
int Teacher::getNumOfSubjects() { return NumOfSubjects; }
string& Teacher::getGroups() {
	string* copy = new string[NumOfGroups];
	for (int i = 0; i < NumOfGroups;i++) {
		copy[i] = groups[i];
	}
	return *copy;
}
string& Teacher::getSubjects() {
	string* copy = new string[NumOfSubjects];
	for (int i = 0; i < NumOfSubjects;i++) {
		copy[i] = subjects[i];
	}
	return *copy;
}
string Teacher::getFio() { return Fio; }
void Teacher::setFio(string NFio) { Fio = NFio; }