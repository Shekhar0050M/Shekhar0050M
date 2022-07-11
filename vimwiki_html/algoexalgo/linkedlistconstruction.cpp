#include <cstdio>
#include <iostream>

using namespace std;

typedef struct node{
    int data;
    struct node *next=NULL,*prev=NULL;
}node;

inline void display(node *head){
    node *cur=head;
    printf("Printing details: ");
    while (cur!=NULL) {
        printf("%d ",cur->data);
        cur=cur->next;
    }
}

inline void displayrev(node *end){
    node *cur=end;
    printf("\nPrinting details in reverse order: ");
    while (cur!=NULL) {
        printf("%d ",cur->data);
        cur=cur->prev;
    }
}

inline void insertinlinkedlist(node *head){
    node *pos=head,*newnode,*curnxt;
    int temp=0;
    newnode=new node;
    printf("Enter the value you want to enter: ");
    scanf("%d",&newnode->data);
    printf("Enter the value after which you want to emter: ");
    scanf("%d",&temp);
    while(pos!=nullptr){
        if(temp==pos->data){
            newnode->next=curnxt;
            pos->next=newnode;
            curnxt->prev=newnode;
            newnode->prev=pos;
            break;
        }
        pos=pos->next;
        curnxt=pos->next;
    }
}

inline void deletionofnode(node *head){
    node *cur=head,*curnxt,*curprev;
    int temp=0;
    printf("Enter the value you want to delete: ");
    scanf("%d",&temp);
    while(cur!=nullptr){
        if(cur->data==temp){
            curprev->next=curnxt;
            curnxt->prev=curprev;
            free(cur);
            break;
        }
        cur=cur->next;
        curnxt=cur->next;
        curprev=cur->prev;
    }
}

int main(){
    int size=0,temp=0;
    node *head,*cur,*newnode,*end;
    head=new node;
    printf("Enter the data you want to store in head: ");
    scanf("%d",&head->data);
    cur=head;
    printf("Enter the size of node: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        printf("Enter the data: ");
        scanf("%d",&temp);
        newnode=new node;
        newnode->data=temp;
        cur->next=newnode;
        newnode->prev=cur;
        cur=cur->next;
    }
    end=cur;
}



