# include "math_op.h"

//Potência de 2:
MathOp calc_square(float a, float *result){

    *result = a * a;

    // decltype(a)
    // if(b == 0){
    //    return ERROR_OPERATION; // Retorna erro caso o divisor seja 0
    //}

    return SUCESS_OPERATION; // Indica se a operação foi bem sucedida, sem erros
}

// Determinante da matriz 2x2:
// MathOp calc_determinant(float m[2][2], float *result){
//     // // Formato da matriz m 2x2:
//     // // [0][0]  [0][1]
//     // // [1][0]  [1][1]
//     // float principal_diag = m[0][0] * m[1][1];
//     // float secondary_diag = m[1][0] * m[0][1];

//     // *result = principal_diag - secondary_diag; 

//     return SUCESS_OPERATION; 
// }

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
    

    //     if ()
    //     if (m[i][i] == 0.0f) {
    //         int c = 0;
    //         for (j = i + 1; j < n; j++) {
    //             if (m[j][i] != 0.0f) {
    //                 // Troca as linhas "i" e "j"
    //                 for (k = 0; k < n; k++) {
    //                     float temp = m[i][k];
    //                     m[i][k] = m[j][k];
    //                     m[j][k] = temp;
    //                 }
    //                 det = -det; // Trocar linhas altera o sinal do determinante
    //                 c = 1;
    //                 break;
    //             }
    //         }

    //         if (c == 0) {
    //             *result = 0.0f; // Determinante é nulo se houver uma linha de zeros
    //             return SUCESS_OPERATION;
    //         }

    //         // Transformação para matriz triangular superior
    //         for (j = i + 1; j < n; j++) {
    //             float factor = m[j][i] / m[i][i];
    //             for (k = i; k < n; k++) {
    //                 m[j][k] -= factor * m[i][k];
    //             }
    //         }
    //     }
    // }

    // // Calcula o determinante com a multiplicação dos termos da diagonal principal
    // for (i = 0; i < n; i++) {
    //     det *= m[i][i];
    // }

    // *result = det;
    // return SUCESS_OPERATION;
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