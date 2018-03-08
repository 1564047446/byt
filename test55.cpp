/*************************************************************************
	> File Name: test55.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月17日 星期三 10时55分44秒
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define init(T, n) (__init(sizeof(T), 10))
#define push(q, value) (__push(q, &value))
#define front(T, q) (* (T *)__front(q))

typedef struct Queue {
    int length, data_size, head, tail;
    void *data;
} Queue;

Queue *__init(int data_size, int length = 10) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = malloc(data_size * length);
    q->head = 0, q->tail = 0, q->length = length, q->data_size = data_size;
}

int __push(Queue *q, void *value) {
    char *data = (char *)(q->data);
    q->data = memcpy(data + q->tail * q->data_size, value, q->data_size);
    q->tail++;
    return 1;
}

int pop(Queue *q) {
    q->head++;
    return 1;
}


int clear(Queue *q) {
    free(q->data);
    free(q);
    return 1;
}

void *__front(Queue *q) {
    return (char *)(q->data) + q->data_size * q->head;
}

int main() {
    int op, value;
    Queue *q = init(int, 10);
    while (~scanf("%d", &op)) {
        switch (op) {
            case 1:{
                scanf("%d", &value);
                push(q, value);
                break;
            }
            case 2: {
                pop(q);
                break;
            }
        }
        int temp = front(int, q);
        printf("%d\n", temp);
    }
}
