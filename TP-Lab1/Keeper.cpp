#include "Keeper.h"
#include <iostream>
#include <fstream>

using namespace std;
Keeper::Keeper() {
	filledN = 0;
	n = 8;
	mass =(VUZ**) malloc(n*sizeof(VUZ*));
}

void Keeper::loadData(ifstream& file) {
	int type = 0;
	bool corrupted = 0;
	file >> filledN;
	while (n<filledN)
		resizeMass();
	for (int i = 0; i < n; i++) {
		file >> type;
		mass[i] = NULL;
		mass[i] = &creator.CreateVUZ(type);
		if (mass[i] == NULL)
			cout << "Данные повреждены!" << endl;
		else
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
void Keeper::destroyData() {
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
void Keeper::addData() {
	filledN += 1;
	resizeMass();
	mass[filledN] = &creator.CreateVUZ();
	mass[filledN]->scanData();
}