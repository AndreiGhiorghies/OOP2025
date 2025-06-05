#pragma once
#include <vector>
#include "Student2.h"
class Catalog
{
protected:
	std::vector<Student2> studenti;

public:
	void AdaugaStudent(Student2& s);
	virtual void rankStudents() = 0;
	virtual void AfiseazaStudenti() = 0;
	void rankStudentsGlobal();
	void AfiseazaStudentiGlobal();
};

class CatalogRO : public Catalog {
public:
	void rankStudents() override;
	void AfiseazaStudenti() override;
};

class CatalogEN : public Catalog {
public:
	void rankStudents() override;
	void AfiseazaStudenti() override;
};

