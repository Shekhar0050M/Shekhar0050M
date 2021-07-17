#include <cstdio>
#include <iostream>
#include <vector>

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

inline bool inordertraversal(node *curnode,vector<int> &arr){
    if(curnode==nullptr){
        return 1;
    }
    inordertraversal(curnode->left,arr);
    arr.push_back(curnode->data);
    inordertraversal(curnode->right,arr);
    return 1;
}

inline bool preordertraversal(node *curnode,vector<int> &arr){
    if(curnode==nullptr){
        return 1;
    }
    arr.push_back(curnode->data);
    preordertraversal(curnode->left,arr);
    preordertraversal(curnode->right,arr);
    return 1;
}

inline bool postordertraversal(node *curnode,vector<int> &arr){
    if(curnode==nullptr){
        return 1;
    }
    postordertraversal(curnode->left,arr);
    postordertraversal(curnode->right,arr);
    arr.push_back(curnode->data);
    return 1;
}

inline void display(vector<int> &arr){
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    arr.erase(arr.begin(),arr.end());
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
    bstinsertion(root,22);
    //
    vector<int> arr;
    inordertraversal(root,arr);
    printf("Inorder traversal:: ");
    display(arr);
    preordertraversal(root,arr);
    printf("Preorder traversal:: ");
    display(arr);
    postordertraversal(root,arr);
    printf("Postorder traversal:: ");
    display(arr);
}
