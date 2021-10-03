#pragma once
#include <string>
using namespace std;
class VUZ {
public:
	VUZ() {};
	~VUZ() {};
	virtual void printData() = 0;
	virtual void scanData() = 0;
	virtual void saveData(string fileName) = 0;
	virtual void loadData(string fileName) = 0;
private:
	string Fio;
	int type = 0;
};