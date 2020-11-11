#include <stdio.h>

void escreve_espacos(int i)
{
    for(int j = 0; j < i; j++)
        printf(" ");
}

void escreve_hashtag(int espaco)
{
    printf("#");
    if(espaco > 0)
    {
        escreve_espacos(espaco); //espaços entre hashtags
        printf("#");
    }
}

int main()
{
    int n, aux = 0, espaco = 0;
    scanf("%d", &n);
    aux = n;
    for(int i = 0; i < n; i++)
    {
        escreve_espacos(aux-1);
        escreve_hashtag(espaco);
        espaco += espaco == 0 ? 1 : 2;
        aux--;
        printf("\n");
    }
    aux = 1;
    espaco += -4;
    for(int i = 0; i < n-1; i++)
    {
        escreve_espacos(aux);
        escreve_hashtag(espaco);
        espaco += -2;
        aux++;
        printf("\n");
    }
}
