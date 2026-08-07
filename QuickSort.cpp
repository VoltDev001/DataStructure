#include<iostream>
using namespace std;

int a[9] = {1,2,3,4,5,6,7,8,9};

void swapValues(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int findProperPlace(int up, int down, int pivot){
    while(up < down){
        while(a[up] < pivot){
            up++;
            if(up > down)
                break;
        }
        while(a[down] > pivot){
            down--;
            if(up > down)
                break;
        }
        if(up > down)
            break;
        swapValues(&a[up], &a[down]);
        up++;
        down--;
    }
    return down;
}

void quickSort(int start, int end){
    if(start >= end)
        return;
    int pivot = a[start];
    int pivotplace = findProperPlace(start+1, end, pivot);
    swapValues(&a[start], &a[pivotplace]);
    quickSort(start, pivotplace-1);
    quickSort(pivotplace+1, end);
}

int main(){
    quickSort(0,8);
    for(int i=0; i<9; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}