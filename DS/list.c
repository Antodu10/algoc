#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


// constructs a new (empty) list
List *list_create(void) {
    List *l = malloc(sizeof(List));
    l->first = l->last = NULL;
    return l;
}

// counts the items on a list
size_t list_count(const List *list) {
    size_t count = 0;

    ListNode *p=list->first;
    while(p!=NULL) {
        count++;
        p=p->next;
    }

    return count;
}

// inserts item_data at *end* of a list
void list_addlast(List *list, data_t item_data) {
    ListNode* nouvelleList =malloc(sizeof(ListNode)); //on créer l'espace mémoire
    //on initalise
    nouvelleList->data=item_data;
    nouvelleList->prev= list->last;
    nouvelleList->next=NULL;
    //j'ajoute ma nouvelle liste à l'ancienne
    list->last->next=nouvelleList;

}

// removes the item from *end* of the list and returns its value
data_t list_rmlast(List *list) {
    data_t itemRemoved = list->last->data; //sauvegarde la dernière valeur
     //on va à la dernière ListNode, on remonte à la List précédente, et on l'initialise
     // comme étant la dernière liste
    list->last->prev->next=NULL; 
    ListNode* memoire = list->last->prev;//mais en mémoire l'adresse de l'avant dernière list
    //on libère l'espace mémoir de la dernière liste
    free(list->last);
    list->last=memoire;
    return itemRemoved;
}



int main(void) {

    List *l = list_create();

    assert(list_count(l)==0);

    list_addlast(l,10);
    list_addlast(l,20);
    list_addlast(l,30);
    list_addlast(l,40);

    assert(list_count(l)==4);

    list_print(l);

    data_t t =  list_rmlast(l);

    assert(t==40);
    list_print(l);

    return 0;
}