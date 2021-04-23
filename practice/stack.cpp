#include<iostream>

using namespace std;

#define MAX 10

int arr[MAX];
int top=-1;

inline bool push(int x){
    if(top>=MAX-1){
        cout<<"STACK OVERFLOW"<<endl;
        return 0;
    }
    arr[++top]=x;
    return 1;
}

inline int peek(){
    if(top<0){
        cout<<"STACK UNDERFLOW"<<endl;
        return 0;
    }
    return arr[top];
}

inline bool pop(){
    if(top<0){
        cout<<"STACK UNDERFLOW"<<endl;
        return 0;
    }
    arr[top--]=0;
    return 1;

}

int main(){
    int x=0;
    for (int i=0;i<11;i++) {
        cin>>x;
        push(x);
    }
    for(int i=0;i<12;i++){
        cout<<peek()<<endl;
        pop();
    }
}



