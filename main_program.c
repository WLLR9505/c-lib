#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "lib/cores.h"
#include "lib/mylib.h"

int main () {

    TYPEmenu menuClasses = {
        "Menu Exemplo",
        5,
        {
        1, "item 1",
        2, "item 2",
        3, "item 3",
        4, "item 4",
        5, "item 5"
        }
    };

    Menu(&menuClasses, menuClasses.tamanho);

    // usando printc
    printcolor("Alerta\n ", "cor_amarelo");

    // usando printf
    printf(cor_vermelho "Cuidado\n" cor_reset);


    return 0;
}
