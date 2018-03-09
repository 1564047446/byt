ListNode* findIntersectionListNode(ListNode *head1, ListNode *head2) {
    ListNode *p, *q;
    while (head1) {
        p = head1, q = head2;
        while (q) {
            if (p == q) return p;
            q = q->next;
        }
        head1 = head1->next;
    }
    return NULL;
}