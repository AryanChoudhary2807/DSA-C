// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node *min(struct node *root);
struct node{
    int data;
    struct node *left;
    struct node *right;
};


struct node *insert(struct node *root , int val){
    if(root == NULL){
        root = (struct node*) malloc(sizeof(struct node));
        root->data = val;
        return root;
    }
    
    if(root->data > val){
        root->left = insert(root->left , val);
    }
    
    else{
        root->right = insert(root->right , val);
    }
    
    return root;
    
}

 void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

bool search(struct node *root , int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
   else if(root->data > key){
        return search(root->left , key);
    }
    else{
        return search(root->right , key);
    }
}

struct node *delete(struct node *root , int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data > key){
        root->left = delete(root->left,key);
    }
    else if(root->data < key){
       root->right = delete(root->right,key);
    }
    else{
        //case 1
        if(root->right==NULL && root->left==NULL){
            return NULL;
        }
        
        //case 2
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }
        
        // case 3
        struct node *Is = min(root->right);
        root->data = Is->data;
        root->right = delete(root->right , Is->data);
    }
    return root;
}

struct node *min(struct node *root){
    
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
    
}

int main() {
    // Write C code here
     int values[] = {5,1,3,4,2,7};
     struct node *root = NULL;
     
     for(int i=0;i<(sizeof(values)/4) ; i++){
         root = insert(root , values[i]);
     }

inorder(root);
printf("\n");
//Search
if(search(root , 6)){
    printf("Found\n");
}
else{
    printf("Not found!\n");
}

delete(root,7);
inorder(root);
    return 0;
}
