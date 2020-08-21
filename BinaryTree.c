#include "stdio.h"

typedef struct arvore {
   int info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;


Arvore* cria_arvore_vazia (void) {
   return NULL;
}

void arvore_libera (Arvore* a) {
   if (a != NULL) {
      arvore_libera (a->esq);
      arvore_libera (a->dir);
      free(a);
   }
}

Arvore* inserir (Arvore *a, int v) {
    if(a==NULL)
    {
        a = (Arvore*)malloc(sizeof(Arvore));
        a->dir = NULL;
        a->esq = NULL;
        a->info = v;
    }
    else if( a->info > v)
        a->esq = inserir(a->esq, v);
    else
        a->dir = inserir(a->dir, v);
    return a;
}

Arvore* remover (Arvore *a, int v) {
    if(a!=NULL)
    {
        if(a->info > v)
            a->esq = remover(a->esq,v);
        else if(a->info < v)
            a->dir = remover(a->dir,v);
        else
        {
            if(a->dir == NULL && a->esq == NULL)
            {
                free(a);
                a = NULL;
            }
            else if(a->dir == NULL)
            {
                Arvore *tmp = a;
                a = a->esq;
                free(tmp);
            }
            else if(a->esq == NULL)
            {
                Arvore *tmp = a;
                a = a->dir;
                free(tmp);
            }
            else
            {
                Arvore *tmp = a->dir;
                while(tmp->esq != NULL)
                    tmp = a->esq;
                a->info = tmp->info;
                tmp->info = v;
                a->dir=remover(a->dir,v);
            }
        }
    }
    return a;
}



int buscar (Arvore *a, int v) { ////Função não utilizando recursão
    Arvore* aux = a;
    while(aux!=NULL)
    {
        if(aux->info > v)
            aux = aux->esq;
        else if(aux->info < v)
            aux = aux->dir;
        if(aux!=NULL && aux->info == v)
            return 1;
    }
    return 0;
}


int buscar2 (Arvore *a, int v) { //Função igual dos slides, utilizando recursão (melhor)
    Arvore* aux = a;
    if(a != NULL)
    {
        if(a->info > v)
            return buscar2(a->esq,v);
        else if (a->info < v)
            return buscar2(a->dir,v);
        else
            return 1;
    }
    else
        return 0;

}


void pre_order (Arvore* a) {
   if (a != NULL) {
      printf("%d ", a->info);
      pre_order (a->esq);
      pre_order (a->dir);
   }
}

void in_order (Arvore* a) {
   if (a != NULL) {
      in_order (a->esq);
      printf("%d ", a->info);
      in_order (a->dir);
   }
}

int min(Arvore *a)
{
    if(a != NULL)
    {
        Arvore* aux = a->esq;
        while(aux->esq!=NULL)
            aux = aux->esq;
        return aux->info;
    }
}

int max(Arvore *a)
{
    if(a != NULL)
    {
        Arvore* aux = a->dir;
        while(aux->dir!=NULL)
            aux = aux->dir;
        return aux->info;
    }
}

void imprime_decrescente (Arvore *a)
{
    if (a != NULL) {
      imprime_decrescente (a->dir);
      printf("%d ", a->info);
      imprime_decrescente (a->esq);
   }
}

int maior_ramo (Arvore *a)
{
    int esq = 0;
    int dir = 0;
    if (a != NULL) {
      dir+=maior_ramo(a->dir) + a->info;
      esq+=maior_ramo(a->esq) + a->info;
      if(esq>dir)
        return esq;
      return dir;
   }
}

int ancestral (Arvore *a, int e1, int e2)
{
    if (a != NULL) {
        ancestral (a->dir,e1,e2);
        if(a->info > e1 && a->info < e2)
            return a->info;
        ancestral (a->esq,e1,e2);
   }
}


int main () {

   int i;

   Arvore *a = cria_arvore_vazia ();

   a = inserir (a, 50);
   a = inserir (a, 30);
   a = inserir (a, 90);
   a = inserir (a, 20);
   a = inserir (a, 40);
   a = inserir (a, 95);
   a = inserir (a, 10);
   a = inserir (a, 35);
   a = inserir (a, 45);

   /*a = remover (a, 20);
    ...
   */

   printf("\n");
   pre_order (a);
   printf("\n");
   in_order(a);
   printf("\n");
   printf("%d", buscar(a,45));
   printf("\n");
   a=remover(a,45);
   in_order(a);
   printf("\n");
   printf("Minimo: %d", min(a));
   printf("\n");
   printf("Maximo: %d", max(a));
   printf("\n");
   imprime_decrescente(a);
   printf("\n");
   printf("Maior ramo: %d", maior_ramo(a));
   printf("\n");
   printf("Ancestral: %d", ancestral(a,10,35));

   return 0;
}
