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