#pragma once
#include <string>
using namespace std;
class VUZ {
public:
	VUZ() {};
	VUZ(string fileName) {};
	virtual ~VUZ() {};
	virtual void printData() = 0;
	virtual void scanData() = 0;
	virtual void saveData(string fileName) = 0;
	virtual void loadData(string fileName) = 0;
protected:
	string Fio;
	int type = 0;
};