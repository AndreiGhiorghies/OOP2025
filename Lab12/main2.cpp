#include <iostream>
#include "Materie.h"
#include "Student2.h"
#include "Catalog.h"

using namespace std;

int main() {

	CatalogRO catalogRO;
	CatalogEN catalogEN;

	Student2 s1("Ana Popescu", "123", "RO");
	Student2 s2("John Smith", "456", "RO");
	Student2 s3("Ion Popescu", "789", "EN");

	Matematica mate("Obligatorie", "Matematica", 5);
	Romana romana("Obligatorie", "Matematica", 5);
	Engleza engleza("Obligatorie", "Matematica", 5);
	Informatica info("Obligatorie", "Matematica", 5);
	Optional1 opt1("Obligatorie", "Matematica", 5);

	s1.AdaugaNota(mate, 9.5);
	s1.AdaugaNota(romana, 8.5);
	s1.AdaugaNota(info, 10);
	s2.AdaugaNota(engleza, 9.0);
	s2.AdaugaNota(mate, 8.0);
	s2.AdaugaNota(opt1, 7.0);
	s3.AdaugaNota(romana, 6.8);
	s3.AdaugaNota(info, 9.9);
	s3.AdaugaNota(opt1, 8.1);

	catalogRO.AdaugaStudent(s1);
	catalogRO.AdaugaStudent(s2);
	catalogEN.AdaugaStudent(s3);

	catalogRO.rankStudents();
	catalogEN.rankStudents();

	catalogRO.AfiseazaStudenti();
	catalogEN.AfiseazaStudenti();

	return 0;
}