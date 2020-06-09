#include "../lib/primetest.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(int argc, char** argv)
{
    unsigned register long long number, number_max;
    switch(argc)
    {
        case 0:
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
    while(number <= number_max)
    {
        if(isprime(number)) printf("%llu\r\n", number);
        number++;
    }
    exit(EXIT_SUCCESS);
}