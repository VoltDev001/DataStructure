#include<iostream>
using namespace std;

struct Stack{
    int data;
    Stack* next;
}*stack1 = nullptr, *stack2 = nullptr;

void push(Stack* &top, int n){
    Stack *t = new Stack();
    if(!t)
        return;
    t->data = n;
    t->next = top;
    top = t;
}

void display(Stack* top){
    if(!top)
        return;
    while(top){
        cout<<top->data<<" ";
        top = top->next;
    }
    cout<<endl;
}

int pop(Stack* &f){
    if(!f)
        return -1;
    Stack *t = f;
    int d = t->data;
    f = f->next;
    delete t;
    return d;
}

int isEmpty(Stack* f){
    if(!f)
        return 1;
    return 0;
}

void insertQueue(int num){
    push(stack1, num);
}

void deleteQueue(){
    if(isEmpty(stack2)){
        if(isEmpty(stack1)){
            cout<<"Queue is Empty."<<endl;
            return;
        }
        else{
            while(!isEmpty(stack1)){
                push(stack2, pop(stack1));
            }
        }
    }
    cout<<"Deleted Data : "<<pop(stack2)<<endl;
}

int main(){
    insertQueue(0);
    insertQueue(4);
    insertQueue(9);
    insertQueue(8);
    deleteQueue();
    deleteQueue();
    insertQueue(89);
    insertQueue(90);
    deleteQueue();
    display(stack1);
    display(stack2);
    return 0;
}