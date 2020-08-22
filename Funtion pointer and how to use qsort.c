#include <stdio.h>
#include <stdlib.h>

int menor(int a, int b)
{
    return a <= b ? a : b;
}

int compare(void* a, void* b)
{
    return a <= b ? a : b;
}

int cmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*) b); //return numero positivo se a > b, negativo se b > a e zero se b==a
}

void quicksort()
{
    int v[50];
    for(int i = 0, j = 50; i < 50; i++, j--)
        v[i] = j;
    qsort(v,50,sizeof(int),cmp);
    for(int i = 0; i < 50; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main()
{
    char f = 'f';
    char c = 'c';
    int n = 4;
    int a;
    int ans = 0;
    int (*ptr) (int,int); //ponteiro para função
    ptr = menor;
    quicksort();
    n = ptr(50,60);
    printf("Menor 50 and 60 : %d\n", n);
    printf("Compare 4 and 1 : %d\n", compare(n,1));
    printf("Compare f and c : %c\n", compare(f,c));
    for(int i = 0; i<50; i++)
        ans += i<25; //return 0 ou 1
    printf("%d", ans);
    return 0;
}
