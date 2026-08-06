#include<iostream>
#include<climits>
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
    //q->size = 5;
    q->front = q->rear = 0;
    q->Q = new int[q->size];
}

void destroyCQueue(CQueue *q){
    delete[] q->Q;
}

void display(CQueue q){
    int i = q.front;
    while(i != q.rear){
        i = (i+1) % q.size;
        cout<<q.Q[i]<<" ";
    }
    cout<<endl;
}

void insert(CQueue *q, int n){
    if(q->front == (q->rear + 1) % q->size){
        cout<<"Queue Overflow."<<endl;
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = n;
}

int Qdelete(CQueue *q){
    if(q->front == q->rear)
        return INT32_MIN;
    q->front = (q->front+1) % q->size; 
    int d = q->Q[q->front];
    return d;
}

int isFull(CQueue q){
    if(q.front == (q.rear + 1) % q.size)
        return 1;
    return 0;
}

int isEmpty(CQueue q){
    if(q.front == q.rear)
        return 1;
    return 0;
}

int main(){
    struct CQueue q;
    createCQueue(&q);
    insert(&q, 0);
    insert(&q, 1);
    insert(&q, 2);
    insert(&q, 3);
    insert(&q, 4);
    insert(&q, 0);
    int d = Qdelete(&q);
    if(d == INT32_MIN)
        cout<<"CQueue Empty."<<endl;
    else
        cout<<"Deleted Element = "<<d<<endl;
    // d = Qdelete(&q);
    // if(d == INT32_MIN)
    //     cout<<"CQueue Empty."<<endl;
    // else
    //     cout<<"Deleted Element = "<<d<<endl;
    // d = Qdelete(&q);
    // if(d == INT32_MIN)
    //     cout<<"CQueue Empty."<<endl;
    // else
    //     cout<<"Deleted Element = "<<d<<endl;
    // d = Qdelete(&q);
    // if(d == INT32_MIN)
    //     cout<<"CQueue Empty."<<endl;
    // else
    //     cout<<"Deleted Element = "<<d<<endl;
    // insert(&q, 9);
    // insert(&q, 8);
    // insert(&q, 9);
    // insert(&q, 8);
    // cout<<"CQueue is Full = "<<isFull(q)<<endl;
    // cout<<"CQueue is Empty = "<<isEmpty(q)<<endl;
    display(q);
    destroyCQueue(&q);
    return 0;
}