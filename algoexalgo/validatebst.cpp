#include <iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *left=nullptr,*right=nullptr;
}node;

inline bool bstinsertion(node *curnode,int key){
    if(key<curnode->data){
        if(curnode->left==nullptr){
            node *newnode;
            newnode=new node;
            newnode->data=key;
            curnode->left=newnode;
            return 1;
        }
        bstinsertion(curnode->left,key);
    }
    else{
        if(curnode->right==nullptr){
            node *newnode;
            newnode=new node;
            newnode->data=key;
            curnode->right=newnode;
            return 1;
        }
        bstinsertion(curnode->right,key);
    }
    return 0;
}

inline bool validatebst(int maxnum,int minnum,node *curnode){
    if(curnode==nullptr){
        return 1;
    }
    if(!(curnode->data<maxnum && curnode->data>=minnum)){
        return 0;
    }
    validatebst(curnode->data,minnum,curnode->left);
    validatebst(maxnum,curnode->data,curnode->right);
    return 1;
}

int main(){
    node *root;
    root=new node;
    root->data=10;
    bstinsertion(root,5);
    bstinsertion(root,15);
    bstinsertion(root,2);
    bstinsertion(root,5);
    bstinsertion(root,1);
    bstinsertion(root,13);
    bstinsertion(root,22);
    bstinsertion(root,14);
    int k=validatebst(INT_MAX,INT_MIN,root);
    if(k){
        cout<<"It is a binary search tree.\n";
    }
    else{
        cout<<"Not a binary search tree.\n";
    }
}
