#include <stdio.h>
#include "hmi.h"
#include "math_op.h"

void hmi_run(void) {
    int choice = 0;

    while (1) {
        printf("----------------------------------------\n");
        printf("     CALCULADORA - Gabriela Gomes \n");
        printf("----------------------------------------\n\n");
        printf(" 1 - Calcular a potencia de 2 de um numero \n");
        printf(" 2 - Calcular o determinante da matriz NxN \n");
        printf(" 3 - Calcular soma de dois numeros \n");
        printf(" 4 - Calcular subtracao de dois numeros \n");
        printf(" 5 - Calcular multiplicacao de dois numeros \n");
        printf(" 6 - Calcular divisao de dois numeros \n");
        printf(" 7 - Sair \n\n");
        printf(" Digite o numero da operacao desejada: \n");

        scanf("%d", &choice);

        switch (choice) {

            //Potência:
            case 1: {
                float a, res;
                int input_valido = 0;

                // Loop para verificar se o usuário inseriu um valor válido
                while (input_valido == 0) {
                    printf("Digite o numero que deseja calcular a potencia de 2:\n");
                    
                    if (scanf("%f", &a) != 1) {
                        printf("Erro de digitacao. Por favor, insira apenas numeros e utilize ponto para decimais (Ex: 2.50). Tente novamente. \n\n");
                        while (getchar() != '\n');
                    } else {
                        char next_char = getchar();

                        // Verifica se o próximo caractere é um "Enter" ou um espaço
                        if (next_char == '\n' || next_char == ' ') {
                            if (next_char != '\n') {
                                while (getchar() != '\n'){
                                }
                            }
                                input_valido = 1;
                        } 
                            else {
                                printf("Erro de digitacao. Voce utilizou virgula ou letras junto ao numero. Por favor, tente novamente \n\n");
                                while (getchar() != '\n');
                            }
                    }
                }

                if (calc_square(a, &res) == SUCCESS_OPERATION) {
                    printf("Resultado da potencia: %.2f \n", res);
                } 
                break;
            }
            
            //Determinante:
            case 2: {
                int n; 
                float res;
                int input_valido = 0;

                while (input_valido == 0) {
                    printf("Para o tamanho da matriz quadrada (ex: 3 para 3x3). Observacao: tamanho maximo %d \n", MAX);                 
                    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
                        printf("Erro. Insira um numero inteiro positivo entre 1 e %d.\n\n", MAX);
                        while (getchar() != '\n');
                    } else {
                        char next_char = getchar();
                        if (next_char == '\n' || next_char == ' ') {
                            if (next_char != '\n') {
                                while (getchar() != '\n'){
                                }
                            }
                                input_valido = 1;
                        } else {
                            printf("Erro de digitacao. Voce utilizou virgula ou letras junto ao numero. Por favor, tente novamente \n\n");
                            while (getchar() != '\n');
                        }
                    }
                }

                float m[MAX][MAX];
                printf("Digite os elementos da matriz %dx%d, separados por enter:\n", n, n);

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int input_valido = 0;
                        while (input_valido == 0) {
                            printf("Valor para a posicao [%d][%d]: ", i, j );
                            if (scanf("%f", &m[i][j]) != 1) {
                                printf("Erro de digitacao. Por favor, insira apenas numeros e utilize ponto para decimais (Ex: 2.50). Tente novamente. \n\n");
                                while (getchar() != '\n');
                            } else {
                                char next_char = getchar();
                                if (next_char == '\n' || next_char == ' ') {
                                    if (next_char != '\n') {
                                        while (getchar() != '\n'){
                                        }
                                    }
                                        input_valido = 1;
                                } else {
                                    printf("Erro de digitacao. Voce utilizou virgula ou letras junto ao numero. Por favor, tente novamente \n\n");
                                    while (getchar() != '\n');
                                }
                            }
                        }
                    }
                }

                if (calc_determinant(m, n, &res) == SUCCESS_OPERATION) {
                    printf("Resultado do Determinante: %.2f \n", res);
                } 
                break;
            }

            //Soma:
            case 3: {
                float a, b, res;
                int input_valido = 0;

                while (input_valido == 0) {
                    printf("Digite os dois numeros para a soma (ex: 1 5): \n");
                    
                    if (scanf("%f %f", &a, &b) != 2) {
                        printf("Erro de digitacao. Por favor, insira apenas numeros e utilize ponto para decimais (Ex: 2.50). Tente novamente. \n\n");
                        while (getchar() != '\n');
                    } else {
                        char next_char = getchar();
                        if (next_char == '\n' || next_char == ' ') {
                            if (next_char != '\n') {
                                while (getchar() != '\n'){
                                }
                            }
                                input_valido = 1;
                        } else {
                            printf("Erro de digitacao. Voce utilizou virgula ou letras junto ao numero. Por favor, tente novamente \n\n");
                            while (getchar() != '\n');
                        }
                    }
                }

                if (calc_sum(a, b, &res) == SUCCESS_OPERATION) {
                    printf("Resultado da soma: %.2f \n", res);
                }
                break;
            }

            //Subtração:
            case 4: {
                float a, b, res;
                int input_valido = 0;

                while (input_valido == 0) {
                    printf("Digite o minuendo e o subtraendo (ex: 10 3): \nEquacao = minuendo - subtraendo \n");
                    
                    if (scanf("%f %f", &a, &b) != 2) {
                        printf("Erro de digitacao. Por favor, insira apenas numeros e utilize ponto para decimais (Ex: 2.50). Tente novamente. \n\n");
                        while (getchar() != '\n');
                    } else {
                        char next_char = getchar();
                        if (next_char == '\n' || next_char == ' ') {
                            if (next_char != '\n') {
                                while (getchar() != '\n'){
                                }
                            }
                                input_valido = 1;
                        } else {
                            printf("Erro de digitacao. Voce utilizou virgula ou letras junto ao numero. Por favor, tente novamente \n\n");
                            while (getchar() != '\n');
                        }
                    }
                }

                if (calc_sub(a, b, &res) == SUCCESS_OPERATION) {
                    printf("Resultado da subtracao: %.2f \n", res);
                } 
                break;
            }

            //Multiplicação:
            case 5: {
                float a, b, res;
                int input_valido = 0;

                while (input_valido == 0) {
                    printf("Digite os dois numeros para a multiplicacao (ex: 5 3): \n");
                    
                    if (scanf("%f %f", &a, &b) != 2) {
                        printf("Erro de digitacao. Por favor, insira apenas numeros e utilize ponto para decimais (Ex: 2.50). Tente novamente. \n");
                        while (getchar() != '\n');
                    } else {
                        char next_char = getchar();
                        if (next_char == '\n' || next_char == ' ') {
                            if (next_char != '\n') {
                                while (getchar() != '\n'){
                                }
                            }
                                input_valido = 1;
                        } else {
                            printf("Erro de digitacao. Voce utilizou virgula ou letras junto ao numero. Por favor, tente novamente \n\n");
                            while (getchar() != '\n');
                        }
                    }
                }

                if (calc_mult(a, b, &res) == SUCCESS_OPERATION) {
                    printf("Resultado da multiplicacao: %.2f \n", res);
                } 
                break;
            }

            //Divisão:
            case 6: {
                float a, b, res;
                int input_valido = 0;

                while (input_valido == 0) {
                    printf("Digite o dividendo e o divisor (ex: 10 2): \n");
                    
                    if (scanf("%f %f", &a, &b) != 2) {
                        printf("Erro de digitacao. Por favor, insira apenas numeros e utilize ponto para decimais (Ex: 2.50). Tente novamente. \n\n");
                        while (getchar() != '\n');
                    } else {
                        char next_char = getchar();
                        if (next_char == '\n' || next_char == ' ') {
                            if (next_char != '\n') {
                                while (getchar() != '\n'){
                                }
                            }
                                input_valido = 1;
                        } else {
                            printf("Erro de digitacao. Voce utilizou virgula ou letras junto ao numero. Por favor, tente novamente \n\n");
                            while (getchar() != '\n');
                        }
                    }
                }

                if (calc_div(a, b, &res) == SUCCESS_OPERATION) {
                    printf("Resultado da divisao: %.2f \n", res);
                } else {
                    printf("Erro: Divisao por zero.\n");
                }
                break;
            }

            // Sair:
            case 7: {
                printf("Encerrando calculadora...\n\n");
                return; 
            }

            // Caso o usuário digite um número que não está na lista de opções:
            default: {
                printf("Operacao invalida. Tente Novamente.\n\n");
                break;
            }
        }
    }
}
