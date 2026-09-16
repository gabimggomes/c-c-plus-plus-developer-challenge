#ifndef MATH_OPS_H
#define MATH_OPS_H
#define MAX 10

typedef enum{
    SUCCESS_OPERATION,
    ERROR_OPERATION,
} MathOp;

MathOp calc_square(float a, float *result);

MathOp calc_determinant(float m[MAX][MAX], int n, float *result);

MathOp calc_sum(float a, float b, float *result);

MathOp calc_sub(float a, float b, float *result);

MathOp calc_mult(float a, float b, float *result);

MathOp calc_div(float a, float b, float *result);

#endif