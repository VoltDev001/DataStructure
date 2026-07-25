#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*first1, *last1 , *first2, *last2, *third=NULL , *last=NULL;

void makeNode(int a[], int n, Node* &f, Node* &l);
void display(Node *p);
void inverseDisplay(Node *p);
int count(Node *p);
int max(Node *n);
Node* search(Node *p, int key);
void insertAtStart(Node* &f, Node* &l, int num);
void insertAtEnd(Node* &f, Node* &l, int num);
void insert(Node* &f, Node* &l, int pos, int num);
void insertAfterLess(Node* &f, Node* &l, int num);
int deleteAtStart(Node* &f, Node* &l);
int deleteAtPos(Node* &f, Node* &l, int pos);
int isSorted(Node *p);
void delDuplicate(Node *p, Node* &l);
void reverse(Node* &f);
void reverseLinks(Node* &f,  Node* &l);
void concatenation(Node* &l1, Node* &f2);
void merge(Node* &f1, Node* &f2);
int isLinear(Node *p);

int main(){
    int arr1[] = {0, 5, 6, 20}, arr2[] = {2, 7, 9, 15};

    makeNode(arr1, 4, first1, last1);
    makeNode(arr2, 4, first2, last2);

    display(first1);
    cout<<endl;
    display(first2);
    cout<<endl;
    
    // cout<<endl<<"Inverse Diplay:";
    // inverseDisplay(first1);

    // cout <<endl<< "Number of nodes:" << count(first2) << endl;

    // cout<<"Maximum data: "<<max(first1)<<endl;

    // Node *found = search(first1, 12);
    // if(found == NULL)
    //     cout<<"Data not in Linked List."<<endl;
    // else
    //     cout<<"Data is at: "<<found<<endl;
    // insertAtStart(first1, last1, -1);
    // insert(first1, last1, 4, 18);
    // insertAtEnd(first1, last1, 10);
    // insertAfterLess(first2, last2, 13);
    // insertAtEnd(first2, last2, 50);
    // concatenation(last1, first2);
    // int del = deleteAtStart(first2, last2);
    
    // // int del = deleteAtPos(first1, last1, 4);
    // if(del != INT32_MIN)
    //     cout<<"Deleted Node and value = "<<del<<endl;
    // else
    //     cout<<"No Linked List is present or position out of bound."<<endl;

    // if(isSorted(first1)){
    //     cout<<"Sorted."<<endl;
    //     delDuplicate(first1, last1);
    // }
    // else
    //     cout<<"Not Sorted."<<endl;
    // reverse(first1);
    // reverseLinks(first2, last2);
    // insertAtStart(first1, last1, 50);
    // insertAtEnd(first2, last2, -4);
    // concatenation(last1, first2);
    // display(first1);
    // cout<<endl;
    // display(first2);
    //merge(first1, first2);
    // insertAtEnd(third, last, 50);
    //display(third);
    // int iL = isLinear(first1);
    // if(iL)
    //     cout<<"Linked List is linear."<<endl;
    // else
    //     cout<<"Linked List is not linear."<<endl;
    // last2->next = first2->next;
    // int iL2 = isLinear(first2);
    // if(iL2)
    //     cout<<"Linked List is linear."<<endl;
    // else
    //     cout<<"Linked List is not linear."<<endl;
    cout<<endl;

    return 0;
}

int isLinear(Node *p){
    Node *q = p->next;
    while(p && q->next){
        if(q == p){
            return 0;
        }
        q = q->next->next;
        p = p->next;
    }
    return 1;
}

void merge(Node* &f1, Node* &f2){
    if(f1->data < f2->data){
        third = f1;
        last = f1;
        f1 = f1->next;
        last->next = NULL;
    }
    else{
        third = f2;
        last = f2;
        f2 = f2->next;
        last->next = NULL;
    }
    while(f1 && f2){
        if(f1->data < f2->data){
            last->next = f1;
            last = f1;
            f1 = f1->next;
        }
        else{
            last->next = f2;
            last = f2;
            f2 = f2->next;
        }
        last->next = NULL;
    }
    if(f1){
        last->next = f1;
        last = last1;
    }
    else{
        last->next = f2;
        last = last2;
    }
}

void concatenation(Node* &l1, Node* &f2){
    if(l1 && f2){
        l1->next = f2;
        f2 = NULL;
    }
}

void reverseLinks(Node* &f,  Node* &l){
    Node *p = f, *q = NULL, *r = NULL;
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
        if(!r)
            l = q;
    }
    f = q;
}

void reverse(Node* &f){
    Node *p = f;
    int c = count(p);
    if(c){
        int rev[c];
        for(int i=0; i<c; i++){
            rev[i] = p->data;
            p = p->next;
        }
        p = f;
        for(int i=c-1; i>=0; i--){
            p->data = rev[i];
            p = p->next;
        }
    }
    else 
        return;
}

void delDuplicate(Node *p, Node* &l){
    if(!p)
        return;
    Node *q = p->next;
    while(q && q!=l){
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
            l = p;
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

int deleteAtPos(Node* &f, Node* &l, int pos){
    int x = INT32_MIN;
    Node *p =  f;
    if(p == NULL || pos < 1)
        return x;
    if(pos == 1){
        return deleteAtStart(f, l);
    }
    Node *r = NULL;
    for(int i=0; i<pos-1 && p; i++){
        r = p;
        p = p->next;
    }
    if(p){
        r->next = p->next;
        x = p->data;
        if(p == l)
            l = r;
        delete p;
        return x;
    }
    return x;
}

int deleteAtStart(Node* &f, Node* &l){
    Node *p = f;
    int x = INT32_MIN;
    if(p != NULL){
        x = p->data;
        if(p == l){
            l = NULL;
            f = NULL;
        }
        else{
            f = p->next;
        }
        delete p;
    }
    return x;
}

void insertAfterLess(Node* &f, Node* &l, int num){
    Node *p = f;
    Node *q = NULL;
    if(p == NULL || p->data > num)
        insertAtStart(f, l, num);
    else{
        while(p->data < num && p != l){
            q = p;
            p = p->next;
        }
        if(p == l && p->data < num)
            insertAtEnd(f, l, num);
        else{
            Node *t = new Node;
            t->data = num;
            t->next = p;
            q->next = t;
        }
    }
}

void insert(Node* &f, Node* &l, int pos, int num){
    if(pos<0)
        return;
    else if(pos == 0 ){
        insertAtStart(f, l, num);
    }
    else{
        Node *p = f;
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
        if(p == l)
            l = t;
    }
}

void insertAtEnd(Node* &f, Node* &l, int num){
    if(l != NULL){
        Node *t = new Node;
        t->data = num;
        t->next = NULL;
        l->next = t;
        l = t;
    }
    else{
        insertAtStart(f, l, num);
    }
}

void insertAtStart(Node* &f, Node* &l, int num){
    if(f != NULL){
        Node* t = new Node;
        t->data = num;
        t->next = f;
        f = t;
    }
    else{
        f = new Node;
        f->data = num;
        f->next = NULL;
        l = f;
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

void makeNode(int a[], int n, Node* &f, Node* &l){
    if(a == NULL || n<=0)
        return;
    f = new Node;
    f->data = a[0];
    f->next = NULL;
    l = f;
    for(int i=1; i<n; i++){
        Node *p = new Node;
        p->data = a[i];
        p->next = NULL;
        l->next = p;
        l = p;
   }
}