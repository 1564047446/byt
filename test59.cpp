/*************************************************************************
	> File Name: test59.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月17日 星期三 14时34分06秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long long s;
} Node;

typedef struct Queue {
    Node *data;
    int head, tail, length;
}Queue;

void init(Queue *q, int n) {
    q->data = (Node *)malloc(sizeof(Node) * n);
    q->head = 0;
    q->tail = 0;
    q->length = n;
}

int push(Queue *q, Node node) {
    q->data[q->tail] = node;
    q->tail++;
    return 1;
}

int pop(Queue *q) {
    q->head++;
    return 1;
}

void clear(Queue *q) {
    free(q->data);
    free(q);

}

int empty(Queue *q) {
    if (q->tail == q->head) return 1;
    else return 0;
}

int main() {
    int n = 10;
    Queue *q0 = (Queue *)malloc(sizeof(Queue)), *q1 = (Queue *)malloc(sizeof(Queue)), *q2 = (Queue *)malloc(sizeof(Queue));
    init(q0, 10), init(q1, 10), init(q2, 10);
    while (n--) {
        int k;
        scanf("%d", &k);
        //Node temp;
        switch (k) {
            Node temp;
            case 0: {
                scanf("%lld\n", &temp.s);
                push(q0, temp);
                break;
            }
            case 1: {
                scanf("%lld\n", &temp.s);
                push(q1, temp);
                break;
            }
            case 2: {
                scanf("%lld\n", &temp.s);
                push(q2, temp);
                break;
            }
        }
    }
    int p = 10;
    while (p--) {
        if (!empty(q0)) {
            printf("%lld ", q0->data[q0->head].s);
            //free(q0->data[q0->head]);
            pop(q0);
        } else {
            printf("0 ");
        }
        if (!empty(q1)) {
            printf("%lld ", q1->data[q1->head].s);
            pop(q1);
        } else {
            printf("0 ");
        }
        if (!empty(q2)) {
            printf("%lld\n", q2->data[q2->head].s);
            pop(q2);
        } else {
            printf("0\n");
        }
    }
}
