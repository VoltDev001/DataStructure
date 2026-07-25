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
}

void insert(int pos, int num){
    Node *p = head;
    if(!p || pos<0){
        cout<<"LL not there or Position out of bounds."<<endl;
        return;
    }
    for(int i=0; i<pos-1; i++)
        p = p->next;
    Node *t = new Node;
    t->data = num;
    t->next = p->next;
    p->next = t;
}


int main(){
    int arr[] = {1,2,3,4,5};

    createNode(arr, 5);
    display(head);
    cout<<endl;
    insert(2, 9);
    insert(6,8);
    display(head);
    return 0;
}