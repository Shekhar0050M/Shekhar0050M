#include <cstdio>
#include <iostream>

using namespace std;

typedef struct node {
    int64_t data;
    struct node* next=nullptr;
}node;

node* createsll(){
    node *root,*curnode,*newnode;
    root=new node;
    root->data=0;
    curnode=root;
    for(int64_t i=1;i<10;i++){
        newnode=new node;
        newnode->data=i;
        curnode->next=newnode;
        curnode=curnode->next;
    }
    return root;
}

void printll(node *root){
    node *curnode;
    for(int i=0;i<10;i++){
        printf("%ld ",curnode->data);
        curnode=curnode->next;
    }
}

int main(){
    node *root=createsll();
    
}
