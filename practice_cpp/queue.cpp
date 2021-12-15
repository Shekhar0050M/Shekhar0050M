#include<iostream>

using namespace std;

#define MAX 8

class queue{
    int arr[MAX];
public:
    int front=-1;
    int rear=-1;
    bool enqueue(int x);
    bool dequeue();
    int peek();
};

inline bool queue::enqueue(int x){
    if(rear>=MAX-1){
        cout<<"STACK OVERFLOW"<<endl;
        return 0;
    }
    arr[++rear]=x;
    return 1;
}

inline int queue::peek(){
    if(rear==front){
        cout<<"STACK UNDERFLOW"<<endl;
        return 0;
    }
    return arr[front+1];
}

inline bool queue::dequeue(){
    arr[++front]=0;
    return 1;
}

int main(){
    queue q1;
    for(int i=1;i<10;i++){
        q1.enqueue(i);
    }
    for(int i=0;i<10;i++){
        cout<<q1.peek()<<endl;
        q1.dequeue();
    }
}
