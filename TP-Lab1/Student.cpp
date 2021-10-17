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
	file << Fio << endl;
	file << group << endl;
	file << specialization << endl;
	file << course << endl;
	file << AvScore << endl;
}