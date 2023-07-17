#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
        printf("Pushed item: %d\n", item);
    }
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int item = stack[top--];
        printf("Popped item: %d\n", item);
        return item;
    }
}

int peek() {
    if (top < 0) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

int isEmpty() {
    return (top < 0);
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", peek());
    printf("Popped element: %d\n", pop());
    printf("Top element: %d\n", peek());

    return 0;
}
