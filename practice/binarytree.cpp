#include <cstdio>
#include <iostream>

using namespace std;

typedef struct node{
    int data;
    struct node *left,*right;
}tree;

tree* create(){
    int x;
    tree *newnode;
    newnode=new tree;
    //printf("Enter the data");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    newnode->data=x;
    //printf("Enter the data in left node\n");
    newnode->left=create();
    //printf("Enter the data in right node\n");
    newnode->right=create();
    return newnode;
}

void display(tree *node){
    if(node==NULL){
        return;
    }
    printf("Data is %d",node->data);
    display(node->left);
    display(node->right);
    return;
}

int main(){
    tree *root;
    root=create();
    display(root);
}
