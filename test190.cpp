/*************************************************************************
	> File Name: test190.cpp
	> Author:  byt 
	> Mail: baotongyu1995@163.com
	> Created Time: 2018年05月17日 星期四 16时54分32秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Node {
public:
    Node() {}
    int data;
    Node *next;
};

class LinkedList {
public:
    LinkedList() {
        head = NULL;
    }
    Node *insert(int value);
    void show();
    ~LinkedList() {
        Node *node = head;
        while (node) {
            Node *delete_node;
            node = node->next;
        }
    }
private:
    Node *head;
};

void LinkedList::show() {
    Node *node = head;
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
    return ;
}

Node *get_node(int value) {
    Node *node = new Node;
    node->data = value, node->next = NULL;
    return node;
}

Node* LinkedList::insert(int value) {
    Node *node = get_node(value);
    node->next = NULL;
    if (head == NULL) {
        head = node;
        return head;
    }
    Node *current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = node;
    return head;
}

int main() {
    LinkedList head;
    int op;
    while (cin >> op) {
        if (op) {
            head.insert(op);
        } else {
            head.show();
        }
    }
    return 0;
}
