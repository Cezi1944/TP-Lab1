#include "Student.h"
#include <iostream>
#include <fstream>
Student::Student() {
	type = 1;
	Fio = "0";
	group = "0";
	specialization = "0";
	course = 0;
	AvScore = 0;
}
Student::Student(Student& original) {
	Fio = original.Fio;
	group = original.group;
	specialization = original.specialization;
	course = original.course;
	AvScore = original.AvScore;
}
string Student::getGroup() { return group; }
string Student::getFio() { return Fio; }
string Student::getSpecialization() { return specialization; }
int Student::getCourse() { return course; }
float Student::getAvScore() { return AvScore; }
void Student::setGroup(string Ngroup) { group = Ngroup; }
void Student::setFio(string NFio) { Fio = NFio; }
void Student::setSpecialization(string Nspecialization) { specialization = Nspecialization; }
void Student::setCourse(int Ncourse) { course = Ncourse; }
void Student::setAvScore(float NAvScore) { AvScore = NAvScore; }
void Student::scanData() {
	cout << endl << "Введите ФИО студента: ";
	while (!(cin >> Fio) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
	cout << endl << "ВВедите номер группы: ";
	while (!(cin >> group) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
	cout << endl << "Введите название специальности: ";
	while (!(cin >> specialization) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
	cout << endl << "Введите номер курса: ";
	while (!(cin >> course) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
	cout << endl << "Введите средний бал: ";
	while (!(cin >> AvScore) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
}
void Student::printData() {
	cout << "ФИО: " << Fio << endl;
	cout << "Группа: " << group << endl;
	cout << "Специализация: " << specialization << endl;
	cout << "Курс: " << course << endl;
	cout << "Средний балл: " << AvScore << endl;
}
void Student::loadData(ifstream& file) {
	file >> Fio;
	file >> group;
	file >> specialization;
	file >> course;
	file >> AvScore;
}
void Student::saveData(ofstream& file) {
	file << type << endl;
	file << Fio << endl;
	file << group << endl;
	file << specialization << endl;
	file << course << endl;
	file << AvScore << endl;
}
void Student::changeData() {
	printData();
	int choise = -1;
	cout << " 1.ФИО\n2.Группа\n3.Специализация\n4.Курс\n5.Средний балл\n0.Выход\n Выберите пункт для изменения: ";
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
			cout << endl << "ВВедите номер группы: ";
			while (!(cin >> group) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Неверный ввод!" << endl;
			}
			break;
		case 3:
			cout << endl << "Введите название специальности: ";
			while (!(cin >> specialization) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Неверный ввод!" << endl;
			}
			break;
		case 4:
			cout << endl << "Введите номер курса: ";
			while (!(cin >> course) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Неверный ввод!" << endl;
			}
			break;
		case 5:
			cout << endl << "Введите средний бал: ";
			while (!(cin >> AvScore) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Неверный ввод!" << endl;
			}
			break;
		default:
			cout << "Неверный ввод!" << endl;
			break;
		}
	} while (choise != 0);
}