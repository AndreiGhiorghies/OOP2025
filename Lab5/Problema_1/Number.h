#pragma once
class Number
{
	char* number;
	int base, length;

	long long ToDecimal() const;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int value);
	~Number();

	Number(const Number& from);
	Number(Number&& from);

	Number& operator=(const Number& from);
	Number& operator=(Number&& from);
	Number& operator=(int num);
	Number& operator=(const char* s);

	friend Number operator+(const Number& a, const Number& b);
	friend Number operator-(const Number& a, const Number& b);

	void operator+=(const Number &a);
	void operator-=(const Number &a);

	char operator[](int index) const;

	bool operator<(const Number& a) const;
	bool operator<=(const Number& a) const;
	bool operator>(const Number& a) const;
	bool operator>=(const Number& a) const;
	bool operator==(const Number& a) const;
	bool operator!=(const Number& a) const;

	void operator--();
	void operator--(int);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};

