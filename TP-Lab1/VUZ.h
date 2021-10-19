#pragma once
#include <string>
using namespace std;
class VUZ {
public:
	VUZ() {};
	virtual ~VUZ() {};
	virtual void printData() = 0;
	virtual void scanData() = 0;
	virtual void saveData(ofstream& file) = 0;
	virtual void loadData(ifstream& file) = 0;
	virtual void changeData() = 0;
protected:
	string Fio;
	int type = 0;
};