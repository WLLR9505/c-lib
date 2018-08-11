#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <unistd.h>
#include <termios.h>
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

//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------

static struct termios old, new;

void initTermios(int echo)
{
    tcgetattr(0, &old);
    new = old;
    new.c_lflag &= ICANON;
    new.c_lflag &= echo ? ECHO : ~ECHO;
    tcsetattr(0, TCSANOW, &new);
}

void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

char getch(void) //sem eco
{
    return getch_(0);
}

char getche(void) //com eco
{
    return getch_(1);
}

//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------

TYPEreturn IO(char mode[8])
{
    //++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++
    void LimpaIO()
    {
        r.i = 0;
        strcpy(r.s, "");
        r.f = 0;
        r.d = 0;
    }
    //++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++
    LimpaIO();
    if (strcmp(mode, "m") == 0) //Menu
    {
        r.c = getche();
        return r;
    }
    char input[64] = "";
    scanf("%s", input);

    if (strcmp(mode, "i") == 0)
    {
        r.i = atoi(input);
        return r;
    }
    else if (strcmp(mode, "s") == 0)
    {
        strcpy(r.s, input);
        return r;
    }
    else if (strcmp(mode, "c") == 0)
    {
        r.c = input[0];
        return r;
    }
}

//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------

int Menu(TYPEmenu *menu, int nItens)
{
    int posSeletor = 0; //Posição inicial do seletor
    //++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++
    void AtualizaMenu()
    {
        printf("%50s\n\n", (*menu).titulo);
        for (int i2 = 0; i2 < nItens; i2++)
        {
            if ((*menu).item[i2].nItem >= 0 && strcmp((*menu).item[i2].descricao, "") != 0)
            {
                if (posSeletor == i2)
                    printf(cor_ciano " %s\n" cor_reset, (*menu).item[i2].descricao);
                else
                    printf("%s\n", (*menu).item[i2].descricao);
            }
            else
                continue;
        }
        printf("\n");
    }
    //++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++     ++
    void ExibeMenuPadrao()
    {
        do
        {
            if (r.c == 'w')
                posSeletor--;
            else if (r.c == 's')
                posSeletor++;

            if (posSeletor == nItens)    ///Seletor no fim e avança
                posSeletor = 0;          //Igual ao primeiro item do menu
            else if (posSeletor < 0)     //seletor no começo e volta
                posSeletor = nItens - 1; //Igual ao ultimo item do menu

            system("clear");
            AtualizaMenu();

            IO("m");
        } while (r.c == 'w' || r.c == 's' || r.c == '\n');
    }
    do
    {
        ExibeMenuPadrao();
    } while (validarControles(r) == false);
    return posSeletor;
}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------

bool validarControles(TYPEreturn r)
{
    if (r.c == 'e')
    {
        return true;
    }
    else
    {
        printf(cor_amarelo "Comando invalido\n" cor_reset);
        sleep(1);
        return false;
    }
}

//---------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TYPERacional SomaRacional(TYPERacional nr1, TYPERacional nr2)
{
    TYPERacional r;
	r.num = nr1.num * nr2.den + nr2.num * nr1.den;
	r.den = nr1.den * nr2.den;
    return r;
}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
TYPERacional SubtraiRacional(TYPERacional nr1, TYPERacional nr2)
{
    TYPERacional r;

	r.num = nr1.num * nr2.den - nr2.num * nr1.den;
	r.den = nr1.den * nr2.den;
    return r;
}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
TYPERacional MultRacional(TYPERacional nr1, TYPERacional nr2)
{
    TYPERacional r;

	r.num = nr1.num * nr2.num;
	r.den = nr1.den * nr2.den;
    return r;
}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
TYPERacional DivRacional(TYPERacional nr1, TYPERacional nr2)
{
    TYPERacional r;

	r.num = nr1.num * nr2.den;
	r.den = nr2.num * nr1.den;
    return r;
}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
int MDC(int m, int n)
{
    if (m < 0) {
        m = -m;
    }
	if (n < 0) {
        n = -n;
    }

	if (m % n == 0) {
		return n;
	} else {
		return MDC(n, m % n);
    }
}
TYPERacional SimplRacional(TYPERacional nr1)
{
    TYPERacional r;

    r.num = nr1.num / MDC(nr1.num, nr1.den);
    r.den = nr1.den / MDC(nr1.num, nr1.den);
    return r;
}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
