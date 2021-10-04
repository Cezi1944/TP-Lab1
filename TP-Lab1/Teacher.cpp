#include "Teacher.h"
#include <iostream>
Teacher::Teacher() {
	type = 2;
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