#include "Number.h"
#include <stdio.h>

long long Number::ToDecimal() const
{
    long long base10 = 0, p = 1;
    for (int i = length - 1; i >= 0; i--, p *= base)
        base10 = base10 + p * (number[i] - (number[i] <= '9' ? '0' : 'A' - 10));

    return base10;
}

Number::Number(const char* value, int b) : base(b)
{
    while (value[this->length])
        this->length++;

    this->number = new char[this->length + 1];

    for (int i = 0; i < this->length; i++)
        this->number[i] = value[i];
    number[length] = '\0';
}

Number::Number(int value)
{
    base = 10;
    int save = value;
    length = 0;

    while (value > 0) {
        length++;
        value /= 10;
    }
    value = save;

    number = new char[length + 1];
    for (int i = length - 1; i >= 0; i--, value /= 10)
        number[i] = value % 10 + '0';
    number[length] = '\0';
}

Number::~Number()
{
    delete[] number;
}

Number::Number(const Number& from) : base(from.base), length(from.length)
{
    this->number = new char[this->length + 1];

    for (int i = 0; i < this->length; i++)
        this->number[i] = from.number[i];
    number[length] = '\0';
}

Number::Number(Number&& from) : base(from.base), length(from.length), number(from.number)
{
    from.number = nullptr;
}

Number& Number::operator=(const Number& from)
{
    delete[] number;
    base = from.base;
    length = from.length;
    number = new char[length + 1];

    for (int i = 0; i < length; i++)
        number[i] = from.number[i];
    number[length] = '\0';

    return *this;
}

Number& Number::operator=(Number&& from)
{
    delete[] number;
    base = from.base;
    length = from.length;
    number = from.number;
    from.number = nullptr;

    return *this;
}

Number& Number::operator=(int num)
{
    int save = num;
    while (num > 0) {
        length++;
        num /= 10;
    }
    num = save;

    number = new char[length + 1];
    base = 10;
    number[length] = '\0';
    for (int i = length - 1; i >= 0; i--, num /= 10)
        number[i] = '0' + num % 10;

    return *this;
}

Number& Number::operator=(const char* s)
{
    base = 10;

    while (s[length])
        length++;

    number = new char[length + 1];
    for (int i = 0; i < length; i++)
        number[i] = s[i];
    number[length] = '\0';

    return *this;
}

void Number::operator+=(const Number& a)
{
    *this = operator+(*this, a);
}

void Number::operator-=(const Number& a)
{
    *this = operator-(*this, a);
}

char Number::operator[](int index) const
{
    if (index < 0 || index >= length)
        return NULL;

    return number[index];
}

bool Number::operator<(const Number& a) const
{
    return ToDecimal() < a.ToDecimal();
}

bool Number::operator<=(const Number& a) const
{
    return ToDecimal() <= a.ToDecimal();
}

bool Number::operator>(const Number& a) const
{
    return ToDecimal() > a.ToDecimal();
}

bool Number::operator>=(const Number& a) const
{
    return ToDecimal() >= a.ToDecimal();
}

bool Number::operator==(const Number& a) const
{
    return ToDecimal() == a.ToDecimal();
}

bool Number::operator!=(const Number& a) const
{
    return ToDecimal() != a.ToDecimal();
}

void Number::operator--()
{
    for (int i = 1; i < length; i++)
        number[i - 1] = number[i];

    number[length - 1] = '\0';
    length--;
}

void Number::operator--(int)
{
    number[length - 1] = '\0';
    length--;
}

void Number::SwitchBase(int newBase)
{
    long long base10 = ToDecimal();

    delete[] number;
    base = newBase;
    length = 0;

    long long save = base10;
    while (base10 > 0) {
        length++;
        base10 /= base;
    }
    base10 = save;

    number = new char[length + 1];
    number[length] = '\0';
    for (int i = length - 1; i >= 0; i--, base10 /= base)
        if (base10 % base <= 9)
            number[i] = base10 % base + '0';
        else
            number[i] = base10 % base + 'A' - 10;
}

void Number::Print()
{
    printf("Base: %d\nNumber: %s\n", base, number);
}

int Number::GetDigitsCount()
{
    return length;
}

int Number::GetBase()
{
    return base;
}

Number operator+(const Number& a, const Number& b)
{
    Number nr(a.ToDecimal() + b.ToDecimal());
    int mxBase = a.base;
    if (b.base > mxBase)
        mxBase = b.base;

    nr.SwitchBase(mxBase);

    return nr;
}

Number operator-(const Number& a, const Number& b)
{
    Number nr(a.ToDecimal() - b.ToDecimal());
    int mxBase = a.base;
    if (b.base > mxBase)
        mxBase = b.base;

    nr.SwitchBase(mxBase);

    return nr;
}
