#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arque;

    char nome[50];
    char c[10];
    char k[10];
    int a;

    //===============primeiro arquivo====================

    printf("digite o nome do arquivo\n");
    gets(nome);

    arque=fopen(nome,"w");

    if(arque==NULL)
    {
        printf("erro");
        exit(1);
    }

    a=fputs("aloooooo",arque);
    printf("entrou 1\n");
    fclose(arque);


    arque=fopen(nome,"r");
    if(arque==NULL)
    {
        printf("erro");
        exit(1);
    }

    a=fread (c, sizeof(char), 10, arque);
    printf("entrou 1\n");
    fclose(arque);
    printf("entrou 2\n");

    //========================segundo arquivo==========================

    printf("digite o nome do arquivo\n");
    gets(nome);

    arque=fopen(nome,"w");
    printf("entrou 1\n");
    if(arque==NULL)
    {
        printf("erro");
        exit(1);
    }

    a=fputs("batatata",arque);
    printf("entrou 1\n");
    fclose(arque);
    printf("entrou 2\n");
    arque=fopen(nome,"r");

    a=fread (k, sizeof(char), 10, arque);

    printf("entrou 2\n");
    fclose(arque);
    printf("entrou 2\n");

    //================terceiro arquivo======================

    arque=fopen("terceiro.txt","w");
    printf("entrou 1\n");
    if(arque==NULL)
    {
        printf("erro");
        exit(1);
    }
    printf("entrou 1\n");
    fprintf(arque,"%s %s",c,k);
    printf("entrou 2\n");
    fclose(arque);


    return 0;
}
