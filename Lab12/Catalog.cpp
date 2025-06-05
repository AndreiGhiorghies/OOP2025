#include "Catalog.h"
#include "Student2.h"
#include <algorithm>
#include <iostream>

void Catalog::AdaugaStudent(Student2& s)
{
	studenti.push_back(s);
}

void Catalog::rankStudentsGlobal()
{
	sort(studenti.begin(), studenti.end(), [](Student2& a, Student2& b) {return a.GetMedia() > b.GetMedia(); });
}

void Catalog::AfiseazaStudentiGlobal()
{
	for (auto i : studenti)
		std::cout << i.GetNume() << " : " << i.GetNumarMatricol() << " : " << i.GetProgramDeInvatare() << " -> " << i.GetMedia() << std::endl;
}

void CatalogRO::rankStudents()
{
	sort(studenti.begin(), studenti.end(), [](Student2& a, Student2& b) {
		if(a.GetProgramDeInvatare() == "RO" && b.GetProgramDeInvatare() == "RO")
			return a.GetMedia() > b.GetMedia();
		if (b.GetProgramDeInvatare() == "RO")
			return true;
		return false;
	});
}

void CatalogRO::AfiseazaStudenti()
{
	std::cout << "Studenti la Romana: " << std::endl;
	for(auto i : studenti)
		if(i.GetProgramDeInvatare() == "RO")
			std::cout << i.GetNume() << " : " << i.GetNumarMatricol() << " -> " << i.GetMedia() << std::endl;
}

void CatalogEN::rankStudents()
{
	sort(studenti.begin(), studenti.end(), [](Student2& a, Student2& b) {
		if (a.GetProgramDeInvatare() == "EN" && b.GetProgramDeInvatare() == "EN")
			return a.GetMedia() > b.GetMedia();
		if (b.GetProgramDeInvatare() == "EN")
			return true;
		return false;
		});
}

void CatalogEN::AfiseazaStudenti()
{
	std::cout << "Studenti la Engleza: " << std::endl;
	for (auto i : studenti)
		if (i.GetProgramDeInvatare() == "EN")
			std::cout << i.GetNume() << " : " << i.GetNumarMatricol() << " -> " << i.GetMedia() << std::endl;
}
