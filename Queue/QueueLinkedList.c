
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{	
    int data;
    struct node *next;
};

struct node *top=NULL;

void insert(int data){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(top==NULL){
        top = temp;
        return;
    }
    struct node *traverse = top;
    
    while(traverse->next !=NULL){
        traverse=traverse->next;
    }
    traverse->next = temp;
}

void Remove(){
    top=top->next;
}

int peek(){
    return top->data;
}


int main() {
    // Write C code here
    printf("Queue\n");
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    
    while(top!=NULL){
        printf(" %d\n",peek());
        Remove();
    }

    return 0;
}
