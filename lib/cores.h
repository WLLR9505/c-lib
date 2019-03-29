//Cor Fundo
#define fnd_vermelho "\x1b[01;41m"
#define fnd_verde "\x1b[01;42m"
#define fnd_amarelo "\x1b[01;43m"
#define fnd_azul "\x1b[01;44m"
#define fnd_magenta "\x1b[01;45m"
#define fnd_ciano "\x1b[01;46m"
#define fnd_preto "\x1b[22;40m"
#define fnd_branco "\x1b[01;47m"
#define fnd_vermelhoEscuro "\x1b[22;41m"
#define fnd_verdeEscuro "\x1b[22;42m"
#define fnd_amareloEscuro "\x1b[22;43m"
#define fnd_azulEscuro "\x1b[22;44m"
#define fnd_magentaEscuro "\x1b[22;45m"
#define fnd_cianoEscuro "\x1b[22;46m"

//Cor Texto
#define cor_cinza "\x1b[01;40m"
#define cor_vermelho "\x1b[01;31m"
#define cor_verde "\x1b[01;32m"
#define cor_amarelo "\x1b[01;33m"
#define cor_azul "\x1b[01;34m"
#define cor_magenta "\x1b[01;35m"
#define cor_ciano "\x1b[01;36m"
#define cor_preto "\x1b[22;30m"
#define cor_branco "\x1b[01;37m"
#define cor_vermelhoEscuro "\x1b[22;31m"
#define cor_verdeEscuro "\x1b[22;32m"
#define cor_amareloEscuro "\x1b[22;33m"
#define cor_azulEscuro "\x1b[22;34m"
#define cor_magentaEscuro "\x1b[22;35m"
#define cor_cianoEscuro "\x1b[22;36m"
#define cor_reset "\x1b[0m"

typedef struct STRcores
{
    char nomeCor[32];
    char color[16];
} TYPEcores;
