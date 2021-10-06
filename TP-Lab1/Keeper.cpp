#include "Keeper.h"
Keeper::Keeper() {
	filledN = 0;
	n = 8;
	*mass =(VUZ*) malloc(n*sizeof(VUZ*));
}
Keeper::~Keeper() {
	for (int i = 0; i < filledN; i++)
		delete[] mass[i];
	free(mass);
}
void Keeper::resizeMass() {
	if (filledN >= n) {
		n = n * 2;
		realloc(*mass, n * sizeof(VUZ*));
	}
}
int Keeper::getN() { return n; }
int Keeper::getFilledN() { return filledN; }