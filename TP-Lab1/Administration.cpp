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