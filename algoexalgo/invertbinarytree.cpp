#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef struct node{
    int data;
    struct node *left=nullptr,*right=nullptr;
}node;

inline node *btinsert(){
    node *curnode;
    curnode=new node;
    printf("Enter data:: ");
    scanf("%d",&curnode->data);
    if(curnode->data==-1){
        return nullptr;
    }
    curnode->left=btinsert();
    curnode->right=btinsert();
    return curnode;
}

inline node *mymethodinverttree(node *curnode){
    if(curnode==nullptr){
        return nullptr;
    }
    node *newnode;
    newnode=new node();
    newnode->data=curnode->data;
    newnode->left=mymethodinverttree(curnode->right);
    newnode->right=mymethodinverttree(curnode->left);
    return newnode;
}

inline bool algoguymtd(node *curnode,vector<int> &storeprcs){
    if(curnode==nullptr){
        return 0;
    }
    storeprcs.push_back(curnode->data);
    algoguymtd(curnode->right,storeprcs);
    algoguymtd(curnode->left,storeprcs);
    return 1;
}

inline bool displaybst(node *curnode){
    if(curnode==nullptr) return 0;
    printf("%d ",curnode->data);
    displaybst(curnode->left);
    displaybst(curnode->right);
    return 1;
}


int main(){
    vector<int> inverttree;
    node *root=btinsert();
    displaybst(root);
    node *root2=mymethodinverttree(root);
    printf("\n");
    displaybst(root2);
    algoguymtd(root,inverttree);
    printf("\n");
    for(auto i:inverttree){
        cout<<i<<" ";
    }
    cout<<endl;
}
