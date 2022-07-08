#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//qual o usuário informe o nome de um arquivo texto e uma palavra, e o programa
// informe o número de vezes que aquela palavra aparece dentro do arquivo.

    int main()
    {

        FILE *p;
        int r=0;
        char name[20], palavra[20];
        char conteudo[100];

        printf("Digite o nome do arquivo (.txt no fim):");
        scanf("%s", name);

        printf("Digite a palavra a ser procurada:");
        scanf("%s", palavra);

        p = fopen(name, "r");


        while (fgets(conteudo, 100, p) != NULL)
        {
            char *tmp = conteudo;
            while ((tmp = strstr(tmp, palavra)) != NULL)
            {
                r++;
                tmp++;
            }
        }

        p = fclose(p);


        printf("A palavra:%s aparece %d vezes em %s\n", palavra, r, name);





        return 0;
    }











