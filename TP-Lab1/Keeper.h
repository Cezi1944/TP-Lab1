#pragma once
#include "VUZ.h"
class Keeper {
private :
	int filledN;//���������� ����������� ����� �������
	int n;// ������ ������������ �������
	VUZ** mass;//��������� �� ������������ ������ ����������
public:
	Keeper();
	~Keeper();
	void loadData(string fileName);
	void saveData(string fileName);
	void resizeMass();
	int getN();
	int getFilledN();
};