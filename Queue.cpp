// Not made front = 0 when first element is added
#include<iostream>
#include<climits>
using namespace std;

struct Queue{
    int size ;
    int front;
    int rear;
    int *Q;
};

void createQueue(Queue *q){
    cout<<"Enter size : ";
    cin>>q->size;
    q->front = q->rear = -1;
    q->Q = new int[q->size];
}

void destroyQueue(Queue *q){
    delete[] q->Q;
}

void display(Queue q){
    for(int i = q.front+1; i<=q.rear; i++)
        cout<<q.Q[i]<<" ";
    cout<<endl;
}

void insert(Queue *q, int n){
    if(q->rear == q->size-1){
        cout<<"Queue full."<<endl;
        return;
    }
    q->Q[++q->rear] = n;
}

int Qdelete(Queue *q){
    if(q->front == q->rear)
        return INT32_MIN;
    int d = q->Q[++q->front];
    return d;
}

int isFull(Queue q){
    if(q.rear == q.size-1)
        return 1;
    return 0;
}

int isEmpty(Queue q){
    if(q.rear == q.front)
        return 1;
    return 0;
}

int main(){
    struct Queue q;
    createQueue(&q);
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
    //     cout<<"Queue Empty."<<endl;
    // else
    //     cout<<"Deleted Element = "<<d<<endl;
    cout<<"Queue is Full = "<<isFull(q)<<endl;
    cout<<"Queue is Empty = "<<isEmpty(q)<<endl;
    display(q);
    destroyQueue(&q);
    return 0;
}