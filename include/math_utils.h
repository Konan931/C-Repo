#ifndef MATH_UTILS_H
#define MATH_UTILS_H

// Define some useful constants
#define PI 3.14159265358979323846
#define E  2.71828182845904523536
#define GOLDEN_RATIO 1.618033988749895
#define SQRT2 1.41421356237309504880
#define SQRT3 1.73205080756887729353
#define SQRT5 2.23606797749978969640
#define PHI 1.618033988749895
#define TAU 6.28318530717958647692 // 2 * PI
#define DEG_TO_RAD(deg) ((deg) * (PI / 180.0))
#define RAD_TO_DEG(rad) ((rad) * (180.0 / PI))
#define CLAMP(value, min, max) ((value) < (min) ? (min) : ((value) > (max) ? (max) : (value)))
#define LERP(a, b, t) ((a) + (t) * ((b) - (a)))
#define SMOOTHSTEP(edge0, edge1, x) ((x) < (edge0) ? 0.0 : ((x) > (edge1) ? 1.0 : (((x) - (edge0)) * ((x) - (edge1)) * ((x) - (edge1)) * ((x) - (edge0)))))
#define SMOOTHSTEP_DERIVATIVE(edge0, edge1, x) ((x) < (edge0) ? 0.0 : ((x) > (edge1) ? 0.0 : (6.0 * ((x) - (edge0)) * ((x) - (edge1)))))
#define BILINEAR_INTERPOLATION(x1, y1, x2, y2, t1, t2, tx, ty) ((1 - tx) * (1 - ty) * (x1 * y1) + (tx) * (1 - ty) * (x2 * y1) + (1 - tx) * (ty) * (x1 * y2) + (tx) * (ty) * (x2 * y2))
#define TRILINEAR_INTERPOLATION(x1, y1, z1, x2, y2, z2, t1, t2, t3, tx, ty, tz) ((1 - tx) * (1 - ty) * (1 - tz) * (x1 * y1 * z1) + (tx) * (1 - ty) * (1 - tz) * (x2 * y1 * z1) + (1 - tx) * (ty) * (1 - tz) * (x1 * y2 * z1) + (tx) * (ty) * (1 - tz) * (x2 * y2 * z1) + (1 - tx) * (1 - ty) * (tz) * (x1 * y1 * z2) + (tx) * (1 - ty) * (tz) * (x2 * y1 * z2) + (1 - tx) * (ty) * (tz) * (x1 * y2 * z2) + (tx) * (ty) * (tz) * (x2 * y2 * z2))
#define CUBIC_INTERPOLATION(y0, y1, y2, y3, mu) ((y1) + 0.5 * (mu) * ((y2) - (y0) + (mu) * ((2.0 * (y0) - 5.0 * (y1) + 4.0 * (y2) - (y3)) + (mu) * ((3.0 * (y1) - 3.0 * (y2)) + (y3) - (y0)))))
#define CUBIC_INTERPOLATION_DERIVATIVE(y0, y1, y2, y3, mu) ((y2) - (y0) + (mu) * ((2.0 * (y0) - 5.0 * (y1) + 4.0 * (y2) - (y3)) + (mu) * ((3.0 * (y1) - 3.0 * (y2)) + (y3) - (y0))))
#define CUBIC_INTERPOLATION_SECOND_DERIVATIVE(y0, y1, y2, y3, mu) ((y2) - (y0) + (mu) * ((2.0 * (y0) - 5.0 * (y1) + 4.0 * (y2) - (y3)) + (mu) * ((3.0 * (y1) - 3.0 * (y2)) + (y3) - (y0))))
#define CUBIC_INTERPOLATION_THIRD_DERIVATIVE(y0, y1, y2, y3, mu) ((y2) - (y0) + (mu) * ((2.0 * (y0) - 5.0 * (y1) + 4.0 * (y2) - (y3)) + (mu) * ((3.0 * (y1) - 3.0 * (y2)) + (y3) - (y0))))
#define CUBIC_INTERPOLATION_FOURTH_DERIVATIVE(y0, y1, y2, y3, mu) ((y2) - (y0) + (mu) * ((2.0 * (y0) - 5.0 * (y1) + 4.0 * (y2) - (y3)) + (mu) * ((3.0 * (y1) - 3.0 * (y2)) + (y3) - (y0))))
#define CUBIC_INTERPOLATION_FIFTH_DERIVATIVE(y0, y1, y2, y3, mu) ((y2) - (y0) + (mu) * ((2.0 * (y0) - 5.0 * (y1) + 4.0 * (y2) - (y3)) + (mu) * ((3.0 * (y1) - 3.0 * (y2)) + (y3) - (y0))))
#define SIGN(value) ((value) < 0 ? -1 : (value) > 0 ? 1 : 0)
#define IS_INF(value) ((value) == INFINITY || (value) == -INFINITY)
#define IS_FINITE(value) ((value) != INFINITY && (value) != -INFINITY && (value) == (value))
#define IS_EVEN(value) ((value) % 2 == 0)
#define IS_ODD(value) ((value) % 2 != 0)
#define IS_POWER_OF_TWO(value) ((value) && !((value) & ((value) - 1)))
#define IS_POW2(value) ((value) && !((value) & ((value) - 1)))
#define IS_POW3(value) ((value) && ((value) % 3 == 0))
#define IS_POW4(value) ((value) && !((value) & ((value) - 1)) && (((value) & 0x55555555) == (value)))
#define IS_POW5(value) ((value) && ((value) % 5 == 0))

// Function prototypes
double square_root(double value);
double power(double base, double exponent);
double sine(double angle);
double cosine(double angle);
double tangent(double angle);
double logarithm(double value);
double exponential(double value);
double factorial(int value);
double absolute(double value);
double radians_to_degrees(double radians);
double degrees_to_radians(double degrees);
double min(double a, double b);
double max(double a, double b);
double clamp(double value, double min_value, double max_value);
double lerp(double a, double b, double t);
double smoothstep(double edge0, double edge1, double x);
double smoothstep_derivative(double edge0, double edge1, double x);
double sign(double value);
double is_inf(double value);
double is_finite(double value);
double is_even(double value);
double is_odd(double value);
double is_power_of_two(double value);
double is_pow2(double value);
double is_pow3(double value);
double is_pow4(double value);
double is_pow5(double value);

#endif
