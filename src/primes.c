#include "../lib/primetest.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(int argc, char** argv)
{
    register unsigned long long number, number_max;
    switch(argc)
    {
        case 0:
            number = 0ULL;
            number_max = ULLONG_MAX;
            break;
        case 1:
            number = 0ULL;
            number_max = ULLONG_MAX;
            break;
        case 2:
            number = 0ULL;
            number_max = strtoull(argv [1], NULL, 10);
            break;
        case 3:
            number = strtoull(argv [1], NULL, 10);
            number_max = strtoull(argv [2], NULL, 10);
            break;
        default:
            exit(EXIT_FAILURE);
    }
    PRIMALITY number_primality;
    while(number <= number_max)
    {
        primality(number, &number_primality, (const unsigned long long) sqrtl((long double) number));
        if(number_primality == PRIME) printf("%llu\r\n", number);
        number++;
    }
    exit(EXIT_SUCCESS);
}