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

inline void binaryiteration(node *root,int arr[],int lower,int upper){
    if(lower>upper) return;
    int mid=(lower+upper)/2;
    if(root->data==0){
        root->data=arr[mid];
    }
    else{
        bstinsertion(root,arr[mid]);
    }
    binaryiteration(root,arr,lower,mid-1);
    binaryiteration(root,arr,mid+1,upper);
}

inline node *binaryiterationimprovised(int arr[],int lower,int upper){
    if(lower>upper) return nullptr;;
    int mid=(lower+upper)/2;
    node *newnode=new node();
    newnode->data=arr[mid];
    newnode->left=binaryiterationimprovised(arr,lower,mid-1);
    newnode->right=binaryiterationimprovised(arr,mid+1,upper);
    return newnode;
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

int main(){
    int arr[]={1,2,5,7,10,13,14,15,22},size=(sizeof(arr)/sizeof(arr[0]));
    node *root=new node();
    binaryiteration(root,arr,0,size-1);
    //bstdisplay(root);
    //Work needed on cleaner method.
    node *root2=binaryiterationimprovised(arr,0,size-1);
    bstdisplay(root2);
}
