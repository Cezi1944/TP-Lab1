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
	file >> n;
	filledN = n;
	mass = new VUZ*[n];
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
Keeper::~Keeper() {
	for (int i = 0; i < filledN; i++)
		delete[] mass[i];
	delete[] mass;
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