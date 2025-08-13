#include <stdio.h>
#include <stdlib.h>

typedef struct Cel{
    int value;
    struct Cel *ptrNextCel;
}Cel;

typedef struct LDE{
    int elementsNumber;
    Cel *firstElement;
}LDE;

Cel *create_cel(int value){
    Cel *newCel = malloc(sizeof(Cel));
    newCel->value = value;
    newCel->ptrNextCel = NULL;
    return newCel;
}

LDE *create_list(){
    LDE *newList = malloc(sizeof(LDE));
    newList->elementsNumber = 0;
    newList->firstElement = NULL;
    return newList;
}

void insert(LDE *list, int value){
    Cel *newCel = create_cel(value);
    Cel *anterior = NULL;
    Cel *atual = list->firstElement;
    while(atual != NULL && atual->value < value){
        anterior = atual;
        atual = atual->ptrNextCel;
    }
    if(anterior == NULL){
        newCel->ptrNextCel = list->firstElement;
        list->firstElement = newCel;
    }else{
        anterior->ptrNextCel = newCel;
        newCel->ptrNextCel = atual;
    }
    list->elementsNumber++;
}

void removeCel(LDE *list, int value){
    Cel *atual = list->firstElement;
    Cel *anterior = NULL;

    while(atual != NULL){
        if(atual->value == value){
            anterior = atual->ptrNextCel;
            free(atual);
            break;
        }
        anterior = atual;
        atual = atual->ptrNextCel;
    }
}

void printList(LDE *list){
    Cel *atual = list->firstElement;
    while(atual != NULL){
        printf("%d ", atual->value);
        atual = atual->ptrNextCel;

    }
    printf("\n");
}

int main(){

    LDE *list = create_list();
    int i = 9;
    for(i = 9; i >= 0; i--){
        insert(list, i);
        printList(list);

    }
    removeCel(list, 8);
    printList(list);
    return 0;
}
