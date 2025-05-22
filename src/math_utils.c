#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/math_utils.h"

// Calculate the square root
double square_root(double value) {
    return sqrt(value);
}

// Calculate base raised to the power of exponent
double power(double base, double exponent) {
    return pow(base, exponent);
}

// Calculate the sine of an angle in radians
double sine(double angle) {
    return sin(angle);
}
// Calculate the cosine of an angle in radians
double cosine(double angle) {
    return cos(angle);
}
// Calculate the tangent of an angle in radians
double tangent(double angle) {
    return tan(angle);
}
// Calculate the natural logarithm
double logarithm(double value) {
    return log(value);
}
// Calculate the exponential function
double exponential(double value) {
    return exp(value);
}
// Calculate the factorial of a non-negative integer
double factorial(int value) {
    if (value < 0) {
        fprintf(stderr, "[ERROR] Factorial of negative number\n");
        return -1;
    }
    double result = 1.0;
    for (int i = 2; i <= value; i++) {
        result *= i;
    }
    return result;
}

// Convert radians to degrees
double radians_to_degrees(double radians) {
    return radians * (180.0 / PI);
}
// Convert degrees to radians
double degrees_to_radians(double degrees) {
    return degrees * (PI / 180.0);
}
// Find the minimum of two values
double min(double a, double b) {
    return (a < b) ? a : b;
}
// Find the maximum of two values
double max(double a, double b) {
    return (a > b) ? a : b;
}
// Clamp a value between min_value and max_value
double clamp(double value, double min_value, double max_value) {
    return fmax(min_value, fmin(value, max_value));
}

// Smoothstep interpolation
double smoothstep(double edge0, double edge1, double x) {
    if (x < edge0) return 0.0;
    if (x > edge1) return 1.0;
    double t = (x - edge0) / (edge1 - edge0);
    return t * t * t * (t * (t * 6 - 15) + 10);
}
// Derivative of smoothstep
double smoothstep_derivative(double edge0, double edge1, double x) {
    if (x < edge0 || x > edge1) return 0.0;
    double t = (x - edge0) / (edge1 - edge0);
    return 30 * t * t * (t * (t - 2) + 1) / (edge1 - edge0);
}

// Function to calculate the binomial coefficient
double binomial_coefficient(int n, int k) {
    if (k < 0 || k > n) {
        fprintf(stderr, "[ERROR] Invalid binomial coefficient parameters\n");
        return -1;
    }
    return factorial(n) / (factorial(k) * factorial(n - k));
}
// Function to calculate the permutation
double permutation(int n, int k) {
    if (k < 0 || k > n) {
        fprintf(stderr, "[ERROR] Invalid permutation parameters\n");
        return -1;
    }
    return factorial(n) / factorial(n - k);
}
// Function to calculate the combination
double combination(int n, int k) {
    if (k < 0 || k > n) {
        fprintf(stderr, "[ERROR] Invalid combination parameters\n");
        return -1;
    }
    return binomial_coefficient(n, k);
}
// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
// Function to calculate the least common multiple (LCM)
int lcm(int a, int b) {
    if (a == 0 || b == 0) {
        fprintf(stderr, "[ERROR] LCM of zero\n");
        return -1;
    }
    return abs(a * b) / gcd(a, b);
}
// Function to calculate the mean of an array
double mean(double *arr, int size) {
    if (size <= 0) {
        fprintf(stderr, "[ERROR] Invalid array size\n");
        return -1;
    }
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}
// Comparison function for qsort
int compare(const void *a, const void *b) {
    double diff = *(double *)a - *(double *)b;
    return (diff > 0) - (diff < 0);
}

// Function to calculate the median of an array
double median(double *arr, int size) {
    if (size <= 0) {
        fprintf(stderr, "[ERROR] Invalid array size\n");
        return -1;
    }
    double *sorted = malloc(size * sizeof(double));
    if (!sorted) {
        fprintf(stderr, "[ERROR] Memory allocation failed\n");
        return -1;
    }
    memcpy(sorted, arr, size * sizeof(double));
    qsort(sorted, size, sizeof(double), compare);
    double med;
    if (size % 2 == 0) {
        med = (sorted[size / 2 - 1] + sorted[size / 2]) / 2.0;
    } else {
        med = sorted[size / 2];
    }
    free(sorted);
    return med;
}
