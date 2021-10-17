#include "Teacher.h"
#include <iostream>
#include <fstream>
Teacher::Teacher() {
	type = 2;
	Fio = "0";
	NumOfGroups = 0;
	groups = NULL;
	NumOfSubjects = 0;
	subjects = NULL;

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
	groups = new string[NumOfGroups];
	for (int i = 0; i < NumOfGroups;i++) {
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
	subjects = new string[NumOfSubjects];
	for (int i = 0;i < NumOfSubjects;i++) {
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
	for (int i = 0; i < NumOfGroups; i++)
		cout << "\t" << groups[i] << endl;
	cout << "Предметы: " << endl;
	for (int i = 0; i < NumOfSubjects; i++)
		cout << "\t" << subjects[i] << endl;
}
void Teacher::loadData(ifstream& file) {
	file >> Fio;
	file >> NumOfGroups;
	groups = new string[NumOfGroups];
	for (int i = 0; i < NumOfGroups;i++)
		file >> groups[i];
	file >> NumOfSubjects;
	subjects = new string[NumOfSubjects];
	for (int i = 0;i < NumOfSubjects;i++)
		file >> subjects[i];

}
void Teacher::saveData(ofstream& file) {
	file << Fio << endl;
	file << NumOfGroups << endl;
	groups = new string[NumOfGroups];
	for (int i = 0; i < NumOfGroups;i++)
		file << groups[i] << endl;
	file << NumOfSubjects << endl;
	subjects = new string[NumOfSubjects];
	for (int i = 0;i < NumOfSubjects;i++)
		file << subjects[i] << endl;
}