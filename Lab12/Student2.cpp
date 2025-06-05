#include "Student2.h"

Student2::Student2(std::string n, std::string nr, std::string program) : nume(n), nrMatricol(nr), programDeInvatare(program)
{
}

void Student2::AdaugaNota(Materie& materie, const double& nota)
{
	note[materie.GetNume()].push_back(nota);
}

std::string Student2::GetNume()
{
	return nume;
}

std::string Student2::GetNumarMatricol()
{
	return nrMatricol;
}

std::string Student2::GetProgramDeInvatare()
{
	return programDeInvatare;
}

double Student2::GetMedia()
{
	double s = 0;
	int nr = 0;
	for (auto i : note) {
		for (auto j : i.second)
			s += j;
		nr += (int)i.second.size();
	}
	
	if (nr != 0)
		return (double)s / nr;
	else
		return 0;
}
