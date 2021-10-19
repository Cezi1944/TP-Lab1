#include "Teacher.h"
#include <iostream>
#include <fstream>
Teacher::Teacher() {
	type = 2;
	Fio = "0";
	NumOfGroups = 0;
	FilledNumOfGroups = 0;
	groups = NULL;
	NumOfSubjects = 0;
	FilledNumOfSubjects = 0;
	subjects = NULL;

}
Teacher::Teacher(Teacher& original) {
	Fio = original.Fio;
	NumOfGroups = original.NumOfGroups;
	FilledNumOfGroups = original.FilledNumOfGroups;
	groups = new string[NumOfGroups];
	for (int i = 0; i < NumOfGroups;i++)
		groups[i] = original.groups[i];
	NumOfSubjects = original.NumOfSubjects;
	FilledNumOfSubjects = original.FilledNumOfSubjects;
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
	string* copy = new string[FilledNumOfGroups];
	for (int i = 0; i < FilledNumOfGroups;i++) {
		copy[i] = groups[i];
	}
	return *copy;
}
string& Teacher::getSubjects() {
	string* copy = new string[FilledNumOfSubjects];
	for (int i = 0; i < FilledNumOfSubjects;i++) {
		copy[i] = subjects[i];
	}
	return *copy;
}
string Teacher::getFio() { return Fio; }
void Teacher::setFio(string NFio) { Fio = NFio; }
void Teacher::scanData() {
	delete[] groups;
	delete[] subjects;
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
	FilledNumOfGroups = NumOfGroups;
	groups = new string[FilledNumOfGroups];
	for (int i = 0; i < FilledNumOfGroups;i++) {
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
	FilledNumOfSubjects = NumOfSubjects;
	subjects = new string[FilledNumOfSubjects];
	for (int i = 0;i < FilledNumOfSubjects;i++) {
		cout << endl << "������� �������� ��������: ";
		while (!(cin >> subjects[i]) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "�������� ����!" << endl;
		}
	}
}
void Teacher::printData() {
	cout << "���: " << Fio << endl;
	cout << "������: " << endl;
	for (int i = 0; i < FilledNumOfGroups; i++)
		cout << "\t" << i+1 << ". " << groups[i] << endl;
	cout << "��������: " << endl;
	for (int i = 0; i < FilledNumOfSubjects; i++)
		cout << "\t" << subjects[i] << endl;
}
void Teacher::loadData(ifstream& file) {
	file >> Fio;
	file >> NumOfGroups;
	FilledNumOfGroups = NumOfGroups;
	groups = new string[FilledNumOfGroups];
	for (int i = 0; i < FilledNumOfGroups;i++)
		file >> groups[i];
	file >> NumOfSubjects;
	FilledNumOfSubjects = NumOfSubjects;
	subjects = new string[FilledNumOfSubjects];
	for (int i = 0;i < FilledNumOfSubjects;i++)
		file >> subjects[i];

}
void Teacher::saveData(ofstream& file) {
	file << type << endl;
	file << Fio << endl;
	file << FilledNumOfGroups << endl;
	for (int i = 0; i < FilledNumOfGroups;i++)
		file << groups[i] << endl;
	file << FilledNumOfSubjects << endl;
	for (int i = 0;i < FilledNumOfSubjects;i++)
		file << subjects[i] << endl;
}
void Teacher::changeData() {
	printData();
	int group = 0;
	int subject = 0;
	int choise = -1;

	cout << " 1.���\n2.������\n3.��������\n0.�����\n �������� ����� ��� ���������: ";
	do {
		while (!(cin >> choise) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "�������� ����!" << endl;
		}
		switch (choise)
		{
		case 0:
			break;
		case 1:
			cout << endl << "������� ���: ";
			while (!(cin >> Fio) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "�������� ����!" << endl;
			}
			break;
		case 2:
			cout << endl << "�������� ����� ������ (1-" << FilledNumOfGroups << "): ";
			while (!(cin >> group) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "�������� ����!" << endl;
			}
			if (group < 1 || group > FilledNumOfGroups) {
				cout << endl << "�������� � ����� ������� �� ����������!"<<endl;
				break;
			}
			else
			{
				cout << endl << "������� ����� ������: ";
				while (!(cin >> groups[group-1]) || (cin.peek() != '\n'))
				{
					cin.clear();
					while (cin.get() != '\n');
					cout << "�������� ����!" << endl;
				}
			}
			break;
		case 3:
			cout << endl << "�������� ����� �������� (1-" << FilledNumOfSubjects << "): ";
			while (!(cin >> subject) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "�������� ����!" << endl;
			}
			if (subject < 1 || subject > FilledNumOfSubjects) {
				cout << endl << "�������� � ����� ������� �� ����������!" << endl;
				break;
			}else
			{
				cout << endl << "������� �������� ��������: ";
				while (!(cin >> subjects[subject-1]) || (cin.peek() != '\n'))
				{
					cin.clear();
					while (cin.get() != '\n');
					cout << "�������� ����!" << endl;
				}
			}
			break;
		default:
			cout << "�������� ����!" << endl;
			break;
		}
	} while (choise != 0);
}
