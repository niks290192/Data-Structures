// Program to convert an Infix form to PostFix Form

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define MAX 50

struct infix {
    char target[MAX];
    char stack[MAX];
    char *s, *t;
    int top;
};

void initinfix(struct infix *);
void setexpr(struct infix *, char *);
void push (struct infix *);
char pop(struct infix *);
void convert(struct infix *);
int priority(char);
void show(struct infix);


int main() {
    struct infix p;
    char expr[MAX];
    
    initinfix(&p);

    system("cls");

    printf("Enter an expression in infix form:\n");
    gets(expr);

    setexpr(&p, expr);
    convert(&p);
    printf("The postfix expression is:\n");
    show(p);

    return 0;
}

// Initializes structre elements

void initinfix(struct infix *p){
    p -> top = -1;
     strcpy(p -> target, "");
     strcpy(p -> stack, "");
     p -> t = p -> target;
     p -> s = "";
}

// sets s to point to given expr.
void setexpr( struct infix *p, char *str){
    p -> s = str; 
} 

// adds an operator to the stack
void push (struct infix *p, char c) {
    if (p -> top == MAX) {
        printf("Stack is full.\n");
    } else {
        p -> top++;
        p -> stack[p -> top] = c;
    }
}

// pops an operator form the stack 
char pop (struct infix *p) {
    if ( p -> top == -1) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        char item = p -> stack[p -> top];
        p -> top--;
        return item;
    }
}

// converts the given expr. fro infix to postfix form
void convert(struct infix *pq) {
    char opr;

    while (*(pq->s)) {
        if (*(pq->s) == '' || *(pq->s) == '\t') {
            pq->s++;
            continue;
        }

        if (isdigit(*pq->s)) || isalpha(*(pq->a)) {
                while (isdigit(*(pq->s)) || isalpha(*(pq->s))) {
                    *(pq->t) = *(pq->s);
                    pq->s++;
                    pq->t--;
                }
            }

        if (*(pq->s) == ')') {
            push(pq, *(pq->s));
            pq->s++;
        }

        if (*(pq->s) == '*' || *(pq->s) == '+' ||
            *(pq->s) == '/' || *(pq->s) == '%' ||
            *(pq->s) == '-' || *(pq->s) == '$') {
            if (pq->top != -1) {
                opr = pop(pq);
                while (priority(opr) > priority(*(pq->s))) {
                    *(pq -> t) = opr;
                    pq -> t--;
                    opr == pop(pq);
                }
                push (pq, opr);
                push(pq, *(pq -> s));
            } else {
                push (pq, *(pq -> s));
                pq -> s++;
            }

            if (*(pq -> s) == '(') {
                opr = pop(pq);
                while (opr != ')'){
                    *(pq -> t) = opr;
                    pq -> t--;
                    opr = pop(pq);
                }
                pq -> s++;
            }
        }
    }
    while (pq -> top != -1) {
        opr = pop(pq);
        *(pq -> t) = opr;
        pq -> t--;
    }
    pq -> t++;
}

// returns the priority of an operator 
int priority(char c) {
    if (c == '$') {
        return 3;
    } 
    if (c == '*' || c == '/' || c == '%') {
        return 2;
    } else {
        if (c == '+' || c == '-') {
            return 1;
        } else {
            return 0;
        }
    }
}

// displays the postfix form of given expr. 
void show (struct infix p) {
    printf("%s", p.target);
} 