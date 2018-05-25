#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "lib/cores.h"
#include "lib/mylib.h"

TYPEcores lista_cores[14] = {
    {"cor_vermelho", "\x1b[01;31m"},
    {"cor_verde", "\x1b[01;32m"},
    {"cor_amarelo", "\x1b[01;33m"},
    {"cor_azul", "\x1b[01;34m"},
    {"cor_magenta", "\x1b[01;35m"},
    {"cor_ciano", "\x1b[01;36m"},
    {"cor_preto", "\x1b[22;30m"},
    {"cor_branco", "\x1b[01;37m"},
    {"cor_vermelhoEscuro", "\x1b[22;31m"},
    {"cor_verdeEscuro", "\x1b[22;32m"},
    {"cor_amareloEscuro", "\x1b[22;33m"},
    {"cor_azulEscuro", "\x1b[22;34m"},
    {"cor_magentaEscuro", "\x1b[22;35m"},
    {"cor_cianoEscuro", "\x1b[22;36m"}
};

void printcolor(char texto[512], char cor[16])
{
    for (int i = 0; i < 14; i++)
    {
        if (strcmp(cor, lista_cores[i].nomeCor) == 0)
            printf("%s%s\x1b[0m", lista_cores[i].color, texto);
    }
}
