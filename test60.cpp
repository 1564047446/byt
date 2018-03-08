/*************************************************************************
	> File Name: test60.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月17日 星期三 15时21分14秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top, size;
    int *data;
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
    if (s->top == -1) return 1;
    else return 0;
}

int top(Stack *s) {
    return s->data[s->top];
}

int main() {
    int n;
    Stack *s = (Stack *)malloc(sizeof(Stack));
    scanf("%d", &n);
    init(s, n);
    int flag = 1;
    int num = 0;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        while (empty(s) || top(s) < value) {
            push(s, num);
            num++;
        }
        if (top(s) == value) {
            pop(s);
        } else {
            flag = 0;
            break;
        }
    }
    if (flag) printf("YES\n");
    else printf("NO\n");
}
