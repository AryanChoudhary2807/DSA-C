
#include <stdio.h>

int a[10];
int top=-1;

void push(){
    if(top==9){
        printf("Stack is full");
        return;
    }
    top++;
    printf("Enter the data = ");
    scanf("%d",&a[top]);
}

void pop(){
    if(top==-1){
        printf("Stack is Empty!\n");
        return;
    }
    top--;
    return;
}

void peek(){
    if(top==-1){
    printf("Stack is Empty!\n");
    return;
    }
    printf("%d\n",a[top]);
}

void display(){
    if(top==-1){
    printf("Stack is Empty!\n");
    return;
    }
    for(int i=top;i>-1;i--){
        printf("%d\n",a[i]);
    }
}


int main() {
    
    printf("    Stack \n");
    int choice;
    
    do{
        printf(" MENU \n1.Push \n2.Pop \n3.Peek \n4.Display \n");
        printf("Enter your choice = ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: push();break;
            case 2: pop();break;
            case 3: peek();break;
            case 4: display();break;
            default : printf("Invalid choice!\n");
        }
    }while(choice<5);

    return 0;
}
