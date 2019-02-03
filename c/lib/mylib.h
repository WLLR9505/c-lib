typedef struct {
    int num;
    int den;
} TYPERacional;

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

typedef enum sn {
    sim,
    nao
} TYENsn;

typedef struct STRcontroles {
    char cima;
    char baixo;
    char esquerda;
    char direita;
    char confirmar;
    char cancelar;
    char salvar;
    char sair;
    char ajuda;
} TYPEcontroles;

TYPERacional SomaRacional(TYPERacional, TYPERacional);

TYPERacional SubtraiRacional(TYPERacional, TYPERacional);

TYPERacional MultRacional(TYPERacional, TYPERacional);

TYPERacional DivRacional(TYPERacional, TYPERacional);

TYPERacional SimplRacional(TYPERacional);

float Fahrenheit2Celsius(float);

float Celsius2Fahrenheit(float);

char getch();

char getche();

int Dec2Bin (int);

void printcolor(char[512], char[16]);

bool validarControles(TYPEreturn);

int Menu(TYPEmenu *, int);

float DistAB(float, float, float, float);
