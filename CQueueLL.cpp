#include<iostream>
#include<climits>
using namespace std;

struct Queue{
    int data;
    Queue* next;
}*front = nullptr, *rear = nullptr;

void insert(int n){
    Queue *t = new Queue();
    if(t == nullptr)
        return;
    t->data = n;
    t->next = nullptr;
    if(rear == nullptr)
        front = rear = t;
    else{
        rear->next = t;
        rear = t;
    }
}

void queueDestructor(Queue *q){
    delete q;
}

int qDelete(Queue *t){
    if(!t)
        return INT32_MIN;
    int d = t->data;
    front = t->next;
    delete t;
    return d;
}

void display(Queue *t){
    while(t){
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<endl;
}

int main(){
    Queue *q = new Queue();
    insert(0);
    insert(1);
    insert(5);
    insert(10);
    insert(12);
    int d = qDelete(front);
    if(d == INT32_MIN)
        cout<<"Stack Underflow."<<endl;
    else
        cout<<"Deleted data = "<<d<<endl;
    display(front);
    return 0;
}