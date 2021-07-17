#include <cstdio>
#include<iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *left=nullptr,*right=nullptr;
}node;

inline bool bstsearch(node *curnode,int key){
    if(key==curnode->data){
        return true;
    }
    else if(key<curnode->data){
        bstsearch(curnode->left,key);
    }
    else{
        bstsearch(curnode->right,key);
    }
    return false;
}

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

inline bool bstdisplay(node *curnode){
    if(curnode==nullptr){
        return 0;
    }
    printf("%d ",curnode->data);
    bstdisplay(curnode->left);
    bstdisplay(curnode->right);
    return 0;
}

//Deletion is hard , read with concentration

inline bool bstdeletion(node *prevnode,node *curnode,int key){
    if(key==curnode->data){
        if(curnode->left==nullptr && curnode->right==nullptr){
            node *n=curnode;
            if(prevnode->left==curnode){
                prevnode->left=nullptr;
            }
            else{
                prevnode->right=nullptr;
            }
            delete n;
            return 1;
        }
        else if(curnode->right==nullptr){
            node *n=curnode;
            prevnode->left=n->left;
            delete n;
            return 1;
        }
        else{
            node *n=curnode->right;
            prevnode=curnode;
            while(n->left!=nullptr){
                prevnode=n;
                n=n->left;
            }
            int k=n->data;
            bstdeletion(nullptr,curnode,n->data);
            curnode->data=k;
            return 1;
        }
    }
    else if(key<curnode->data){
        bstdeletion(curnode,curnode->left,key);
    }
    else{
        bstdeletion(curnode,curnode->right,key);
    }
    return 0;
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
    bstdisplay(root);
    printf("\n");
    //if(bstsearch(root,14)){
        //printf("Present.\n");
    //}
    //else{
        //printf("Not present.\n");
    //}
    bstdeletion(nullptr,root,10);
    bstdisplay(root);
}
