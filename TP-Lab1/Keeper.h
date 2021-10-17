#pragma once
#include "VUZ.h"
#include "Student.h"
#include "Teacher.h"
#include "Administration.h"
#include "VUZCreator.h"
class Keeper {
private :
	VUZCreator creator;
	int filledN;//количество заполненных ячеек массива
	int n;// размер динамическго массива
	VUZ** mass;//указатель на динамический массив указателей
public:
	Keeper();
	~Keeper();
	void loadData(ifstream& file);
	void saveData(ofstream& file);
	void resizeMass();
	int getN();
	int getFilledN();
};