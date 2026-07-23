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

int main(){
    int arr[] = {0,5,12,15,15,20,25,40};

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
    // insertAfterLess(45);
    // insertAtEnd(50);
    
    // int del = deleteAtStart(first);
    
    // int del = deleteAtPos(first, 4);
    // if(del != INT16_MIN)
    //     cout<<"Deleted Node and value = "<<del<<endl;
    // else
    //     cout<<"No Linked List is present or position out of bound."<<endl;

    // if(isSorted(first))
    //     cout<<"Sorted."<<endl;
    // else
    //     cout<<"Not Sorted."<<endl;
    display(first);

    return 0;
}

// void delDuplicate(Node *p){
//     Node *q = NULL;
//     if(p){
//         q = p;
//         p = p->next;
//     }
//     while(p){
//         if(q->data == p->data){
//             q->next = p->next;
//         }
//         q = p;
//         p = p->next;
//     }
// }

int isSorted(Node *p){
    int x = INT16_MIN;
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
    int x = INT16_MIN;
    if(pos == 0 || pos == 1){
        return deleteAtStart(first);
    }
    if(p != NULL){
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
        }
    }
    return x;
}

int deleteAtStart(Node *p){
    int x = INT16_MIN;
    if(p != NULL){
        x = p->data;
        if(p == last){
            last = NULL;
            first = NULL;
        }
        else
            first = p->next;
    }
    return x;
}

void insertAfterLess(int num){
    Node *p = first;
    Node *q = first;
    if(p == NULL || p->data > num)
        insertAtStart(num);
    else{
        while(p->data < num && p != last){
            if(p != first)
                q = q->next;
            p = p->next;
        }
        if(p == last)
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
        return INT16_MIN;
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