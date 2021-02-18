#include <stdio.h>
#include <stdlib.h>

typedef struct _lnode{
    int key;
    struct _lnode *next;
    struct _lnode *previous;
} lnode;

typedef struct {
    lnode *head;
} lista;

void inicializaLista(lista *l)
{
    l->head = NULL;
}
int insereNaLista(lista *l, int chave)
{
    lnode *u = malloc(sizeof(lista));
    if(!u)return 1;
    u->key = chave;
    u->next = l->head;
    if(l->head != NULL)
        l->head->previous = u;
    u->previous = NULL;
    l->head = u;
    return 0;
}

void imprimeLista(lista *l)
{
    lnode *u;
    if(l->head==NULL) {
        printf("Nenhum valor na lista!");
        return 0;
    }
    for(u=l->head;u;u=u->next) {
        printf("%s%d", u == l->head ? "" : " ", u->key);
    }
}

void liberaLista(lista *l)
{
    lnode *atual,*proximo;
    for(atual=l->head;atual;atual=proximo)
    {
        proximo=atual->next;
        free(atual);
    }
    l->head= NULL;
}

int apaga_node(lista *l, int chave)
{
    lnode *toRemove = NULL;
    for(toRemove = l->head; toRemove != NULL && toRemove->key != chave; toRemove = toRemove->next) {}
    if(toRemove==NULL) {
        printf("Valor nao encontrado!");
        return 0;
    }
    if(toRemove == l->head)
        l->head = toRemove->next;
    else
    {
        toRemove->previous->next = toRemove->next;
        if(toRemove->next != NULL)
            toRemove->next->previous = toRemove->previous;
    }
    free(toRemove);
    return 0;
}

void invertelista(lista *l)
{
    lnode* aux = l->head;
    lnode* prev = next = last = NULL;
    for(; aux->next != NULL; aux = aux->next) {}
    last = aux;
    for(; aux != NULL; aux = prev) {
        prev = aux->previous;
        aux->next = aux->previous;
        aux->previous = next;
        next = aux;
    }
    next->next = NULL;
    l->head = last;
}

int main()
{
    lista *l;
    int escolha=1,voltar=1,chave;
    inicializaLista(&l); //MANDAR SEMPRE O ENDEREÇO DO PONTEIRO PARA UMA FUNÇÃO!
    printf("Double linked list!!");
    printf("\n0-Leave the menu\n1-Insere um numero na lista\n2-Imprime lista\n3-Apaga valor\n");
    while(escolha!=0)
    {
        printf("\nDigite sua escolha:");
        scanf("%d", &escolha);
        switch (escolha)
        {
            case 1 :
                printf("Digite o numero que deseja inserir:");
                scanf("%d", &chave);
                insereNaLista(&l,chave);
                break;

            case 2 :
                imprimeLista(&l);
                break;

            case 3 :
                printf("Digite o valor que queira apagar:\n");
                scanf("%d", &chave);
                apaga_node(&l,chave);
                break;

            case 4 :
                invertelista(&l);
                break;

            default :
                printf("Voce digitou um numero que nao contem no menu!\n");

        }
    }
    liberaLista(&l);
}

