#include <math.h>

int isprime(const register unsigned long long number)
{
    switch(number)
    {
        case 0:
        case 1:
            return 0;
        case 2:
            return 1;
        default:
            break;
    }
    register unsigned long long factor;
    const register unsigned long long factor_max = (unsigned long long) sqrtl((long double) number);
    for(factor = 2ULL; (number % factor) && (factor < factor_max); factor++);
    return number % factor;
}