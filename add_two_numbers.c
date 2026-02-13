#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * add_two_numbers:
 * Returns 0 on success and stores the sum in *result.
 * Returns -1 if overflow/underflow would occur.
 */
int add_two_numbers(long long a, long long b, long long *result) {
    if (result == NULL) {
        return -1;
    }

    if ((b > 0 && a > LLONG_MAX - b) ||
        (b < 0 && a < LLONG_MIN - b)) {
        return -1;
    }

    *result = a + b;
    return 0;
}

int main(void) {
    long long a = 0;
    long long b = 0;
    long long sum = 0;

    printf("Enter two integers: ");
    if (scanf("%lld %lld", &a, &b) != 2) {
        fprintf(stderr, "Invalid input. Please enter two integers.\n");
        return EXIT_FAILURE;
    }

    if (add_two_numbers(a, b, &sum) != 0) {
        fprintf(stderr, "Error: overflow/underflow detected.\n");
        return EXIT_FAILURE;
    }

    printf("Sum: %lld\n", sum);
    return EXIT_SUCCESS;
}
