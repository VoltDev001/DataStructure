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
void insertAfterLess(int num);
int deleteAtStart(Node *p);
int deleteAtPos(Node *p, int pos);
int isSorted(Node *p);
void delDuplicate(Node *p);
void reverse(Node *p);

int main(){
    int arr[] = {0,5,12,15,20,30,40,45};

    makeNode(arr, 8);

    display(first);
    cout<<endl;
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
    //insert(0, -1);
    //insertAtEnd(10);
    //insertAfterLess(45);
    //insertAtEnd(50);
    
    // int del = deleteAtStart(first);
    
    //  //int del = deleteAtPos(first, 4);
    // if(del != INT32_MIN)
    //     cout<<"Deleted Node and value = "<<del<<endl;
    // else
    //     cout<<"No Linked List is present or position out of bound."<<endl;

    // if(isSorted(first)){
    //     cout<<"Sorted."<<endl;
    //     delDuplicate(first);
    // }
    // else
    //     cout<<"Not Sorted."<<endl;
    reverse(first);
    display(first);

    return 0;
}

void reverse(Node *p){
    int c = count(p);
    if(c){
        int rev[c];
        for(int i=0; i<c; i++){
            rev[i] = p->data;
            p = p->next;
        }
        p = first;
        for(int i=c-1; i>=0; i--){
            p->data = rev[i];
            p = p->next;
        }
    }
    else 
        return;
}

void delDuplicate(Node *p){
    if(!p)
        return;
    Node *q = p->next;
    while(q && q!=last){
        if(q->data == p->data){
            p->next = q->next;
            delete q;
            q = p->next;
        }
        else{
            p = q;
            q = q->next;
        }
    }
    if(q){
        if(q->data == p->data){
            p->next= q->next;
            delete q;
            last = p;
        }
    }
}


int isSorted(Node *p){
    int x = INT32_MIN;
    if(!p)
        return 0;
    while(p){
        if(p->data < x)
            return 0;
        else{
            x = p->data;
            p = p->next;
        }
    }
    return 1;
}

int deleteAtPos(Node *p, int pos){
    int x = INT32_MIN;
    if(p == NULL || pos < 1)
        return x;
    if(pos == 1){
        return deleteAtStart(first);
    }
    Node *r = NULL;
    for(int i=0; i<pos-1 && p; i++){
        r = p;
        p = p->next;
    }
    if(p){
        r->next = p->next;
        x = p->data;
        if(p == last)
            last = r;
        delete p;
        return x;
    }
    return x;
}

int deleteAtStart(Node *p){
    int x = INT32_MIN;
    if(p != NULL){
        x = p->data;
        if(p == last){
            last = NULL;
            first = NULL;
        }
        else{
            first = p->next;
        }
        delete p;
    }
    return x;
}

void insertAfterLess(int num){
    Node *p = first;
    Node *q = NULL;
    if(p == NULL || p->data > num)
        insertAtStart(num);
    else{
        while(p->data < num && p != last){
            q = p;
            p = p->next;
        }
        if(p == last && p->data < num)
            insertAtEnd(num);
        else{
            Node *t = new Node;
            t->data = num;
            t->next = p;
            q->next = t;
        }
    }
}

void insert(int pos, int num){
    if(pos<0)
        return;
    else if(pos == 0 ){
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

Node* search(Node *p, int key){
    while(p){
        if(p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
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
        return INT32_MIN;
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

void inverseDisplay(Node *p){
    if(p){
        inverseDisplay(p->next);
        cout<< p->data << " ";
    }
}

void display(Node *p){
    while(p){
        cout<< p->data << " ";
        p = p->next;
    }
} 

void makeNode(int a[], int n){
    if(a == NULL || n<=0)
        return;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for(int i=1; i<n; i++){
        Node *p = new Node;
        p->data = a[i];
        p->next = NULL;
        last->next = p;
        last = p;
   }
}