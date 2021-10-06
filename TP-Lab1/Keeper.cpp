#include "Keeper.h"
#include <iostream>
#include <fstream>

using namespace std;
Keeper::Keeper() {
	filledN = 0;
	n = 8;
	mass =(VUZ**) malloc(n*sizeof(VUZ*));
}
Keeper::Keeper(ifstream& file) {
	int type = 0;
	bool corrupted = 0;
	file >> n;
	filledN = n;
	mass = new VUZ*[n];
	for (int i = 0; i < n; i++) {
		file >> type;
		switch (type)
		{
		case 1:
			mass[i] = new Student(file);
			break;
		case 2:
			mass[i] = new Teacher(file);
			break;
		case 3:
			mass[i] = new Administration(file);
			break;
		default:
			cout << "Ôאיכ ןמגנוזה¸ם";
			corrupted = 1;
			break;
		}
		if (corrupted == 1)
		{
			for ( int i = 0; i<filledN; i++)
				delete[] mass[i];
			delete[] mass;
			break;
		}

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