// Test file for test_number_utils.c

#include <stdio.h>
#include "../include/number_utils.h"

int main(void) {
    printf("== Number Utils Tests ==\n");
    printf("Is 7 prime? %d\n", is_prime(7));
    printf("GCD of 12 and 18: %d\n", gcd(12, 18));
    printf("All number_utils tests done!\n");
    return 0;
}
