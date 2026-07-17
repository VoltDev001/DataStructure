#include<stdio.h>

struct Stack{
    int size;
    int top;
    int *p;
};

int main(){
    struct Stack st;
    printf("Enter size of stack: \n");
    scanf("%d", &st.size);
    st.p = new int[st.size];
    st.top = -1;
    return 0;
}