#pragma once
#include "VUZ.h"
using namespace std;
class Teacher :public VUZ {
protected:
	int NumOfGroups;
	int NumOfSubjects;
	int FilledNumOfGroups;
	int FilledNumOfSubjects;
	string* groups;
	string* subjects;
public:
	Teacher(Teacher& original);
	Teacher();
	~Teacher() override;
	void printData() override;
	void scanData() override;
	void saveData(ofstream& file) override;
	void loadData(ifstream& file) override;
	void changeData() override;
	string getFio();
	void setFio(string NFio);
	int getNumOfGroups();
	int getNumOfSubjects();
	string& getGroups();
	string& getSubjects();

};