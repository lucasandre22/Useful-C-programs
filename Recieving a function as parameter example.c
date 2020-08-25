#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} Node;

void add(int d, Node** l)
{
    Node *n = malloc(sizeof(Node));
    if (n != NULL) {
        n->data = d;
        n->next = (*l);
        (*l) = n;
    }
}

void ForEach(Node* node, void (*ptr)(Node*))
{
    for(Node* aux = node; aux != NULL; aux = aux->next)
        ptr(aux);
}

void print(Node* ptr) //print de um nó somente
{
    printf("%d ", ptr->data);
}

int main()
{
    Node *list = NULL;
    add(5, &list);
    add(6, &list);
    add(7, &list);
    add(8, &list);
    add(9, &list);
    add(10, &list);
    add(11, &list);
    add(12, &list);
    add(13, &list);
    ForEach(list,print); //passa função como parametro
    //ForEach(list,[](Node* ptr){ printf("%d", ptr->data); }); only in cpp
    return 0;
}
