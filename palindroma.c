#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int tamanho, tamanho_sem_espacos = 0, palindroma = 1;
    char* vetor;
    scanf("%d", &tamanho);
    getchar();
    vetor = (char*)malloc(tamanho*sizeof(char));
    fgets(vetor,tamanho+2,stdin);
    vetor[strlen(vetor)-1] = '\0';
    for(int i = 0; i < tamanho; i++)
    {
        if(vetor[i] == ' ')
        {
            for(int j = i; j < tamanho-tamanho_sem_espacos; j++)
                vetor[j] = vetor[j+1];
            tamanho--;
        }
    }
    //printf("Frase sem espacos: \n%s\n", vetor);
    for(int i = 0; i < tamanho-1; i++)
    {
        if(vetor[i] != vetor[(tamanho-1)-i]) {
            printf("Nao eh palindroma!");
            return 0;
        }
    }
    printf("Eh palindroma!");
    return 0;
}
