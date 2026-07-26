#include<iostream>
using namespace std;

struct Node{
    struct Node* previous;
    int data;
    struct Node* next;
}*first;

void createNode(int a[], int n){
    if(a == NULL || n<=0){
        cout<<"LL not created."<<endl;
        return;
    }
    first = new Node;
    Node *last;
    first->data = a[0];
    first->previous = first->next = NULL;
    last = first;
    for(int i=1; i<n; i++){
        Node *p = new Node;
        p->data = a[i];
        p->previous = last;
        last->next = p;
        p->next = NULL;
        last = p;
    }
}

void display(Node *p){
    if(p == NULL){
        cout<<"No LL present."<<endl;
        return;
    }
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void insertBeforeFirst(int num){
    Node *p = first;
    if(!p){
        cout<<"No LL present."<<endl;
        return;
    }
    Node *t = new Node;
    t->data = num;
    t->next = first;
    t->previous = NULL;
    first->previous = t;
    first = t;
}

void insert(int pos, int num){
    Node *p = first;
    if(!p || pos<0){
        cout<<"No LL present or Position out of bounds."<<endl;
        return;
    }
    if(pos == 0)
        return insertBeforeFirst(num);
    for(int i=0; p && i<pos-1; i++)
        p = p->next;
    if(p){
        Node *q = new Node;
        q->data = num;
        q->next = p->next;
        q->previous = p;
        if(p->next)
            p->next->previous = q;;
        p->next = q;
        cout<<"Inserted."<<endl;
    }
    else
        cout<<"Position out of bounds."<<endl;
}

int deleteFirst(Node *p){
    if(!p)
        return INT32_MIN;
    int d = p->data;
    first = p->next;
    if(p->next)
        p->next->previous = NULL;
    delete p;
    return d;
}

int deleteAtPos(Node *p, int pos){
    if(!p || pos<=0)
        return INT32_MIN;
    if(pos == 1)
        return deleteFirst(p);
    for(int i=0; p && i<pos-1; i++)
        p = p->next;
    if(p){
        int d = p->data;
        p->previous->next = p->next;
        if(p->next)
            p->next->previous = p->previous;
        delete p;
        return d;
    }
    else
        return INT32_MIN;
}

void reverse(Node* p){
    if(!p){
        cout<<"No LL present."<<endl;
        return;
    }
    while(p){
        if(p->next == NULL)
            first = p;
        Node *q = p->previous;
        p->previous = p->next;
        p->next = q;
        p = p->previous;
    }
}

int main(){
    int arr[] = {1,5,12,15,20};

    createNode(arr, 5);
    display(first);
    //insertBeforeFirst(-1);
    //insert(0, 1);
    //int d = deleteFirst(first);
    // int d = deleteAtPos(first, 5);
    // if(d == INT32_MIN)
    //     cout<<"LL not there or Position out of bounds."<<endl;
    // else
    //     cout<<"Deleted Node Data : "<< d << endl;
    reverse(first);
    display(first);
    return 0;
}