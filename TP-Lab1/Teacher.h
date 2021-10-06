#pragma once
#include "VUZ.h"
using namespace std;
class Teacher :public VUZ {
protected:
	int NumOfGroups;
	int NumOfSubjects;
	string* groups;
	string* subjects;
public:
	Teacher(Teacher& original);
	Teacher();
	Teacher(ifstream& file);
	~Teacher() override;
	void printData() override;
	void scanData() override;
	void saveData(ifstream& file) override;
	void loadData(ifstream& file) override;
	string getFio();
	void setFio(string NFio);
	int getNumOfGroups();
	int getNumOfSubjects();
	string& getGroups();
	string& getSubjects();
};