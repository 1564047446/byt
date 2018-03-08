LinkedList insert_circle(LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
            return head;
        }
        head = node;
        head->next = head;
        return head;
    }
    if (index == 0) {
        node->next = head->next;
        head->next = node;
        return head;
    }
    Node *current_node = head->next;
    int count = 0;
    while (count < index - 1 && current_node != head) {
        current_node = current_node->next;
        count++;
    }
    if (index - 1 == count) {
        node->next = current_node->next;
        current_node->next = node;
    }
    if (node == head) {
        head = node;
    }
    return head;
}