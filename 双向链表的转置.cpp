ListNode* reverseLinkedList(ListNode *head) {
    ListNode *p, *q = head->next;
    if (q == NULL) return head;
    head->next = NULL;
    head->pre = q;
    p = q->next;
    q->next = head;
    head = q;
    while (p) {
        q = p;
        p = q->next;
        q->next = head;
        head->pre = q;
        head = q;
    }
    return head;
}