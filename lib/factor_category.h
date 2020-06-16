typedef enum {ONE_FACTOR, TWO_FACTORS, GREATER_THAN_TWO_FACTORS, INFINITE_FACTORS, UNSURE} FACTOR_CATEGORY;

extern inline void factor_category(const register unsigned long long number, register FACTOR_CATEGORY * restrict factor_category, const register unsigned long long factor_max)
{
    switch(number)
    {
        //Hard-coded special cases
        case 0ULL:
            *factor_category = INFINITE_FACTORS;
            return;
        case 1ULL:
            *factor_category = ONE_FACTOR;
            return;
        case 2ULL:
        case 3ULL:
        case 5ULL:
            *factor_category = TWO_FACTORS;
            return;
        default: switch(number % 6ULL)
        {
            //Numbers divisible by 2 or 3 cannot be prime
            case 0ULL:
            case 2ULL:
            case 3ULL:
            case 4ULL:
                *factor_category = GREATER_THAN_TWO_FACTORS;
                return;
            default: switch(number % 30ULL)
            {
                //Numbers divisible by 5 cannot be prime
                case 5ULL:
                case 25ULL:
                    *factor_category = GREATER_THAN_TWO_FACTORS;
                    return;
                default: for(register unsigned long long factor = 7ULL; factor <= factor_max;)
                {
                    //Numbers not divisible by 2 or 3 and divisible by a factor greater than or equal to 7 that is not divisible by 2 or 3 and is less than or equal to the maximum factor to be checked cannot be prime
                    switch(number % factor)
                    {
                        case 0ULL:
                            *factor_category = GREATER_THAN_TWO_FACTORS;
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
                                *factor_category = UNSURE;
                                return;
                        }
                    }
                }
                *factor_category = TWO_FACTORS; return;
            }
        }
    }
}