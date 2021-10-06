#pragma once
#include "VUZ.h"
#include "Student.h"
#include "Teacher.h"
#include "Administration.h"
class Keeper {
private :
	int filledN;//количество заполненных ячеек массива
	int n;// размер динамическго массива
	VUZ** mass;//указатель на динамический массив указателей
public:
	Keeper();
	Keeper(ifstream& file);
	~Keeper();
	void loadData(ifstream& file);
	void saveData(ofstream& file);
	void resizeMass();
	int getN();
	int getFilledN();
};