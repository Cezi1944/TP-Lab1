#pragma once
#include "VUZ.h"
using namespace std;
class Student :public VUZ {
protected:
	string group;
	string specialization;
	int course;
	float AvScore;
public:
	Student();
	Student(Student& original);
	~Student();
	void printData() override;
	void scanData() override;
	void saveData(ofstream& file) override;
	void loadData(ifstream& file) override;
	void changeData() override;
	string getGroup();
	string getFio();
	string getSpecialization();
	int getCourse();
	float getAvScore();
	void setGroup(string Ngroup);
	void setFio(string NFio);
	void setSpecialization(string Nspecialization);
	void setCourse(int Ncourse);
	void setAvScore(float NAvScore);
};