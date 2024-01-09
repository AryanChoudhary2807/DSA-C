// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
    int data;
    struct node *left;
    struct node *right;
};

    int idx=-1;
    struct node *buildtree(int nodes[]){
        idx++;
        if(nodes[idx] == -1){
            return NULL;
        }
        struct node *newnode = (struct node*) malloc(sizeof(struct node));
        newnode->data = nodes[idx];
        newnode->left = buildtree(nodes);
        newnode->right = buildtree(nodes);
        
        return newnode;
        
    }
    
    void preorder(struct node *root){
        if(root == NULL){
            return;
        }
        
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }

void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node *root){
    if(root == NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main() {
    // Write C code here
      int nodes[] = {30,20,10,-1,15,-1,-1,25,23,-1,-1,-1,39,35,-1,-1,42,-1,-1};
    struct node *root = buildtree(nodes);
    printf(" Root = %d \n",root->data);
    printf("Preorder\n");
    preorder(root);
    printf("\nInorder\n");
    inorder(root);
    printf("\nPostorder\n");
    postorder(root);
    return 0;
}
