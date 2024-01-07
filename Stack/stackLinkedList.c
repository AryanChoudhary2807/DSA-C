
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
};

struct node *top=NULL;


void push(int data){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data=data;
    temp->next = top;
    top = temp;
    
}

void pop(){
    top=top->next;
}

int  peek(){
    return top->data;
}

int main() {
    
    printf("Stack\n");
    
    push(3);
    push(2);
    push(1);
    
    while(top!=NULL){
        printf(" %d \n",peek());
        pop();
    }


    return 0;
}
