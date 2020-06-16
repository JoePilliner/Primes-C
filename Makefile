bin/primes : lib/factor_category.h src/primes.c Makefile
	mkdir -p bin
	cc -o bin/primes src/primes.c -lm