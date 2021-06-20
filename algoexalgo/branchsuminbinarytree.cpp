#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef struct node{
    int data;
    struct node *left,*right;
}tree;

tree* create(){
    int x;
    tree *newnode;
    newnode=new tree;
    printf("Enter the data: ");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
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
    printf("Data is %d\n",node->data);
    display(node->left);
    display(node->right);
    return;
}

void getbranchsum(tree *node,int curvalue,vector<int> &a){
    if(node==NULL) return;
    curvalue+=node->data;
    if(node->left==NULL && node->right==NULL){
        a.push_back(curvalue);
        return;
    }
    getbranchsum(node->left,curvalue,a);
    getbranchsum(node->right,curvalue,a);
}

int main(){
    tree *root;
    vector<int> a;
    root=create();
    //display(root);
    getbranchsum(root,0,a);
    for(auto i:a){
        cout<<i<<" ";
    }
}
