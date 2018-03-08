bool isLinkedListCycle(ListNode *head) {
    if (head == NULL) return false;
    ListNode *p = head, *q = head->next->next;
    while (q && q->next) {
        if (p == q) return true;
        p = p->next;
        q = q->next->next;
    }
    return false;
}