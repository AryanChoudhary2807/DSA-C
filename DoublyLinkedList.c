
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
    struct node *pre;
};

struct node *head =NULL;
struct node *last =NULL;

bool isempty(){
    return head == NULL;
}


void printlist(){
    if(isempty()){
        printf("List is Empty");
        return;
    }
    struct node *temp=head;
    
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
//print reverse
void reverse(){
    if(isempty()){
        printf("List is Empty");
        return;
    }
    struct node *temp=last;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->pre;
    }
    printf("NULL\n");
}

void addfirst(int data){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data=data;
    
    if(isempty()){
        last = temp;
    }
    else{
        head->pre = temp;
        temp->next =head;
    }
    head=temp;
}

void addlast(int data){
    struct node *temp =(struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    
    if(isempty()){
        last=temp;
    }
    else{
        last->next=temp;
        temp->pre = last;
    }
    last=temp;
}

void delete(int key){
    
    struct node *temp = head;
    
    if(key == head->data){
        head=head->next;
        head->pre =NULL;
        return;
    }
     if(key == last->data){
        last=last->pre;
        last->next = NULL;
        return;
    }
    
        while(temp->data!=key){
           temp = temp->next;
           
        }
    
     temp->pre->next = temp->next;
     temp->next->pre = temp->pre;
}

int main() {
    
    addfirst(3);
    addfirst(2);
    addfirst(1);
    addlast(4);
    printlist();
    reverse();
    delete(1);
    printlist();
    

    return 0;
}
