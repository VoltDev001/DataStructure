#include<iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int *s;
};

void createStack(Stack *st){
    cout<<"Enter size of stack :";
    cin>>st->size;
    st->s = new int[st->size];
    st->top = -1;
}

void display(Stack st){
    if(st.top < 0)
        cout<<"Stack is empty."<<endl;
    else{
        for(int i = st.top; i>=0; i--)
            cout<<st.s[i]<<" ";
        cout<<endl;
    }
}

void push(Stack *st, int num){
    if(st->top == (st->size-1))
        cout<<"Stack Overflow."<<endl;
    else
        st->s[++st->top] = num;
}

int pop(Stack *st){
    if(st->top == -1)
        return INT16_MIN;
    int x = st->s[st->top--];
    return x;
}

int peek(Stack st, int index){
    int pos = st.top-index+1;
    if(pos<0)
        return INT16_MIN;
    return st.s[pos];
}

int findTop(Stack st){
    return st.top;
}

int isFull(Stack st){
    return st.top == st.size-1;
}

int isEmpty(Stack st){
    return st.top == -1;
}

int main(){
    Stack st;
    createStack(&st);
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    push(&st, 5);
    // push(&st, 6);
    // cout<<"Popped Value : "<<pop(&st)<<endl;
    // cout<<"Popped Value : "<<pop(&st)<<endl;
    // cout<<"Popped Value : "<<pop(&st)<<endl;
    // cout<<"Popped Value : "<<pop(&st)<<endl;
    // cout<<"Popped Value : "<<pop(&st)<<endl;
    // cout<<"Popped Value : "<<pop(&st)<<endl;
    // cout<<"Element is : "<<peek(st, 7)<<endl;
    // cout<<isEmpty(st)<<endl;
    // cout<<isFull(st)<<endl;
    cout<<findTop(st)<<endl;
    display(st);
    return 0;
}