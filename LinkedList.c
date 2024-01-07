
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
  int data;
  struct node *next;
};

struct node *head = NULL;

void addfirst(int data){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head=temp;
}

void addlast(int data){
    
    struct node *temp =(struct node*) malloc(sizeof(struct node));
    
    temp->data = data;
    temp->next = NULL;
    
    if(head == NULL){
        head = temp;
        return ;
    }
   
    struct node *traverse = head;
    
    while(traverse->next != NULL){

    traverse = traverse->next;
    
}    
traverse -> next = temp;

}


void deletefirst(){
    head=head->next;
}

void deletelast(){
    struct node *traverse = head;
    
    while(traverse ->next ->next !=NULL){
        traverse = traverse->next;
    }
    
    traverse ->next = NULL;
}

void delete(int key){
    struct node *temp = head,*prev;
    if(temp != NULL && temp->data == key){
        head = temp->next;
        return;
    }
    while(temp->data != key && temp != NULL){
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    
}

void printlist(){
    
    struct node *p = head;
    printf("\n[");
    
    while(p!=NULL){
        printf(" %d ",p->data);
        p=p->next;
    }
    printf("]");
}
//reverse using recursion
struct node *reverse(struct node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    struct node *newhead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return newhead;
}



int main() {
    
    printf("Linked List\n");
    
   addlast(4);
    addfirst(3);
    addfirst(2);
    addfirst(1);
   addlast(5);
    
   printlist();
    
    deletelast();
    deletefirst();
    delete(3);
    printlist();
    

    return 0;
}
