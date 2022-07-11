#include <cstdio>
#include <iostream>

using namespace std;

typedef struct node{
    int data;
    struct node *left,*right;
}tree;

static int ans;

struct node *newnode(int item){
    tree *temp=new node();
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
};
 
tree *insert(tree *node,int data){
    if(node==NULL) {
        tree *temp=new tree();
        temp->data=data;
        temp->left=temp->right=NULL;
        return temp;
    }
    if(data<node->data){
        node->left=insert(node->left,data);
    }
    else{
        node->right=insert(node->right,data);
    }
    return node;
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

tree *findclosestvalue(tree *node,int value,int closest,int tempdiff){
    if(node==NULL){
        ans=closest;
        return node;
    }
    if(abs(value-node->data)<tempdiff){
        tempdiff=abs(value-node->data);
        closest=node->data;
    }
    if(value<node->data){
        findclosestvalue(node->left,value,closest,tempdiff);
    }
    else{
        findclosestvalue(node->right,value,closest,tempdiff);
    }
    return node;
}

int main(){
    int arr[]={10,5,15,2,5,13,22,1,14},x=12;
    int n=sizeof(arr)/sizeof(arr[0]);
    tree *root=NULL,*closest;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    //display(root);
    //printf("Enter the element::");
    //scanf("%d",&x);
    closest=findclosestvalue(root,x,0,INT_MAX);
    printf("%d",ans);
}
