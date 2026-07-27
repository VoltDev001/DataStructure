#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Stack{
private:
    Node *top;

public:
    Stack(){
        top = NULL;
    }
    void display();
    void push(int num);
    int pop();
    int peek(int pos);
    int findTop();
    int isEmpty();
    int isFull();
};

void Stack::push(int num){
    Node *st = new Node;
    if(!st){
        cout<<"Stack Overflow."<<endl;
        return;
    }
    st->data = num;
    st->next = top;
    top = st;
}

void Stack::display(){
    Node *p = top;
    if(!p){
        cout<<"Stack empty.";
        return;
    }
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int Stack::pop(){
    if(!top)
        return INT32_MIN;
    Node *p = top;
    int d = top->data;
    top = top->next;
    delete p;
    return d;
}

int Stack::peek(int pos){
    Node *p = top;
    for(int i = 0; p && i<pos-1; i++)
        p = p->next;
    if(!p || pos<=0)
        return INT32_MIN;
    return p->data;
}

int Stack :: findTop(){
    if(top)
        return top->data;
    return INT32_MIN;
}

int Stack :: isEmpty(){
    return top ? 0 : 1;
}

int Stack :: isFull(){
    Node *p = new Node;
    int f = p ? 1 : 0;
    delete p;
    return f;
}

int main(){
    Stack st;
    st.push(0);
    st.push(5);
    st.push(10);
    st.push(18);
    st.push(45);
    st.display();
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.peek(2)<<endl;
    cout<<st.findTop()<<endl;
    cout<<st.isEmpty()<<endl;
    cout<<st.isFull()<<endl;
    return 0;
}