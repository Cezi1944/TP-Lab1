#pragma once
#include "VUZ.h"
#include "Student.h"
#include "Teacher.h"
#include "Administration.h"
class VUZCreator {
public:
	VUZ& CreateVUZ(int type) {
		switch (type)
		{
		case 1:
			return *(new Student());
			break;
		case 2:
			return *(new Teacher());
			break;
		case 3:
			return *(new Administration());
			break;
		default:
			break;
		}
	}
};