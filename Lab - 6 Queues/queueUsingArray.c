#include<stdio.h>
int queue[100];
int front = -1;
int end = -1;

int isFull(){
    if (end == 99)
    {
        return 1;
    }
    return 0;
}
int isEmpty(){
    if (front == end && front == -1)
    {
        return 1;
    }
    return 0;
}
void enque(int value){
    if (!isFull())
    {
        if (front == -1)
        {
            front++;
        }
        queue[++end] = value;
    }
}

int deque(){
    front++;  
}

int main(){
    enque(5);
    enque(15);
    enque(25);

    printf("%d", deque());
}