#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    char nome[5];
    int pontos;

} tp_placar;


void ranking();
void jogar();
void limpa();

int main()
{
    int opc;

    do
    {
        printf("A COBRA VAI FUMAR\n");
        printf("1-jogar\n"
               "2-ranking\n"
               "3-creditos\n"
               "0-sair\n");

        scanf("%d",&opc);
        switch(opc)
        {
        case 1:
            limpa();
            jogar();

            break;
        case 2:
            limpa();
            ranking();

            break;
        case 3:

            break;
        }

    }
    while(opc != 0);

    return 0;
}



void jogar()
{
    FILE *arq;

    tp_placar lista[3];

    int t;

    arq=fopen("jogadores.txt","r");

    if(arq == NULL)
    {
        printf("erro de arquivo");
        exit(1);
    }

    fscanf(arq,"%d",&t);

    for(int i=0; i<t; i++)
    {

        fscanf(arq,"%s %d",&lista[i].nome,&lista[i].pontos);
        printf("%d %s : %d\n",i+1,lista[i].nome,lista[i].pontos);

    }

    fclose(arq);


    int opc;
    char nome[5];
    int mesmo=-1;

    printf("");

    scanf("%d",&opc);


    switch(opc)
    {
    case 1:
        opc--;
        break;
    case 2:
        opc--;
        break;
    case 3:
        opc--;
        break;
    case 4:

        printf("digite seu nome");
        scanf("%s",&nome);

        for(int i=0; i<t; i++)
        {
            if(strcmp(nome,lista[i].nome)==0)
            {
                mesmo=i;
                break;
            }
        }

        if(mesmo != -1)
        {
            opc=mesmo;
            printf("digite sua pontuacao");
            scanf("%d",&lista[mesmo].pontos);


        }
        else if(t==3)//se t for igual a 3 (ultima possicao do rank) ele pega essa posicao e armazena.

        {
            opc=2;
            strcpy(lista[2].nome,nome);
            printf("digite sua pontuacao");
            scanf("%d",&lista[2].pontos);

        }
        else
        {
            strcpy(lista[t].nome,nome);
            printf("digite seus pontos");
            scanf("%d",&lista[t].pontos);
            opc=t;

            t++;

        }

        tp_placar aux;

        int i,y;


        for (i = 0; i < t; i++)
        {

            for (y = i + 1; y < t; y++)
            {
                if (lista[i].pontos < lista[y].pontos)
                {
                    aux = lista[i];
                    lista[i] = lista[y];
                    lista[y] = aux;
                }

            }

        }


        arq=fopen("jogadores.txt","w");
        fprintf(arq,"%d\n",t);
        for(int i=0; i<t; i++)
        {

            fprintf(arq,"%s %d\n",lista[i].nome,lista[i].pontos);

        }

        fclose(arq);
        break;

    default:
        printf("opcao invalida\n");
        break;

    }

    printf("volte sempre\njogador:%s \n\n em construcao",lista[opc].nome);

    system("pause");
    system("cls");

}


void ranking()
{
    FILE *arq;
    int t;
    tp_placar lista[3];

    arq=fopen("jogadores.txt","r");

    if(arq == NULL)
    {
        printf("erro de arquivo");
        exit(1);
    }

    fscanf(arq,"%d",&t);

    for(int i=0; i<t; i++)
    {

        fscanf(arq,"%s %d",&lista[i].nome,&lista[i].pontos);
        printf("%d %s : %d\n",i+1,lista[i].nome,lista[i].pontos);

    }

    fclose(arq);

    system("pause");
    system("cls");
}

void limpa(){
    system("cls");
}
