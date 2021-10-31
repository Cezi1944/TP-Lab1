#include "Administration.h"
#include <iostream>
#include <fstream>
Administration::Administration() {
	type = 3;
	Fio = "0";
	post = "0";
	phoneNum = "0";
	Aor = "0";
	cout << "������ ����������� ������� ������ ���������������� ��������" << endl;
}
Administration::Administration(Administration& original) {
	Fio = original.Fio;
	post = original.post;
	phoneNum = original.phoneNum;
	Aor = original.Aor;
	cout << "������ ����������� ����������� ������� ������ ���������������� ��������" << endl;
}
Administration::~Administration() {
	cout << "������ ���������� ������� ������ ���������������� ��������" << endl;
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
	cout << endl << "������� ��� ����������������� ���������: ";
	while (!(cin >> Fio) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
	cout << endl << "������� �������� ���������: ";
	while (!(cin >> post) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
	cout << endl << "������� ����� ��������: ";
	while (!(cin >> phoneNum) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
	cout << endl << "������� �������� ������� ���������������: ";
	while (!(cin >> Aor) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!" << endl;
	}
}
void Administration::printData() {
	cout << "���: " << Fio << endl;
	cout << "���������: " << post << endl;
	cout << "�������: " << phoneNum << endl;
	cout << "������� ���������������: " << Aor << endl;
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
		cout << " 1.���\n2.���������\n3.�������\n4.������� ���������������\n0.�����\n �������� ����� ��� ���������: ";
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
			cout << endl << "������� ���������: ";
			while (!(cin >> post) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "�������� ����!" << endl;
			}
			break;
		case 3:
			cout << endl << "������� ����� ��������: ";
			while (!(cin >> phoneNum) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "�������� ����!" << endl;
			}
			break;
		case 4:
			cout << endl << "������� ������� ���������������: ";
			while (!(cin >> Aor) || (cin.peek() != '\n'))
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