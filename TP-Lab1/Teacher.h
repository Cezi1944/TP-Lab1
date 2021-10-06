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
	string getFio();
	void setFio(string NFio);
	int getNumOfGroups();
	int getNumOfSubjects();
	string& getGroups();
	string& getSubjects();
};