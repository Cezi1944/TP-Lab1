#include "Administration.h"
#include <iostream>
#include <fstream>
Administration::Administration() {
	type = 3;
	Fio = "0";
	post = "0";
	phoneNum = "0";
	Aor = "0";
	cout << "Вызван конструктор объекта класса Административный персонал" << endl;
}
Administration::Administration(Administration& original) {
	Fio = original.Fio;
	post = original.post;
	phoneNum = original.phoneNum;
	Aor = original.Aor;
	cout << "Вызван конструктор копирования объекта класса Административный персонал" << endl;
}
Administration::~Administration() {
	cout << "Вызван деструктор объекта класса Административный персонал" << endl;
}
string Administration::getFio() { return Fio; }
string Administration::getPost() { return post; }
string Administration::getPhoneNum() { return phoneNum;}
string Administration::getAor() { return Aor; }
void Administration::setFio(string NFio) { Fio = NFio; }
void Administration::setPost(string NPost) { post = NPost; }
void Administration::setPhoneNum(string NPhoneNum) { phoneNum = NPhoneNum; }
void Administration::setAor(string NAor) { Aor = NAor; }
void Administration::scanData() {
	cout << endl << "Введите ФИО административного персонала: ";
	while (!(cin >> Fio) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
	cout << endl << "ВВедите название должности: ";
	while (!(cin >> post) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
	cout << endl << "Введите номер телефона: ";
	while (!(cin >> phoneNum) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
	cout << endl << "Введите название области ответственности: ";
	while (!(cin >> Aor) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!" << endl;
	}
}
void Administration::printData() {
	cout << "ФИО: " << Fio << endl;
	cout << "Должность: " << post << endl;
	cout << "Телефон: " << phoneNum << endl;
	cout << "Область ответственности: " << Aor << endl;
}
void Administration::loadData(ifstream& file) {
	file >> Fio;
	file >> post;
	file >> phoneNum;
	file >> Aor;
}
void Administration::saveData(ofstream& file) {
	file << type << endl;
	file << Fio << endl;
	file << post << endl;
	file << phoneNum << endl;
	file << Aor << endl;
}
void Administration::changeData() {
	printData();
	int choise = -1;
	do {
		cout << " 1.ФИО\n2.Должность\n3.Телефон\n4.Область ответственности\n0.Выход\n Выберите пункт для изменения: ";
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
			cout << endl << "ВВедите должность: ";
			while (!(cin >> post) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Неверный ввод!" << endl;
			}
			break;
		case 3:
			cout << endl << "Введите номер телефона: ";
			while (!(cin >> phoneNum) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Неверный ввод!" << endl;
			}
			break;
		case 4:
			cout << endl << "Введите область ответственности: ";
			while (!(cin >> Aor) || (cin.peek() != '\n'))
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