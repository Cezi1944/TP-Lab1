#pragma once
#include "VUZ.h"
using namespace std;
class Student :public VUZ {
protected:
	string group;
	string specialization;
	int course;
	float AvScore;
};