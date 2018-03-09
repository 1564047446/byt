struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p, *q, ret;
    ret.next = head;
    p = &ret;
    q = head;
    while (q->next != NULL && p->next != NULL) {
        p->next = q->next;
        q->next = q->next->next;
        p->next->next = q;
        p = q;
        q = q->next;
    }     
    return ret.next;
}