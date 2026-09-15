# include "math_op.h"

//Potência de 2:
MathOp calc_square(float a, float *result){

    *result = a * a;

    return SUCESS_OPERATION; // Indica se a operação foi bem sucedida, sem erros
}

// Determinante da matriz NxN:
MathOp calc_determinant(float m[MAX][MAX], int n, float *result){
    if (n<= 0 || n>MAX) {
        return ERROR_OPERATION;
    }

    float det = 1.0f;
    int i, j, k;

    for (i = 0; i < n; i++) {

        int max_row = i;
        for (j = i + 1; j < n; j++) {
            if (fabs(m[j][i]) > fabs(m[max_row][i])) {
                max_row = j;
            }
        }

        if (fabs(m[max_row][i]) < 1e-6) {
            *result = 0.0f; // Determinante é nulo se houver uma linha de zeros
            return SUCESS_OPERATION;
        }

        // 3. Se o maior valor nao estiver na linha atual, faz a troca
        if (max_row != i) {
            for (k = 0; k < n; k++) {
                float temp = m[i][k];
                m[i][k] = m[max_row][k];
                m[max_row][k] = temp;
            }
            det = -det; // Trocar linhas inverte o sinal do determinante
        }

        // 4. Transformacao para matriz triangular superior (Eliminacao)
        for (j = i + 1; j < n; j++) {
            float factor = m[j][i] / m[i][i];
            for (k = i; k < n; k++) {
                m[j][k] -= factor * m[i][k];
            }
        }
    }

    // 5. Multiplica a diagonal principal
    for (i = 0; i < n; i++) {
        det *= m[i][i];
    }

    *result = det;
    return SUCESS_OPERATION;
    
}

//Soma:
MathOp calc_sum(float a, float b, float *result){

    *result = a + b;

    return SUCESS_OPERATION;
}

//Subtração:
MathOp calc_sub(float a, float b, float *result){

    *result = a - b;

    return SUCESS_OPERATION;
}

//Multiplicação:
MathOp calc_mult(float a, float b, float *result){
    
    *result = a * b;

    return SUCESS_OPERATION;
}

//Divisão:
MathOp calc_div(float a, float b, float *result){

    if(b == 0){
        return ERROR_OPERATION; // Retorna erro caso o divisor seja 0
    }

    *result = a / b;

    return SUCESS_OPERATION;
}   