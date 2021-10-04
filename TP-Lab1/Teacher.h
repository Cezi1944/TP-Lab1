#pragma once
#include "VUZ.h"
using namespace std;
class Teacher :public VUZ {
private:
	int NumOfGroups;
	int NumOfSubjects;
	string* groups;
	string* subjects;
};