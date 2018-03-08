/*************************************************************************
	> File Name: test57.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月17日 星期三 12时49分45秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERROR 0
#define OK 1

typedef struct Stack {
    int top, size;
    int *data;
} Stack;

void init(Stack *s, int n) {
    s->size = n;
    s->data = (int *)malloc(sizeof(int));
    s->top = -1;
}

int push(Stack *s, int value) {
    if (s->top == s->size) return 0;
    s->top++;
    s->data[s->top] = value;
    return 1;
}

int pop(Stack *s) {
    if (s->top == -1) return 0;
    s->top--;
    return 1;
}

int top(Stack *s) {
    //if (s->top == -1) return 0;
    return s->data[s->top];
}

int empty(Stack *s) {
        if (s->top < 0) {
        return 1;
    } else {
        return 0;
    }
}

int precede(char a, char b) {
    if ((a == '*' || a == '/') && (b == '+' || b == '-')) {
        return 1;
    } else {
        return 0;
    }
}
int operate(int a, int b, char c) {
    switch (c) {
        case '*': return a * b; break;
        case '/': return a / b; break;  
        case '+': return a + b; break;
        case '-': return a - b; break;
    }
}
void calc(Stack *op, Stack *num) {
    int a = top(num);
    pop(num);
    int b = top(num);
    pop(num);
    push(num, operate(a, b, top(op)));
    pop(op);
}

void clear(Stack *s) {
    free(s->data);
    free(s);
}

int main() {
    int n;
    scanf("%d", &n);
    Stack *numbers = (Stack *)malloc(sizeof(Stack));
    init(numbers, n);
    Stack *op = (Stack *)malloc(sizeof(Stack));
    init(op, n);
    char *buffer = (char *)malloc(sizeof(char) * (n + 1));
    scanf("%s", buffer);
    int i = 0;
    while (i < n) {
        if (isdigit(buffer[i])) {
            push(numbers, buffer[i] - '0');
            i++;
        } else {
            if (empty(op) || precede(buffer[i], top(op))) {
                push(op, buffer[i]);
                i++;
            } else {
                calc(numbers, op);
            }
        }
        printf("%c\n", top(op));
        //printf("lalal\n");
    }
    while (!empty(op)) {
        calc(numbers, op);
        printf("aaaa\n");
    }
    printf("%d\n", top(numbers));
    clear(numbers);
    clear(op);
    free(buffer);
    return 0;
}
