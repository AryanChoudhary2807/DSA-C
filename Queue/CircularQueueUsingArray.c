
#include <stdio.h>

int a[10];
int front =-1;
int rear =  -1;


void insert(){
    if((rear+1)%10 == front){
        printf("QUEUE  IS FULL!\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    rear = (rear + 1) % 10; 
    printf("Enter the Data = ");
    scanf("%d", &a[rear]);
    
}


  void  pop(){
    if(front==-1 || rear==-1){
        printf("QUEUE IS EMPTY!\n");
        return;
    }
    if(front == rear){
        front=rear=-1;
        return;
    }
    if(front==9){
        front=0;
        return;
    }
    front++;
  }
  
  void display(){
      if(front==-1){
          printf("QUEUE IS EMPTY!\n");
          return;
      }
      int i=front;
      do{
          printf("%d\n",a[i]);
         i = (i+1)%10;
      }while(i!=(rear+1)%10);
  }
  
int main() {
     printf(" CIRCULAR QUEUE\n");
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
