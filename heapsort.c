#include <stdio.h>
#include <string.h>
#define TAM 10

void trocar(int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void heapfy(int v[], int i, int n) {
    int e = i*2+1;
    int d = i*2+2;
    int maior = i;
    if(e < n && v[maior] < v[e]) {
        maior = e;
    }
    if(d < n && v[maior] < v[d]) {
        maior = d;
    }
    if(maior != i) {
        trocar(v,maior,i);
        heapfy(v,maior,n);
    }
}

void build_max_heap(int v[], int n) {
    for(int i = (n/2) - 1; i >= 0; i--) {
        heapfy(v,i,n);
    }
}

void heapsort(int v[], int n) {
    build_max_heap(v,n);
    imprime(v,n);
    for(int i = n-1; i > 0; i--) {
        trocar(v,0,i);
        heapfy(v,0,i);
    }
}

void imprime(int v[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int extract_max(int v[], int n) {
    if(n < 1)
        return;
    int max = v[0];
    trocar(v,0,n-1);
    n--;
    heapfy(v,0,n);
    return max;
}

int pai(int i) {
    return (i-1)/2;
}

void insert(int v[], int n, int chave) {
    int i = n;
    v[i] = chave;
    while(v[i] > pai(i) && i > 0) {
        trocar(v,i,pai(i));
        i = pai(i);
    }
}

int main() {
    int v[TAM] = { 0, 4, 6, 2, 45, 7, 2, 1, 56, 42 };
    build_max_heap(v,TAM);
    imprime(v,TAM);
    printf("%d\n", extract_max(v,TAM));
    imprime(v,TAM-1);
    insert(v,TAM-1,93);
    imprime(v,TAM);
    printf("\n%d %d", (5)/2, (4)/2);
    /*
    char senha[8];
    for(int i = 108; i < 125; i++) {
        senha[0] = (char)i;
        for(int j = 97; j < 122; j++) {
            senha[1] = (char)j;
            for(int k = 97; k < 122; k++) {
                senha[2] = (char)k;
                for(int l = 97; l < 122; l++) {
                    senha[3] = (char)l;
                    for(int m = 97; m < 122; m++) {
                        senha[4] = (char)m;
                        for(int n = 97; n < 122; n++) {
                            senha[5] = (char)n;
                            for(int o = 97; o < 122; o++) {
                                senha[6] = (char)o;
                                for(int p = 97; p < 122; p++) {
                                    senha[7] = (char)p;
                                    if(strcmp(senha,"lucasppp") == 0)
                                        printf("%s\n", senha);
                                }
                            }
                        }
                    }
                }
            }
        }
    }*/
}
