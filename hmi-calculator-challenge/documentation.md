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

Responsável pelos cálculos matemáticos:
- Potência de 2;
- Determinante da matriz NxN (Nmáx =10);
- Adição;
- Subtração;
- Multiplicação;
- Divisão.

#### Determinante da matriz NxN:
  
O método para cálculo de determinante utilizado foi Eliminação Gaussiana com pivoteamento parcial, que funciona da seguinte maneira:

- Passo 1: Para cada coluna "k" (de 1 até (n-1)), procure o elemento de maior valor absoluto na coluna "k" da linha "k" para baixo.
- Passo 2: Se o maior elemento estiver em outra linha, troque essa linha com a linha "k". Cada troca de linhas inverte o sinal do determinante, por isso o número total de trocas (s) deve ser contado
- Passo 3: Use o pivô para zerar todos os elementos abaixo dele na coluna "k"
- Passo 4: Repita o processo até a matriz virar uma matriz triangular superior "M"
- Passo 5: O determinante é o produto dos elementos da diagonal principal de "M", multiplicado por ((-1)^s), onde "s" é o número de trocas de linhas

---

## Tratamento de erros:

Durante o desenvolvimento do projeto foram identificadas algumas possibilidades de erro, como:
1. Entradas inválidas (ex: uso de vírgula (,) e letras)
1. Divisão por zero
1. Selecionar uma opção de operação que não estava no menu

Atualmente, o projeto trata as seguintes situações: 
1. A calculadora não realiza as operações matématicas quando encontra vírgula e/ou letra, ela envia uma mensagem dizendo que o número é inválido e o usuário deve enviar o número novamente. Porém, esse erro não é corrigido quando ocorre na etapa de seleção de opções do menu, ou seja, se o usuário inserir 4,5 a calculadora entra na operação "4" devido a leitura das variáveis. 
1. A divisão por zero é detectada antes da operação ser executada
1. Se o usuário inserir um número inteiro que não estava no menu, ele recebe um aviso para selecionar as opções disponíveis no menu. 

---

## Decisões de projeto:

- Foi definido um tamanho máximo de matriz por meio de "MAX", para evitar o uso de alocação de memória dinâmica;
- O cálculo do determinate é feito diretamente sobre matriz recebida, evitando a criação de uma segunda matriz na memória;
- A lógica matemática foi separada da interface para facilitar a manuntenção e reutilização das operações;
- A interface homem-máquina deste projeto é realizada por meio do terminal; 

---

## Compilação:

Durante os testes esses foram as sequência de comando utilizados, utilizando GCC:
1. c-c-plus-plus-developer-challenge> *cd hmi-calculator-challenge*
1. c-c-plus-plus-developer-challenge\hmi-calculator-challenge> *gcc -I./include src/main.c src hmi.c src/math_op.c -o calculator*
1. c-c-plus-plus-developer-challenge\hmi-calculator-challenge> *.\calculator.exe*

---

## Melhorias futuras:

Sugestões que tornariam o projeto mais completo:
- Corrigir erros que ocorrem quando o usuário digita uma opção incorreta na escolha de operações do menu
- Implementar o registro de operações ("persistent operation log")
- Avaliar outras formas de IHM, como desenvolver uma interface gráfica 


