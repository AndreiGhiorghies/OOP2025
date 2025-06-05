#pragma once
#include <string>
class Materie
{
protected:
	std::string tipMaterie;
	std::string nume;
	int nrCredite;
public:
	virtual std::string GetNume() = 0;
};

class Matematica : public Materie {
public:
	std::string GetNume() override;

	Matematica(std::string tip, std::string n, int credite) {
		tipMaterie = tip;
		nume = n;
		nrCredite = credite;
	}
};

class Romana : public Materie {
public:
	std::string GetNume() override;

	Romana(std::string tip, std::string n, int credite) {
		tipMaterie = tip;
		nume = n;
		nrCredite = credite;
	}
};

class Engleza : public Materie {
public:
	std::string GetNume() override;

	Engleza(std::string tip, std::string n, int credite) {
		tipMaterie = tip;
		nume = n;
		nrCredite = credite;
	}
};

class Informatica : public Materie {
public:
	std::string GetNume() override;

	Informatica(std::string tip, std::string n, int credite) {
		tipMaterie = tip;
		nume = n;
		nrCredite = credite;
	}
};

class Optional1 : public Materie {
public:
	std::string GetNume() override;

	Optional1(std::string tip, std::string n, int credite) {
		tipMaterie = tip;
		nume = n;
		nrCredite = credite;
	}
};

class Optional2 : public Materie {
public:
	std::string GetNume() override;

	Optional2(std::string tip, std::string n, int credite) {
		tipMaterie = tip;
		nume = n;
		nrCredite = credite;
	}
};

