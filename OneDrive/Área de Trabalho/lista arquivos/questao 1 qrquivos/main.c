#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *a;
    char nome[100];
    char c, letra = '\n';
    int vezes;
    int r;
    int numero;

    printf("digite o nome do arquivo temine ele com .txt se nao nao ira funcionar ex:notas.txt ");
    gets(nome);

    a=fopen(nome,"a");



    if(a==NULL)
    {
        printf("erro");
        exit(1);
    }

    r = fputs("ola pessoas\naaaaaaaaaaaaaaaaaa\n", a);

    fclose(a);

    a=fopen(nome,"r");

    while(fread (&c, sizeof(char), 1, a)) {
            if(c == letra) {
                vezes++;
            }
        }

    printf("\nLinhas: %i\n",vezes);

    fclose(a);

    return 0;
}
