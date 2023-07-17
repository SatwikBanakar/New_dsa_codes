#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define STACK_FILE "stack.txt"
#define STACKLOG_FILE "stacklog.txt"
#define PUSHLOG_FILE "pushlog.txt"
#define POPLOG_FILE "poplog.txt"
#define OPERATIONLOG_FILE "operationlog.txt"

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

int isStackFull(Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack *stack, int item) {
    if (isStackFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = item;
}

int pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

void printStack(Stack *stack) {
    int i;
    printf("Stack contents: ");
    for (i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

void logStack(Stack *stack) {
    int i;
    FILE *f = fopen(STACKLOG_FILE, "a");
    fprintf(f, "Stack contents: ");
    for (i = 0; i <= stack->top; i++) {
        fprintf(f, "%d ", stack->data[i]);
    }
    fprintf(f, "\n");
    fclose(f);
}

void logPush(int item) {
    FILE *f = fopen(PUSHLOG_FILE, "a");
    fprintf(f, "Pushed %d\n", item);
    fclose(f);
}

void logPop(int item) {
    FILE *f = fopen(POPLOG_FILE, "a");
    fprintf(f, "Popped %d\n", item);
    fclose(f);
}

void logOperation(char *operation) {
    FILE *f = fopen(OPERATIONLOG_FILE, "a");
    fprintf(f, "%s\n", operation);
    fclose(f);
}

int main() {

    Stack stack;
    initStack(&stack);
    FILE *f = fopen(STACKLOG_FILE, "w");
    fclose(f);

    int item, choice;
    char operation[20];
    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print stack\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(&stack, item);
                logPush(item);
                sprintf(operation, "Pushed %d", item);
                logOperation(operation);
                logStack(&stack);
                break;
            case 2:
                item = pop
                            (&stack);
            if (item != -1) {
                printf("Popped item: %d\n", item);
                logPop(item);
                sprintf(operation, "Popped %d", item);
                logOperation(operation);
            }
            logStack(&stack);
            break;
        case 3:
            printStack(&stack);
            break;
        case 4:
            printf("Quitting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
} while (choice != 4);

return 0;
}
