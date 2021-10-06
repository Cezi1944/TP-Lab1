#pragma once
#include "VUZ.h"
#include "Student.h"
#include "Teacher.h"
#include "Administration.h"
class Keeper {
private :
	int filledN;//���������� ����������� ����� �������
	int n;// ������ ������������ �������
	VUZ** mass;//��������� �� ������������ ������ ����������
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