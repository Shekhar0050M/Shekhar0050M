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
    node *curnode=root;
    while(curnode!=nullptr){
        printf("%ld ",curnode->data);
        curnode=curnode->next;
    }
}

void deletenode(node *bdel,node *todel,node *afdel){
    node *temp;
    temp=todel;
    bdel->next=afdel;
    todel->next=nullptr;
    free(temp);
}

void posofdelnode(node *root){
    node *prevnode,*ptr1=root,*ptr2=root,*curnnode;
    int64_t k;
    printf("Enter the node you want to delete:: ");
    scanf("%ld",&k);
    while(k--){
        ptr2=ptr2->next;
    }
    while(ptr2!=nullptr){
        prevnode=ptr1;
        ptr1=ptr1->next;
        curnnode=ptr1->next;
        ptr2=ptr2->next;
    }
    deletenode(prevnode,ptr1,curnnode);
}

int main(){
    node *root=createsll();
    printll(root);
    posofdelnode(root);
    printll(root);
}
