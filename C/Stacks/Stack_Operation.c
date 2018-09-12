#include <stdio.h>
#include <stdlib.h>

int push(int stak[], int *top, int val, int size);
int pop(int stak[],int *top);
void display(int stack[], int top);

void main(){
    int stack[20];
    int top = -1;

    int val;
    int size;
    int choice;
    int result;

    printf("Enter the size of the stack");
    scanf("%d", &size);
    size--;

    do {
        printf(" \n Menu - Stack Operations");
        printf("\n Push - 1");
        printf("\n Pop - 2");
        printf("\n Display - 3");
        printf("\n Quit - 4");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter a value to be pushed");
                    scanf("%d",&val);
                    result = push(stack, &top, val, size);
                    if(result == 0) {
                        printf("\n The Stack is Full");
                        break;
                    }
            case 2: result = pop(stack, &top);
                    if (result == 9999) {
                        printf("\n Stack is Empty");
                    } else {
                        printf("\n The poped value = %d", result);            
                    }
                    break;
            case 3: display(stack,top);
            break;

        }
        printf("\n \n Press any key to continue");

    } while(choice != 4);
}

int push(int stack[], int *top, int val, int size) {
    if (*top >= size) {
        return 0;
    } else {
        *top = *top + 1;
        stack[*top] = val;
        return 1;
    }
}

int pop(int stack[], int *top) {
    int val;
    if(*top<0) {
        return 9999;
    } else {
        val = stack[*top];
        *top = *top -1;
        return val;
    }
}

void display(int stack[], int top) {
    int i;
    printf("\n The contents of the stack are: ");
    for(i = top; i >= 0; i--) {
        printf("%d", stack[i]);
    }
}