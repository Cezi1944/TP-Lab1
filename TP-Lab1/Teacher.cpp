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
	cout << endl << "Введите ФИО преподавателя: ";
	while (!(cin >> Fio) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
	cout << endl << "Укажите количество групп: ";
	while (!(cin >> NumOfGroups) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
	FilledNumOfGroups = NumOfGroups;
	groups = new string[FilledNumOfGroups];
	for (int i = 0; i < FilledNumOfGroups;i++) {
		cout << endl << "Введите номер группы: ";
		while (!(cin >> groups[i]) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Неверный ввод!" << endl;
		}
	}

	cout << endl << "Укажите количество предметов: ";
	while (!(cin >> NumOfSubjects) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
	FilledNumOfSubjects = NumOfSubjects;
	subjects = new string[FilledNumOfSubjects];
	for (int i = 0;i < FilledNumOfSubjects;i++) {
		cout << endl << "Введите название предмета: ";
		while (!(cin >> subjects[i]) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Неверный ввод!" << endl;
		}
	}
}
void Teacher::printData() {
	cout << "ФИО: " << Fio << endl;
	cout << "Группы: " << endl;
	for (int i = 0; i < FilledNumOfGroups; i++)
		cout << "\t" << i+1 << ". " << groups[i] << endl;
	cout << "Предметы: " << endl;
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

	cout << " 1.ФИО\n2.Группы\n3.Предметы\n0.Выход\n Выберите пункт для изменения: ";
	do {
		while (!(cin >> choise) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Неверный ввод!" << endl;
		}
		switch (choise)
		{
		case 0:
			break;
		case 1:
			cout << endl << "Введите ФИО: ";
			while (!(cin >> Fio) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Неверный ввод!" << endl;
			}
			break;
		case 2:
			cout << endl << "Выберите номер группы (1-" << FilledNumOfGroups << "): ";
			while (!(cin >> group) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Неверный ввод!" << endl;
			}
			if (group < 1 || group > FilledNumOfGroups) {
				cout << endl << "Варианта с таким номером не существует!"<<endl;
				break;
			}
			else
			{
				cout << endl << "Введите номер группы: ";
				while (!(cin >> groups[group-1]) || (cin.peek() != '\n'))
				{
					cin.clear();
					while (cin.get() != '\n');
					cout << "Неверный ввод!" << endl;
				}
			}
			break;
		case 3:
			cout << endl << "Выберите номер предмета (1-" << FilledNumOfSubjects << "): ";
			while (!(cin >> subject) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Неверный ввод!" << endl;
			}
			if (subject < 1 || subject > FilledNumOfSubjects) {
				cout << endl << "Варианта с таким номером не существует!" << endl;
				break;
			}else
			{
				cout << endl << "Введите название предмета: ";
				while (!(cin >> subjects[subject-1]) || (cin.peek() != '\n'))
				{
					cin.clear();
					while (cin.get() != '\n');
					cout << "Неверный ввод!" << endl;
				}
			}
			break;
		default:
			cout << "Неверный ввод!" << endl;
			break;
		}
	} while (choise != 0);
}
