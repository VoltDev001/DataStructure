#include<iostream>
using namespace std;

struct Node{
    struct Node* previous;
    int data;
    struct Node* next;
}*head;

void createNode(int a[], int n){
    if(a == NULL || n<=0){
        cout<<"LL not created."<<endl;
        return;
    }
    head = new Node;
    head->data = a[0];
    head->previous = head;
    head->next = head;
    Node *last = head;
    for(int i=1; i<n; i++){
        Node *p = new Node;
        p->data = a[i];
        p->previous = last;
        last->next = p;
        p->next = head;
        head->previous = p;
        last = p;
    }
}

void display(Node *p){
    if(p == NULL){
        cout<<"No LL present."<<endl;
        return;
    }
    do{
        cout<<p->data<<" ";
        p = p->next;
    }
    while(p != head);
    cout<<endl;
}

int count(Node *p){
    int c = 0;
    if(!p)
        return INT32_MIN;
    do{
        c++;
        p = p->next;
    }
    while(p != head);
    return c;
}

void insertBeforeHead(int num){
    Node *p = head;
    if(!p){
        cout<<"No LL present."<<endl;
        return;
    }
    Node *t = new Node;
    t->data = num;
    t->next = head;
    t->previous = head->previous;
    head->previous->next = t;
    head->previous = t;
    head = t;
}

void insert(int pos, int num){
    Node *p = head;
    if(!p || pos<0){
        cout<<"No LL present or Position out of bounds."<<endl;
        return;
    }
    if(pos == 0)
        return insertBeforeHead(num);
    for(int i=0; i<pos-1; i++)
        p = p->next;
    Node *q = new Node;
    q->data = num;
    q->next = p->next;
    q->previous = p;
    p->next->previous = q;
    p->next = q;
    cout<<"Inserted."<<endl;
}

int deleteHead(Node *p){
    if(!p)
        return INT32_MIN;
    int d = p->data;
    head = p->next;
    head->previous = p->previous;
    p->previous->next = head;
    delete p;
    return d;
}

int deleteAtPos(Node *p, int pos){
    if(!p || pos<=0)
        return INT32_MIN;
    if((pos%count(head)) == 1)
        return deleteHead(p);
    for(int i=0; i<pos-1; i++)
        p = p->next;
    int d = p->data;
    p->previous->next = p->next;
    p->next->previous = p->previous;
    delete p;
    return d;
}

int main(){
    int arr[] = {1,2,3,4,5};

    createNode(arr, 5);
    display(head);
    
    //insertBeforeHead(-1);
    //insert(7, -1);

    //int d = deleteHead(head);
    int d = deleteAtPos(head, 6);
    if(d == INT32_MIN)
        cout<<"LL not there or Position <= 0."<<endl;
    else
        cout<<"Deleted Node Data : "<< d << endl;
    display(head);
   
    return 0;
}