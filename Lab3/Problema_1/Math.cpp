#include "Math.h"
#include <cstdarg>

int Math::Add(int a, int b)
{
    return a + b;
}

int Math::Add(int a, int b, int c)
{
    return a + b + c;
}

int Math::Add(double a, double b)
{
    return a + b;
}

int Math::Add(double a, double b, double c)
{
    return a + b + c;
}

int Math::Mul(int a, int b)
{
    return a * b;
}

int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}

int Math::Mul(double a, double b)
{
    return a * b;
}

int Math::Mul(double a, double b, double c)
{
    return a * b * c;
}

/*int Math::Add(int count, ...)
{
    int* p = &count;
    int sum = 0;

    while (count--) {
        p += 2;
        sum += *p;
    }

    return sum;
}*/

int Math::Add(int count, ...) {
    int sum = 0;
    va_list args;
    va_start(args, count);

    while (count--)
        sum += va_arg(args, int);

    va_end(args);

    return sum;
}

char* Math::Add(const char* a, const char* b)
{
    if (a == nullptr || b == nullptr)
        return nullptr;

    int la = 0, lb = 0;

    while (a[la] || b[lb]) {
        if (a[la])
            la++;
        if (b[lb])
            lb++;
    }

    char* res = new char[la + lb + 1];
    int mx = la > lb ? la : lb;

    for (int i = 0; i < mx; i++) {
        if (i < la)
            res[i] = a[i];
        if (i < lb)
            res[la + i] = b[i];
    }
    
    res[la + lb] = '\0';

    return res;
}
