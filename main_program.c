#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "lib/cores.h"
#include "lib/mylib.h"

int main () {

    //usando printc
    printcolor("Alerta\n", "cor_amarelo");

    //usando printf
    printf(cor_vermelho "Cuidado\n" cor_reset);

    return 0;
}
