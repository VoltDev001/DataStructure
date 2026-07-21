#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*first;

void makeNode(int a[], int n){
    if(a == NULL || n<=0)
        return;
    first = new Node();
    first->data = a[0];
    first->next = NULL;
    Node* last = first;
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

int main(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9};

    makeNode(arr, 10);

    display(first);

    return 0;
}