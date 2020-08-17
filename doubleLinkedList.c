#include <stdio.h>

typedef struct _node {
    int info;
    struct _node* next;
    struct _node* previous;
} Node;

typedef struct{
    Node* head;
}List;

void list_init(List *l){
    l->head = NULL;
}

void list_insert(List *l, int key){
    Node* a = (Node*)malloc(sizeof(Node));
    a->next = l->head;
    a->info = key;
    if(a->next == NULL)
        a->previous = NULL;
    else
    {
        a->previous = l->head->previous;
        a->next->previous = a;
    }
    l->head = a;
}

Node *list_search(List *l, int key){
    Node* aux;
    for(aux = l->head; aux!=NULL && aux->info != key; aux = aux->next){}
    return aux;
}

void list_erase(List *l, int key){
    Node* aux;
    aux = list_search(l,key);
    if(aux == NULL)
        return;
    if(l->head == aux)
    {
        l->head = aux->next;
        if(aux->next != NULL)
            aux->next->previous = aux->previous;
    }
    else
    {
        if(aux->next != NULL)
            aux->next->previous = aux->previous;
        aux->previous->next = aux->next;
    }
    free(aux);
}

void list_print(List *l){
    for(Node* aux = l->head; aux!=NULL; aux = aux->next)
        printf("%d ", aux->info);
    printf("\n");
}

void list_free(List *l){
    Node* aux;
    Node* next;
    for(aux = l->head; aux != NULL && aux->next != NULL; aux = next)
    {
        next = aux->next;
        free(aux);
    }
}

void merge_list(List *L1, List *L2)
{
    Node* aux;
    if(L1->head == NULL)
    {
        L1->head = L2;
        return;
    }
    if(L2->head == NULL)
        return;
    for(aux = L1->head; aux->next != NULL; aux = aux->next){}

    aux->next = L2->head;
    L2->head->previous = aux;
}


int main()
{
    List list;
    List list2;
    int n = 5;

    list_init(&list2);
    list_init(&list);

    list_insert(&list,5);
    list_insert(&list,6);

    list_insert(&list2,2);
    list_insert(&list2,9);

    printf("First list: \n");
    list_print(&list);
    printf("Second list: \n");
    list_print(&list2);

    printf("Has the list the number %d ? ", n);
    printf("%d" , list_search(&list,n) ? 1 : 0);
    printf("\nHas the list2 the number %d ? ", n);
    printf("%d\n" , list_search(&list2,n) ? 1 : 0);
    printf("List after removing number 5 : \n");
    list_erase(&list, n);
    list_print(&list);
    printf("List2 after removing number 2 : \n");
    list_erase(&list2, 2);
    list_print(&list2);

    merge_list(&list,&list2);
    printf("List after merging it : \n");
    list_print(&list);

    list_insert(&list,5);
    list_insert(&list,6);
    list_print(&list);
    list_insert(&list2,2);
    list_insert(&list2,9);
    list_print(&list2);
    list_free(&list);
}
