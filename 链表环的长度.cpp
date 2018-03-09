ListNode *is_cycle(ListNode *head) {
    ListNode *p = head, *q = head->next->next;
    while (q && q->next) {
        if (p == q) return p;
        p = p->next;
        q = q->next->next;
    }
    return NULL;
}

int linkedListCycleLength(ListNode *head) {
    ListNode *p = is_cycle(head);
    if (p) {
        ListNode *q = p->next->next;
        int cnt = 1;
        while (p != q) {
            ++cnt;
            p = p->next;
            q = q->next->next;
        }
        return cnt + 1;
    } else {
        return 0;
    }
}