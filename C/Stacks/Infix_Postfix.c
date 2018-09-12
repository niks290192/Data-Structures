#include <stdio.h>
#include <stdlib.h> 

struct operator {
    char opName;
    int isp;
    int icp;
};

int push(struct operator stak[], int *top, struct operator val, int size);
struct operator pop (struct operator stack[], int *top);
void display(struct operator stack[], int pop);
int match(struct operator opTab[8], char element, struct operator *op);

void main() {
    char infix[20];
    char target[20];

    struct operator stack[20];
    int top = -1;
    int res;
    char val;
    int size;
    int pos;
    int i;
    struct operator op, opTemp;
    struct operator opTab[8] = {'(',0,6,')',0,0,'^',4,5,'*',3,3,'/',3,3,'+',2,2,'-',2,2,';',0,-1};
    printf("\n Enter the size of the infix expression");
    scanf("%d",&size); size--;
    for(i=0;i<=size;i++) {
        fflush(stdin);
        scanf("%c", &infix[i]);
    }
    pos = 0;

    for(i=0;i<=size;i++) {
        res = match(opTab, infix[i], &op);
        if (res == 0) {
            target[pos] = infix[i];
            pos++;
        } else {
            if (top < 0) {
                push(stack, &top, op, size);
            } else {
                opTemp.opName = "#";
                if (op.opName == ')') {
                    while (opTemp.opName != '('){
                        opTemp = pop(stack,&top);
                        if (opTemp.opName != '(') {
                            target[pos] = opTemp.opName;
                            pos++;
                        }
                    }
                } else {
                    while(stack[top].isp >= op.icp && top >= 0) {
                        opTemp = pop(stack, &top);
                        target[pos] = opTemp.opName;
                        pos++;
                    }
                    push(stack,&top,op,size);
                }
            }
        }
    }
    printf("\n The postfix expression is: ");
    for(i=0;i<pos;i++) {
        printf("%c",target[i]);
    }
}

int push(struct operator stack[], int *top, struct operator val, int size) {
    if(*top >= size) {
        return 0;
    } else {
        *top = *top + 1;
        stack[*top] = val;
        return 1;
    }
}

struct operator pop(struct operator stack[], int *top) {
    struct operator val;
    if (*top < 0) {
        val.opName = '#';
        return val;
    } else {
        val = stack[*top];
        *top = *top - 1;
        return val;
    }
}

void display(struct operator stack[], int top) {
    int i;
    printf("\n The contents of stacks are: ");
    for(i=top;i>=0;i--){
        printf("%c", stack[i].opName);
    }
}

int match(struct operator opTab[8], char element, struct operator *op) {
    int i;
    for(i=0;i<8;i++) {
        if(opTab[i].opName == element){
            *op = opTab[i];
            return 1;
        }
    }
    return 0;
}