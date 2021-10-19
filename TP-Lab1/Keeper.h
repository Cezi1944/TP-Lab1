#pragma once
#include "VUZ.h"
#include "Student.h"
#include "Teacher.h"
#include "Administration.h"
#include "VUZCreator.h"
class Keeper {
private :
	VUZCreator creator;
	int filledN;//���������� ����������� ����� �������
	int n;// ������ ������������ �������
	VUZ** mass;//��������� �� ������������ ������ ����������
public:
	Keeper();
	~Keeper();
	void loadData(ifstream& file);
	void saveData(ofstream& file);
	void printData();
	void changeData();
	void destroyData();
	void addData();
	void resizeMass();
	int getN();
	int getFilledN();
};