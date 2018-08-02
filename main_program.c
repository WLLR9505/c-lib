#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "lib/cores.h"
#include "lib/mylib.h"

int main () {

    short int posMenu;

    TYPEmenu menuCores = {
        "Menu de Cores",
        5,
        {
        1, "cor_azul",
        2, "cor_vermelho",
        3, "cor_verde",
        4, "cor_magenta",
        5, "cor_ciano"
        }
    };

    posMenu = Menu(&menuCores, menuCores.tamanho);

    // usando printcolor e menu
    printcolor("cor selecionada no menu\n ", menuCores.item[posMenu].descricao);

    return 0;
}
