#include "Keeper.h"
#include <iostream>
#include <fstream>

using namespace std;
Keeper::Keeper() {
	filledN = 0;
	n = 8;
	mass =(VUZ**) malloc(n*sizeof(VUZ*));
	cout << "Вызван конструкстор класса Keeper" << endl;
}

void Keeper::loadData(ifstream& file) {
	for (int i = 0; i < filledN; i++)
		delete[] mass[i];
	free(mass);
	int type = 0;
	file >> filledN;
	mass = (VUZ**)malloc(n * sizeof(VUZ*));
	for (int i = 0; i < filledN; i++) {
		file >> type;
		mass[i] = &creator.CreateVUZ(type);
		mass[i]->loadData(file);
	}
}
void Keeper::saveData(ofstream& file) {
	file << filledN << endl;
	for (int i = 0;i < filledN;i++)
		mass[i]->saveData(file);
}
Keeper::~Keeper() {
	for (int i = 0; i < filledN; i++)
		delete[] mass[i];
	free(mass);
	cout << "Вызван деструктор объекта класса Keeper" << endl;
}
void Keeper::resizeMass() {
	if (filledN >= n) {
		n = n * 2;
		VUZ** buf = (VUZ**)realloc(*mass, n * sizeof(VUZ*));
		mass = buf;
	}
}
int Keeper::getN() { return n; }
int Keeper::getFilledN() { return filledN; }
void Keeper::printData() {
	for (int i = 0; i < filledN;i++) {
		cout << "-" << i << "-" << endl;
		mass[i]->printData();
	}
}
void Keeper::changeData() {
	if (filledN == 0)
		cout << "База пуста!" << endl;
	else {
		int choise = -1;
		cout << "Выберите номер записи (0-" << filledN - 1 << "): ";
		while (!(cin >> choise) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Неверный ввод!" << endl;
		}
		if (choise >= 0 && choise < filledN) {
			mass[choise]->changeData();
		}
	}
}
void Keeper::destroyData() {
	if (filledN == 0)
		cout << "База пуста!" << endl;
	else {
		int choise = -1;
		cout << "Выберите номер записи (0-" << filledN - 1 << "): ";
		while (!(cin >> choise) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Неверный ввод!" << endl;
		}
		delete[] mass[choise];
		if (choise >= 0 && choise < filledN) {
			for (int i = choise;i < filledN - 1;i++) {
				mass[i] = mass[i + 1];
			}
			filledN -= 1;

		}
	}

}
void Keeper::addData() {
	resizeMass();
	mass[filledN] = &creator.CreateVUZ();
	mass[filledN]->scanData();
	filledN += 1;
}