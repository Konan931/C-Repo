#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include "../include/number_utils.h"

int is_prime(int n) {
	if (n <= 1) return 0;
	for (int i = 2; i*i <= n; i++)
		if (n % i == 0) return 0;
	return 1;
}

int sieve_of_eratosthenes(int n) {
	if (n < 2) return 0;
	int *sieve = malloc(n * sizeof(int));
	if (!sieve) return 0;
	for (int i = 0; i < n; i++) sieve[i] = 1;
	sieve[0] = sieve[1] = 0; // 0 and 1 are not prime
	for (int i = 2; i*i < n; i++) {
		if (sieve[i]) {
			for (int j = i*i; j < n; j += i) {
				sieve[j] = 0;
			}
		}
	}
	int count = 0;
	for (int i = 2; i < n; i++) {
		if (sieve[i]) count++;
	}
	free(sieve);
	return count;
}