#include<iostream>
using namespace std;

struct Stack{
    int data;
    Stack *next;
}*top = NULL;

void push(int num){
    Stack *st = new Stack;
    if(!st){
        cout<<"Stack Overflow."<<endl;
        return;
    }
    st->data = num;
    st->next = top;
    top = st;
}

void display(Stack *p){
    if(!p){
        cout<<"Stack not there.";
        return;
    }
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}


void pop(){
    if(!top){
        cout<<"Stack Underflow."<<endl;
        return;
    }
    Stack *p = top;
    top = top->next;
    delete p;
}

int peek(int pos){
    Stack *p = top;
    for(int i = 0; p && i<pos-1; i++)
        p = p->next;
    if(!p || pos<=0)
        return INT32_MIN;
    return p->data;
}

int isEmpty(){
    if(top)
        return 0;
    return 1; 
}

int main(){
    push(0);
    push(5);
    push(12);
    push(15);
    push(20);
    push(27);
    pop();
    pop();
    cout<<"Peeked value : "<<peek(4)<<endl;
    display(top);
    return 0;
}