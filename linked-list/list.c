#include <stdio.h>
#include <stdlib.h>

/*
*   Data Struct: Ordered List
*   @Author: Gabriel Oliveira
*
*/

typedef struct Node {
    int data;
    struct Node *next;
} node;

typedef struct List {
    node *start;
}list;

//createNode(&n, <int>);
void createNode(node **n, int data){
    *n = (node*) malloc(sizeof(node));
    if(*n != NULL){
        (*n)->next = NULL;
        (*n)->data = data;
    }
    
}

void createList(list **l){
    *l = (list*) malloc(sizeof(list));
    if(*l != NULL){
        (*l)->start = NULL;
    }
}
void addNode(node *st, node *n){
    int temp = n->data;
    node *previous = st;
    
    while(st != NULL){
        if(temp > st->data && st->next == NULL){
            //insert in end list
            st->next = n;
            return ;
        } else if(temp < st->data) {
            //middle insertion
            //printf("LOG: inserindo no meio\n");
            n->next = st;
            previous->next = n;
            return ;
        }
        previous = st;
        st = st->next;
    }
}

void add(list *l, int n){
    node *nd;
    if(l == NULL){
        return ;
    }
    createNode(&nd, n);
    if(nd == NULL){
        printf("ERROR: insufficient memory");
        return ;
    }
    if(l->start == NULL){
        l->start = nd;
    } else if(n < (l->start->data) ){
        nd->next = l->start;
        l->start = nd;
    } else {
        addNode(l->start, nd);
    }
}

void destroyList(node *act){
    node *temp = act->next;
    while(act != NULL){
        //printf("LOG: Destruindo o %d\n", act->data);
        free(act);
        act = temp;
        if(temp != NULL){
            temp = temp->next;
        }
    }
}

void destroy(list *l){
    if(l == NULL){
        return ;
    }
    destroyList(l->start);
}


void printList(list *l){
    node *n = l->start;
    printf("list: ");
    while(n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}
