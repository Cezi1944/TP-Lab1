#include "Student.h"
#include <iostream>
Student::Student() {
	type = 1;
	cout << endl <<"Введите ФИО студента: " ;
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
Student::Student(Student& original) {
	Fio = original.Fio;
	group = original.group;
	specialization = original.specialization;
	course = original.course;
	AvScore = original.AvScore;
}