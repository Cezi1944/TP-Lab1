#pragma once
#include "VUZ.h"
using namespace std;
class Administration :public VUZ {
protected:
	string post;
	string phoneNum;
	string Aor;
public:
	Administration();
	Administration(Administration& original);
};