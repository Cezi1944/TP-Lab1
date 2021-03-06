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
	~Administration();
	void printData() override;
	void scanData() override;
	void saveData(ofstream& file) override;
	void loadData(ifstream& file) override;
	void changeData() override;
	string getFio();
	string getPost();
	string getPhoneNum();
	string getAor();
	void setFio(string NFio);
	void setPost(string NPost);
	void setPhoneNum(string NPhoneNum);
	void setAor(string NAor);
};