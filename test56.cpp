/*************************************************************************
	> File Name: test56.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月17日 星期三 11时36分07秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define init(T, n) (__init(sizeof(T), 10))
#define push(q, value) ((__push(q, &value)))
#define front(T, q) (*(T *)(__front(q)))

typedef struct Queue {
    void *data;
    int length, head, tail, data_size;
} Queue;

Queue *__init(int data_size, int length = 10) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = malloc(data_size * length);
    q->head = 0;
    q->tail = 0;
    q->length = length;
    q->data_size = data_size;
}

int __push(Queue *q, void *value) {
    if (q->tail >= q->length) return 0;
    char *data = (char *)(q->data);
    //q->data = 
    memcpy(data + q->data_size * q->tail, value, q->data_size);
    q->tail++;
    return 1;
}

int pop(Queue *q) {
    if (q->head == q->tail) {
        return 0;
    }
    q->head++;
    return 1;
}

void *__front(Queue *q) {
    if (q->head == q->tail) return 0;
    char *data = (char *)(q->data);
    return data + q->data_size * q->head;
}

int main() {
    int op, value;
    Queue *q = init(int, 10);
    while (~scanf("%d", &op)) {
        if (op == 1) {
            scanf("%d", &value);
            push(q, value);
        } 
        else if (op == 2) {
            pop(q);
        }
        int temp = front(int, q);
        printf("%d\n", temp);
    }
    return 0;
}
