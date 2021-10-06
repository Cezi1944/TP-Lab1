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
	Student(ifstream& file);
	Student(Student& original);
	void printData() override;
	void scanData() override;
	void saveData(ifstream& file) override;
	void loadData(ifstream& file) override;
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