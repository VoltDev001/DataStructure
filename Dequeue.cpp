#include<iostream>
using namespace std;

struct Dequeue{
    int size;
    int front;
    int rear;
    int *Q;
};

void createDequeue(Dequeue *q){
    cout<<"Enter size : ";
    cin>>q->size;
    q->front = q->rear = -1;
    q->Q = new int[q->size];
}

void destroyDequeue(Dequeue *q){
    delete[] q->Q;
}

void display(Dequeue q){
    for(int i = q.front+1;  i <= q.rear; i++)
        cout<<q.Q[i]<<" ";
    cout<<endl;
}

void insertRear(Dequeue *q, int num){
    if(q->rear == q->size-1){
        cout<<"Dequeue Overflow."<<endl;
        return;
    }
    q->rear++;
    q->Q[q->rear] = num;
}

void deleteRear(Dequeue *q){
    if(q->rear == q->front){
        cout<<"Dequeue Underflow."<<endl;
        return;
    }
    int d = q->Q[q->rear--];
    cout<<"Deleted Data : "<<d<<endl;
}

void insertFront(Dequeue *q, int num){
    if(q->front == -1){ //you cannot insert using front at the beginning as it inserts backwards 
        cout<<"Cannot insert."<<endl;
        return;
    }
    q->Q[q->front] = num;
    q->front--;
}

void deleteFront(Dequeue *q){
    if(q->rear == q->front){
        cout<<"Dequeue Underflow."<<endl;
        return;
    }
    int d = q->Q[++q->front];
    cout<<"Deleted Data : "<<d<<endl;
}

int main(){
    Dequeue q;
    createDequeue(&q);
    insertRear(&q, 0);
    insertRear(&q, 5);
    insertRear(&q, 4);
    insertRear(&q, 8);
    deleteRear(&q);
    insertFront(&q, 80);
    deleteFront(&q);
    insertFront(&q, 84);
    display(q);
    return 0;
}