typedef enum boolean {
    true = 1,
    false = 0
} bool;

typedef struct STRitemMenu {
    int nItem;
    char descricao[64];
} TYPEitemMenu;

typedef struct STRmenu {
    char titulo[64];
    short int tamanho;
    TYPEitemMenu item[64];
} TYPEmenu;

typedef struct STRreturn
{
    int i;
    char c;
    char s[64];
    float f;
    double d;
} TYPEreturn;
TYPEreturn r;

void printcolor(char[512], char[16]);

int Menu(TYPEmenu *, int);
