#include<iostream>
#include<string.h>
using namespace std;

class Node{
public:
    // int data;
    char data;
    Node *next;
};

class Stack{
private:
    Node *top;

public:
    Stack(){
        top = NULL;
    }

    ~Stack() {
        Node *p = top;
        while (top) {
            top = top->next;
            delete p;
            p = top;
        }
    }

    void display();
    //void push(int num);
    void push(char num);
    char pop();
    //void pop();
    int peek(int pos);
    int findTop();
    int isEmpty();
    int isFull();
};

void Stack::push(char num){
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

// void Stack::pop(){
//     if(!top)
//         return;
//     Node *p = top;
//     top = top->next;
//     delete p;
// }

char Stack::pop(){
    if(!top)
        return 0;
    Node *p = top;
    char d = top->data;
    top = top->next;
    delete p;
    return d;
}

int Stack::peek(int pos){
    if(pos<=0)
        return INT32_MIN;
    Node *p = top;
    for(int i = 0; p && i<pos-1; i++)
        p = p->next;
    if(!p)
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

bool parenthesisMatching(string exp){
    Stack st;
    int len = exp.length();
    for(int i = 0; i<len; i++){
        if(exp[i] == '(')
            st.push(exp[i]);
        else if(exp[i] == ')'){
            if(st.isEmpty())
                return false;
            st.pop();    
        }
    }
    if(st.isEmpty())
        return true;
    return false;
}

bool parenthesisMatch(string exp){
    Stack st;
    int len = exp.length();
    for(int i = 0; i<len; i++){
        char ch = exp[i];
        if(ch == '(' || ch == '[' || ch == '{')
            st.push(exp[i]);
        else if(ch == ')' || ch == ']' || ch == '}'){
            if(st.isEmpty())
                return false;
            char p = st.pop();
            if(p == 40){ 
                if(ch-p != 1)
                    return false;
            }
            else{
                if(ch-p != 2)
                    return false;
            }
        }
    }
    return st.isEmpty();
}

int main(){
    // Stack st;
    // st.push(0);
    // st.push(5);
    // st.push(10);
    // st.push(18);
    // st.push(45);

    // st.display();
    // cout << "Popped: " << st.pop() << endl;
    // cout << "Popped: " << st.pop() << endl;
    // cout << "Peek at pos 2: " << st.peek(2) << endl;
    // cout << "Top Element: " << st.findTop() << endl;
    // cout << "Is Empty: " << st.isEmpty() << endl;
    // cout << "Is Full: " << st.isFull() << endl;
    string exp = "{[((a*b)+(c-d))]";
    cout<<"Parenthesis Matching : "<<parenthesisMatch(exp)<<endl;
    return 0;
}