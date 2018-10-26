#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <unistd.h>
#include "lib/cores.h"
#include "lib/mylib.h"

void opRacionais() {
    short int posMenu2;
    TYPERacional a, b, r;
    TYPEmenu menuOpRac = {
        "Menu Operações Racionais",
        5,
        {
            1, "Soma",
            2, "Subtração",
            3, "Divisão",
            4, "Multiplicação",
            5, "voltar"
        }
    };

    while(1) {
        posMenu2 = Menu(&menuOpRac, menuOpRac.tamanho);
        if (posMenu2 == 4) {
            break;
        }
        printf("Informe A: ");
        scanf("%d/%d", &a.num, &a.den);
        printf("Informe B: ");
        scanf("%d/%d", &b.num, &b.den);

        if (posMenu2 == 0) {
            r = SomaRacional(a, b);
            printf("%d/%d\n", r.num, r.den);
            r = SimplRacional(r);
        } else if (posMenu2 == 1) {
            r = SubtraiRacional(a, b);
            r = SimplRacional(r);
        } else if (posMenu2 == 2) {
            r = DivRacional(a, b);
            r = SimplRacional(r);
        } else if (posMenu2 == 3) {
            r = MultRacional(a, b);
            r = SimplRacional(r);
        }
        printf("%d/%d\n", r.num, r.den);
        sleep(2);
    }
    return;
}

void menuTemperatura() {
    short int posMenu2;
    TYPEmenu menuConversaoTemp = {
        "Menu Conversão de Temperatura",
        3,
        {
            1, "Fahrenheit para Celsius",
            2, "Celsius para Fahrenheit",
            3, "Voltar"
        }
    };

    while(1) {
        float temperatura;
        system("clear");
        posMenu2 = Menu(&menuConversaoTemp, menuConversaoTemp.tamanho);
        if (posMenu2 == 2) {
            break;
        }

        if (posMenu2 == 0) {
            printf("Digite uma Temperatura em Fahrenheit\n");
            scanf("%f", &temperatura);
            printf("%.2f F    -    %.5f C\n", temperatura, Fahrenheit2Celsius(temperatura));
        } else if (posMenu2 == 1) {
            printf("Digite uma Temperatura em Celsius\n");
            scanf("%f", &temperatura);
            printf("%.2f C    -    %.5f F\n", temperatura, Celsius2Fahrenheit(temperatura));
        }
        sleep(3);
    }
    return;
}

int main () {

    short int posMenu;
    int dec;
    char res[64];

    TYPEmenu menuPrincipal = {
        "Menu Principal",
        4,
        {
            1, "cores",
            2, "operações com racionais",
            3, "conversão Temperatura",
            4, "sair"
        }
    };

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
    while (1) {
        posMenu = Menu(&menuPrincipal, menuPrincipal.tamanho);
        if (posMenu == 0) {
            posMenu = Menu(&menuCores, menuCores.tamanho);
            printcolor("cor selecionada no menu\n ", menuCores.item[posMenu].descricao);
            sleep(2);
        } else if (posMenu == 1) {
            opRacionais();
            system("clear");
        } else if (posMenu == 2) {
            menuTemperatura();
            system("clear");
        } else if (posMenu == 3) {
            system("clear");
            break;
        }
    }
    return 0;
}
