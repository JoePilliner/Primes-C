typedef enum {COMPOSITE, PRIME, OTHER, UNSURE} PRIMALITY;

extern inline void primality(const register unsigned long long number, register PRIMALITY * restrict primality, const register unsigned long long factor_max)
{
    switch(number)
    {
        //Hard-coded special cases
        case 0ULL:
        case 1ULL:
            *primality = OTHER;
            return;
        case 2ULL:
        case 3ULL:
            *primality = PRIME;
            return;
        default: switch(number % 6ULL)
        {
            //Numbers divisible by 2 or 3 cannot be prime
            case 0ULL:
            case 2ULL:
            case 3ULL:
            case 4ULL:
                *primality = COMPOSITE;
                return;
            default: for(register unsigned long long factor = 5ULL; factor <= factor_max;)
            {
                //Numbers not divisible by 2 or 3 and divisible by a factor greater than or equal to 5 that is not divisible by 2 or 3 and is less than or equal to the maximum factor to be checked cannot be prime
                switch(number % factor)
                {
                    case 0ULL:
                        *primality = COMPOSITE;
                        return;
                    default: switch(factor % 6ULL)
                    {
                        case 1ULL:
                            factor += 4;
                            continue;
                        case 5ULL:
                            factor += 2;
                            continue;
                        default:
                            *primality = UNSURE;
                            return;
                    }
                }
            }
            *primality = PRIME; return;
        }
    }
}