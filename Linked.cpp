#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*first, *last;

void makeNode(int a[], int n);
void display(Node *p);
void inverseDisplay(Node *p);
int count(Node *p);
int max(Node *n);
Node* search(Node *p, int key);
void insertAtStart(int num);
void insertAtEnd(int num);
void insert(int pos, int num);

int main(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9};

    //makeNode(arr, 10);

    //display(first);
    //cout<<endl;
    // cout<<endl<<"Inverse Diplay:";
    // inverseDisplay(first);

    // cout <<endl<< "Number of nodes:" << count(first) << endl;

    // cout<<"Maximum data: "<<max(first)<<endl;

    // Node *found = search(first, 10);
    // if(found == NULL)
    //     cout<<"Data not in Linked List."<<endl;
    // else
    //     cout<<"Data is at: "<<found<<endl;
    //insertAtStart(-1);
    insert(0, -1);
    //insertAtEnd(10);
    display(first);

    return 0;
}

void makeNode(int a[], int n){
    if(a == NULL || n<=0)
        return;
    first = new Node();
    first->data = a[0];
    first->next = NULL;
    last = first;
    for(int i=1; i<n; i++){
        Node *p = new Node();
        p->data = a[i];
        p->next = NULL;
        last->next = p;
        last = p;
   }
}

void display(Node *p){
    while(p){
        cout<< p->data << " ";
        p = p->next;
    }
} 

void inverseDisplay(Node *p){
    if(p){
        inverseDisplay(p->next);
        cout<< p->data << " ";
    }
}

int count(Node *p){
    int c=0;
    while(p){
        c++;
        p = p->next;
    }
    return c;
}

int max(Node* n){
    if(n){
        int m = n->data;
        n=n->next;
        while(n){
            if(n->data > m)
                m = n->data;
            n = n->next;
        }
        return m;
    }
    else{
        cout<<"There is no node."<<endl;
        return INT16_MIN;
    }
}

Node* search(Node *p, int key){
    while(p){
        if(p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

void insertAtStart(int num){
    if(first != NULL){
        Node* t = new Node;
        t->data = num;
        t->next = first;
        first = t;
    }
    else{
        first = new Node;
        first->data = num;
        first->next = NULL;
        last = first;
    }
}

void insertAtEnd(int num){
    if(last != NULL){
        Node *t = new Node;
        t->data = num;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    else{
        insertAtStart(num);
    }
}

void insert(int pos, int num){
    if(pos == 0 ){
        insertAtStart(num);
    }
    else{
        Node *p = first;
        for(int i=0; p && i<pos-1; i++){
            p = p->next;
        }
        if(!p){
            cout<<"Position out of bound."<<endl;
            return;
        }
        Node *t = new Node;
        t->data = num;
        t->next = p->next;
        p->next = t;
        if(p == last)
            last = t;
    }
}