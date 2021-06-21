#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <utility>
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
    //printf("Enter the data");
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
    printf("Data is %d\n",node->data);
    display(node->left);
    display(node->right);
    return;
}

void findnodedepth(tree *node,int depth,vector<pair<int,int>> &a){
    if(node==NULL){
        return;
    }
    a.push_back(make_pair(node->data,depth));
    findnodedepth(node->left,++depth,a);
    findnodedepth(node->right,++depth,a);
}

int maxdepth(vector<pair<int,int>> a){
    int maxelement=0;
    for(auto i:a){
        if(i.second>maxelement){
            maxelement=i.second;
        }
    }
    return maxelement;
}

int main(){
    tree *root;
    vector<pair<int,int>> a;
    root=create();
    //display(root);
    findnodedepth(root,0,a);
    for(auto i:a){
        printf("Depth of element %d is %d.\n",i.first,i.second);
    }
    printf("Depth of tree is %d",maxdepth(a));
}
