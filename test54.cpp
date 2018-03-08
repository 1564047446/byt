/*************************************************************************
	> File Name: test54.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月15日 星期一 11时38分28秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node, *LinkedList;

Node *get_node(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

LinkedList insert(LinkedList head, int value, int index) {
    Node *node, virtual_head;
    virtual_head.next = head;
    node = &virtual_head;
    while (index != 0 && node != NULL) {
        index--, node = node->next;
    }
    Node *new_node = get_node(value);
    new_node->next = node->next;
    node->next = new_node;
    return virtual_head.next;
}

LinkedList delete_node(LinkedList head, int index) {
    Node *node, virtual_head;
    virtual_head.next = head;
    node = &virtual_head;
    while (index != 0 && node != NULL) {
        index--, node = node->next;
    }
    Node *old_node = node->next;
    node->next = node->next->next;
    free(old_node);
    return virtual_head.next;
}

LinkedList reverse(LinkedList head) {
    Node *current = head->next;
    head->next = NULL;
    while (current != NULL) {
        Node *next_node = current->next;
        current->next = head;
        head = current;
        current = next_node;
    }
    return head;
}


void output(LinkedList head) {
    printf("[ ");
    Node *node = head;
    while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
    printf("]\n");
}


int main() {
    LinkedList head = NULL;
    int n;
    while (~scanf("%d", &n)) {
        switch (n) {
            case 1: {
                int value, index;
                scanf("%d%d", &value, &index);
                head = insert(head, value, index);
                break;
            }
            case 2: {
                int index;
                scanf("%d", &index);
                head = delete_node(head, index);
                break;
            }
            default: {
                break;
            }
        }
        output(head);
    }
    head = reverse(head);
    output(head);
    return 0;

}
