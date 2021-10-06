#include "Administration.h"
#include <iostream>
Administration::Administration() {
	type = 3;
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
Administration::Administration(Administration& original) {
	Fio = original.Fio;
	post = original.post;
	phoneNum = original.phoneNum;
	Aor = original.Aor;
}
string Administration::getFio() { return Fio; }
string Administration::getPost() { return post; }
string Administration::getPhoneNum() { return phoneNum;}
string Administration::getAor() { return Aor; }
void Administration::setFio(string NFio) { Fio = NFio; }
void Administration::setPost(string NPost) { post = NPost; }
void Administration::setPhoneNum(string NPhoneNum) { phoneNum = NPhoneNum; }
void Administration::setAor(string NAor) { Aor = NAor; }