#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    struct Node* next;
    char info[256];
}Node;

typedef struct Hash{
    int m;
    int quantidade_chaves;
    Node** vetor;
}Hash;

Hash* cria_hash(Hash* h, int m) {
    h = malloc(sizeof(Hash));
    h->vetor = (Node**)malloc(sizeof(Node*));
    h->m = m;
    for(int i = 0; i < m; i++) {
        h->vetor[i] = NULL;
    }
    h->quantidade_chaves = 0;
    return h;
}

int hash_function(char* string, int division) {
    int hash = string[0];
    if(string[1] != '\0') {
        for(int i = 1;string[i] != '\0'; i++) {
            hash = (hash * 256 + string[i]) % division;
        }
    }
    else
        hash = hash % division;
    return hash;
}

void include_string(Hash* h, char* string) {
    int hash = hash_function(string,h->m);
    Node* aux = malloc(sizeof(Node));
    aux->next = h->vetor[hash];
    h->vetor[hash] = aux;
    strcpy(aux->info,string);
    h->quantidade_chaves++;
}

void imprime_hash(Hash* h) {
    for(int i = 0; i < h->m; i++) {
        if(h->vetor[i] != NULL) {
            printf("Hash %d\n", i);
            for(Node* aux = h->vetor[i]; aux != NULL; aux = aux->next) {
            printf("%s ", aux->info);
            }
            printf("\n");
        }
    }
}

void exclui_hash(Hash* h) {
    for(int i = 0; i < h->m; i++) {
        if(h->vetor[i] != NULL) {
            printf("Hash %d\n", i);
            for(Node* aux = h->vetor[i]; aux != NULL; aux = h->vetor[i]) {
                free(aux);
                h->vetor[i] = h->vetor[i]->next;
            }
        }
    }
}

int main() {
    Hash* h = cria_hash(h,7);
    include_string(h,"Lucas");
    include_string(h,"Lucas Andrezinho");
    include_string(h,"Pedro");
    include_string(h,"Jose");
    include_string(h,"Heliane");
    include_string(h,"Rodrigo");
    include_string(h,"Gustavo");
    include_string(h,"Fernando");
    include_string(h,"Gabriel");
    include_string(h,"Ana");
    include_string(h,"Mario");
    imprime_hash(h);

}
