
#include <stdio.h>

int a[10];
int rear=-1,front=-1;

void insert(){
    if(rear==9){
        printf("Queue is full \n");
        return;
    }
    if(front==-1){
        front++;
    }
    
    rear++;
    printf("Enter the data = ");
    scanf("%d",&a[rear]);
    
}

void pop(){
    if(front>rear || rear==-1){
        printf("Queue is Empty!\n");
        return;
    }
    
    front++;
}

void display(){
     if(front>rear || rear==-1){
        printf("Queue is Empty!\n");
        return;
    }
    
    for(int i=front ; i<=rear ; i++){
        printf("%d\n",a[i]);
    }
}


int main() {
    
    printf("Queue\n");
     int choice;
    do{
    printf("MENU\n");
    printf("1.Add \n2.Remove \n3.Display\n");
    printf("Enter your choice :");
    scanf("%d",&choice);
    
    switch(choice){
        case 1: insert();
        break;
        case 2: pop();
        break;
        case 3: display();
        break;
        default : printf("Invalid Choice!");
    }
  
} while( choice < 4);
    return 0;
}
