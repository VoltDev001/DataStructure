#include<iostream>
using namespace std;

struct CQueue{
    int size ;
    int front;
    int rear;
    int *Q;
};

void createCQueue(CQueue *q){
    cout<<"Enter size : ";
    cin>>q->size;
    q->front = q->rear = -1;
    q->Q = new int[q->size];
}

void display(CQueue q){
    for(int i = q.front+1; i<=q.rear; i++)
        cout<<q.Q[i]<<" ";
    cout<<endl;
}

void insert(CQueue *q, int n){
    if(q->rear == q->size-1 && q->front == -1){
        cout<<"CQueue full."<<endl;
        return;
    }
    q->rear %= (q->size-1);
    q->Q[++q->rear] = n;
}

int Qdelete(CQueue *q){
    if(q->front == q->size-1)
        return INT32_MIN;
    int d = q->Q[++q->front];
    return d;
}

int isFull(CQueue q){
    if(q.rear == q.size-1)
        return 1;
    return 0;
}

int isEmpty(CQueue q){
    if(q.rear == -1 || q.front == q.size-1)
        return 1;
    return 0;
}

int main(){
    struct CQueue q;
    createCQueue(&q);
    insert(&q, 0);
    // insert(&q, 1);
    // insert(&q, 2);
    // insert(&q, 3);
    // insert(&q, 4);
    // insert(&q, 0);
    // int d = Qdelete(&q);
    // d = Qdelete(&q);
    // d = Qdelete(&q);
    // d = Qdelete(&q);
    // d = Qdelete(&q);
    // d = Qdelete(&q);
    // if(d == INT32_MIN)
    //     cout<<"CQueue Empty."<<endl;
    // else
    //     cout<<"Deleted Element = "<<d<<endl;
    cout<<"CQueue is Full = "<<isFull(q)<<endl;
    cout<<"CQueue is Empty = "<<isEmpty(q)<<endl;
    display(q);
    return 0;
}