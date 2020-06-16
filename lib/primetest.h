typedef enum {COMPOSITE, PRIME, OTHER, UNSURE} PRIMALITY;

extern inline void primality(const register unsigned long long number, register PRIMALITY *primality, const register unsigned long long factor_max)
{
    switch(number)
    {
        //Hard-coded cases
        case 0ULL: *primality = OTHER; return;
        case 1ULL: *primality = OTHER; return;
        case 2ULL: *primality = PRIME; return;
        case 3ULL: *primality = PRIME; return;
        default: switch(number % 6ULL)
        {
            //Numbers divisible by 2 or 3 cannot be prime
            case 0ULL: *primality = COMPOSITE; return;
            case 2ULL: *primality = COMPOSITE; return;
            case 3ULL: *primality = COMPOSITE; return;
            case 4ULL: *primality = COMPOSITE; return;
            default: for(register unsigned long long factor = 5ULL; factor < factor_max;)
            {
                switch(number % factor)
                {
                    case 0ULL: *primality = COMPOSITE; return;
                    default: switch(factor % 6ULL)
                    {
                        case 1ULL:
                            factor += 4;
                            continue;
                        case 5ULL:
                            factor += 2;
                            continue;
                        default:
                            *primality = UNSURE; return;
                    }
                }
            }
            *primality = PRIME; return;
        }
    }
    *primality = UNSURE; return;
}