/*************************************************************************
	> File Name: test62.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月17日 星期三 16时09分14秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Stack {
    int *data;
    int top, size;
} Stack;

void init(Stack *s, int n) {
    s->data = (int *)malloc(sizeof(int) * n);
    s->top = -1;
    s->size = n;
}

int push(Stack *s, int value) {
    s->data[++s->top] = value;
    return 1;
}

int pop(Stack *s) {
    s->top--;
    return 1;
}

int empty(Stack *s) {
    if (s->top == 1) return 1;
    else return 0;
}

int main() {
    char p[22];
    scanf("%s", p);
    Stack *s = (Stack *)malloc(sizeof(Stack));
    init(s, 22);
    int len = strlen(p) - 1;
    for (int i = 0; i < len / 2; i++) {
        push(s, p[i]);
    }
    int flag = 1;
    if (len % 2 == 0) {
        for (int i = len / 2; i <= len - 1; i++) {
            if (s->data[s->top] == p[i]) {
                pop(s);
                continue;
            }
            else {
                flag = 0;
                break;
            }
        }
    } else {
        for (int i = len / 2 + 1; i <= len - 1; i++) {
            if (s->data[s->top] == p[i]) {
                pop(s);
                continue;
            } else {
                flag = 0;
                break;
            }
        }
    }
    if (flag) printf("true\n");
    else printf("false\n");
}
