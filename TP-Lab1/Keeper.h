#pragma once
#include "VUZ.h"
class Keeper {
private :
	int filledN;//количество заполненных ячеек массива
	int n;// размер динамическго массива
	VUZ** mass;//указатель на динамический массив указателей
public:
	Keeper();
	~Keeper();
	void loadData(string fileName);
	void saveData(string fileName);
	void resizeMass();
};