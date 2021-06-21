#include <cstdio>
#include <iostream>
#include<stack>

using namespace std;

typedef struct node{
    int data;
    struct node *left,*right;
}tree;

tree* create(){
    int x;
    tree *newnode;
    newnode=new tree;
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    newnode->data=x;
    newnode->left=create();
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

void depthfirstsearch(tree *node,stack<int> &a){
    if(node==NULL){
        return;
    }
    a.push(node->data);
    depthfirstsearch(node->left,a);
    depthfirstsearch(node->right,a);
}

void displaystack(stack<int> &a){
    if(a.empty()){
        return;
    }
    int x=a.top();
    a.pop();
    displaystack(a);
    printf("Data in stack:: %d\n",x);
    a.push(x);
}

int main(){
    tree *root;
    stack<int> a;
    root=create();
    //display(root);
    depthfirstsearch(root,a);
    displaystack(a);
}
