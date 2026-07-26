#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*head;

void createNode(int a[], int n){
    if(a == NULL || n<=0){
        cout<<"LL not created."<<endl;
        return;
    }
    head = new Node;
    Node *last;
    head->data = a[0];
    last = head;
    head->next = last;
    for(int i=1; i<n; i++){
        Node *p = new Node;
        p->data = a[i];
        p->next = head;
        last->next = p;
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

void insertbeforeHead(int num){
    Node *p = head;
    if(!p){
        cout<<"LL not there."<<endl;
        return;
    }
    while(p->next != head)
        p = p->next;
    Node *t = new Node;
    t->data = num;
    t->next = head;
    head = t;
    p->next = t;
}

void insert(int pos, int num){
    Node *p = head;
    if(!p || pos<0){
        cout<<"LL not there or Position out of bounds."<<endl;
        return;
    }
    if(pos == 0)
        return insertbeforeHead(num);
    for(int i=0; i<pos-1; i++)
        p = p->next;
    Node *t = new Node;
    t->data = num;
    t->next = p->next;
    p->next = t;
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

int deleteHead(Node *p){
    if(!p)
        return INT32_MIN;
    int d;
    while(p->next != head){
        p = p->next;
    }
    p->next = head->next;
    d = head->data;
    head = p->next;
    p = p->next;
    p = NULL;
    delete p;
    return d;
}

int deleteAtPos(int pos){
    Node *p = head;
    if(!p || pos<=0)
        return INT32_MIN;
    if((pos%count(head)) == 1)
        return deleteHead(p);
    Node *q = NULL;
    int d;
    for(int i=0;i<pos-1; i++){
        q = p;
        p = p->next;
    }
    q->next = p->next;
    d = p->data;
    p = NULL;
    delete p;
    return d;
}

int main(){
    int arr[] = {1,2,3,4,5};

    createNode(arr, 5);
    display(head);
    cout<<endl;
    // insert(11, 9);
    // insertbeforeHead(-1);
    // int c = count(head);
    // if(c == INT32_MIN)
    //     cout<<"LL not there."<<endl;
    // else
    //     cout<<"Number of Nodes : "<< c <<endl;
    // int del = deleteAtPos(8);
    int del = deleteAtPos(12);
    if(del == INT32_MIN)
        cout<<"LL not there."<<endl;
    else
        cout<<"Node deleted is : "<< del <<endl;
    display(head);
    return 0;
}