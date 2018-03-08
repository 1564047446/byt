/*************************************************************************
	> File Name: test50.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月12日 星期五 15时33分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node, *Linkedlist;

Node *get_node(char value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

Linkedlist insert(Linkedlist head, char value, int index) {
    Node ret, *node;
    ret.next = head;
    node = &ret;
    while (node != NULL && index != 0) {
        node = node->next;
        index--;
    }
    if (node == NULL) return head;
    Node *new_node = get_node(value);
    new_node->next = node->next;
    node->next = new_node;
    return ret.next;
}

Linkedlist reverse(Linkedlist head) {
    Node *current_node = head->next;
    head->next = NULL;
    while (current_node != NULL) {
        Node *next_node = current_node->next;
        current_node->next = head;
        head = current_node;
        current_node = next_node;
    }
    return head;
}

void print(Linkedlist head) {
    int num = 0;
    Node *node = head;
    while (node != NULL) {
        if (num == 0) {
            printf("%c", node->data);
        } else {
            printf(" %c", node->data);
        }
        node = node->next;
        num++;
    }
    printf("\n");
}

void clear(Linkedlist head) {
    Node *node = head;
    while (node != NULL) {
        Node *delet_node = node;
        node = node->next;
        free(delet_node);
    }
    return ;
}

int main() {
    int n;
    Linkedlist head = NULL;
    scanf("%d\n", &n);
    int c;
    for (int i = 0; i < n; i++) {
        char k;
        if (i != n - 1) scanf("%c ", &k);
        else scanf("%c", &k);
        head = insert(head, k, i);
        //getchar();
        //head = insert(head, c, i);
    }
    //print(head);
    if (n == 0) {
        printf("\n");
    } else {
        
        head = reverse(head);
        print(head);
    }
    clear(head);
    return 0;
}
