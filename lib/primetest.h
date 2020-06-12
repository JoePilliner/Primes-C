#include <math.h>

int isprime(const register unsigned long long number)
{
    switch(number)
    {
        case 0ULL:
        case 1ULL:
        case 4ULL:
            return 0;
        case 2ULL:
        case 3ULL:
        case 5ULL:
            return 1;
        default:
            break;
    }
    switch(number % 6ULL)
    {
        case 1ULL:
        case 5ULL:
            break;
        default:
            return 0;
    }
    register unsigned long long factor = 5ULL;
    const register unsigned long long factor_max = (unsigned long long) sqrtl((long double) number);
    while(factor < factor_max)
    {
        if(number % factor == 0) return 0;
        factor += 6 - ((2 * (factor % 6)) % 6);
    }
    return 1;
}