#pragma once
#include <vector>
#include <map>
#include "Materie.h"

class Student2
{
private:
	std::string nume;
	std::string nrMatricol;
	std::string programDeInvatare;

	std::map<std::string, std::vector<double>> note;

public:
	Student2(std::string n, std::string nr, std::string program);
	void AdaugaNota(Materie& materie, const double& nota);
	std::string GetNume();
	std::string GetNumarMatricol();
	std::string GetProgramDeInvatare();
	double GetMedia();
};

