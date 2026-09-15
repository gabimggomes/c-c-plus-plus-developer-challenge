# HMI Calculator - Documentação
 
Nome: Gabriela de Melo Gomes

---

## Projeto:

O projeto possui 3 componentes principais:

### main.c

Responsável por iniciar a calculadora

### hmi.c / hmi.h 

A interface homem-máquina, responsável por:
- Menu de opções de operações;
- Validação dos valores de entrada; 
- Mostrar o resultado das operações.

### math_op.c / math_op.h:

Responsável pelos calculos matématicos:
- Potência de 2;
- Determinante da matriz NxN (Nmáx =10);
- Adição;
- Subtração;
- Multiplicação;
- Divisão.

#### Determinante da matriz NxN:
  
O metódo para calculo de determinante utilizado foi Eliminação Gaussiana com pivoteamento parcial, que funciona da seguinte maneira:

- Passo 1: Para cada coluna "k" (de 1 até (n-1)), procure o elemento de maior valor absoluto na coluna "k" da linha "k" para baixo.
- Passo 2: Se o maior elemento estiver em outra linha, troque essa linha com a linha "k". Cada troca de linhas inverte o sinal do determinante, por isso o número total de trocas (s) deve ser contado
- Passo 3: Use o pivô para zerar todos os elementos abaixo dele na coluna "k'
- Passo 4: Repita o processo até a matriz virar uma matriz triangular superior "M"
- Passo 5: O determinante é o produto dos elementos da diagonal principal de "M", multiplicado por ((-1)^s), onde "s" é o número de trocas de linhas

---

## Erros:

Durante o desenvolvimento do projeto foram detectados algumas possibilidades de erros , como:
1. - Entradas inválidas (ex: uso de vírgula (,) e letras)
1. - Divisão por zero
1. - Selecionar uma opção de operação que não estava no menu

Atualmente, uma parte desses erros foram corrigidos. 
1. - A calculadora não realiza as operações matématicas quando encontra vírgula e/ou letra, ela envia uma mensagem dizendo que o número é inválido e o usuário deve enviar o número novamente. Porém, esse erro não é corrigido quando ocorre na etapa de seleção de opções do menu, ou seja, se o usuário inserir 4,5 a calculadora entra na operação "4" devido a leitura das variavéis. 
1. - Se o usuário inserir zero (0) quando digitar o divisor da operação, ele recebe uma mensagem avisando erro por divisão por zero
1. - Se o usuário inserir um número inteiro que não estava no menu, ele recebe um aviso para selecionar as opções disponíveis no menu. 

---

## Melhorias futuras:

Sugestões que tornariam o projeto mais completo:
1. - Corrigir erros que ocorrem quando o usuário digita uma opção incorreta na escolha de operações do menu;
1. - Implementar o registro de operações ("persistent operation log").


