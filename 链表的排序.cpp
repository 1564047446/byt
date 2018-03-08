ListNode* linkedListSort(ListNode *head) {
    ListNode *p, *end = NULL;
    while (end != head) {
        p = head;
        while (p->next != end) {
            if (p->val > p->next->val) {
                p->val ^= p->next->val;
                p->next->val ^= p->val;
                p->val ^= p->next->val;
            }
            p = p->next;
        }
        end = p;
    }
    return head;
}