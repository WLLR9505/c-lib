# lib

Biblioteca pessoal com o objetivo de acumular funções úteis.

##### Composição
> ***main_program.c***  
> *arquivo principal de onde são chamadas as funções.*

> ***back_process.c***  
> *arquivo responsável por conter a estrutura das funções.*

> ***lib/cores.h***  
> *Header contendo '#defines' das cores e declaração da 'struct' STRcores, usada na função printc.*

> ***lib/mylib***  
> *Header contendo declarações/definições não categorizadas ou pequenas para um Header próprio.*

##### Compilação:

- gcc -c back_process.c

- gcc -c main_program.c

- gcc -o main.exe main_program.o back_process.o
