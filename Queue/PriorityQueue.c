
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct priority{
    int pri,info;
    struct priority *next;
};
struct priority *head=NULL;


bool isempty(){
    return head==NULL;
}


void insert(){
    int n,p;
    struct priority *new1 = (struct priority*) malloc(sizeof(struct priority));
    printf("\nEnter the priority :");
    scanf("%d",&p);
    printf("\nEnter the data :");
    scanf("%d",&n);
    new1->info=n;
    new1->pri=p;
    new1->next=NULL;
    
    if(head==NULL || new1->pri < head->pri){
        new1->next=head;
        head=new1;
    }
    else{
       struct priority *temp=head;
        while(temp->next!=NULL && temp->next->pri<=p)
        {
        temp=temp->next;    
        }
        new1->next=temp->next;
        temp->next = new1;
    }
}

void display(){
    if(isempty()){
        printf("Queue is empty!\n");
        return;
    }
    struct priority *temp = head;
    while(temp!=NULL){
        printf("%d. %d \n",temp->pri,temp->info);
        temp=temp->next;
    }
    
}

int main(){
    printf(" Priority Queue\n");
int ch;
    do{
            printf("Menu\n");
    printf("1.insert \n 2.display \n");
    
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1: insert();
        break;
        case 2: display();
        break;
        default : printf("Invalid Choice!");
    }
    
    }
    while(ch<3);
    
    return;
}



