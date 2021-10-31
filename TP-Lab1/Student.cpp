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
	cout << "������ ����������� ������� ������ �������" << endl;
}
Student::Student(Student& original) {
	Fio = original.Fio;
	group = original.group;
	specialization = original.specialization;
	course = original.course;
	AvScore = original.AvScore;
	cout << "������ ����������� ����������� ������� ������ �������" << endl;
}
Student::~Student() {
	cout << "������ ���������� ������� ������ �������" << endl;
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
	cout << endl << "������� ��� ��������: ";
	while (!(cin >> Fio) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
	cout << endl << "������� ����� ������: ";
	while (!(cin >> group) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
	cout << endl << "������� �������� �������������: ";
	while (!(cin >> specialization) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
	cout << endl << "������� ����� �����: ";
	while (!(cin >> course) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
	cout << endl << "������� ������� ���: ";
	while (!(cin >> AvScore) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
}
void Student::printData() {
	cout << "���: " << Fio << endl;
	cout << "������: " << group << endl;
	cout << "�������������: " << specialization << endl;
	cout << "����: " << course << endl;
	cout << "������� ����: " << AvScore << endl;
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

	do {
		cout << " 1.���\n2.������\n3.�������������\n4.����\n5.������� ����\n0.�����\n �������� ����� ��� ���������: ";
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
			cout << endl << "������� ����� ������: ";
			while (!(cin >> group) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "�������� ����!" << endl;
			}
			break;
		case 3:
			cout << endl << "������� �������� �������������: ";
			while (!(cin >> specialization) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "�������� ����!" << endl;
			}
			break;
		case 4:
			cout << endl << "������� ����� �����: ";
			while (!(cin >> course) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "�������� ����!" << endl;
			}
			break;
		case 5:
			cout << endl << "������� ������� ���: ";
			while (!(cin >> AvScore) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "�������� ����!" << endl;
			}
			break;
		default:
			cout << "�������� ����!" << endl;
			break;
		}
	} while (choise != 0);
}