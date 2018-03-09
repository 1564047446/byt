ListNode* twoWayLinkListUnique(ListNode *head) {
    ListNode *p = head, *q, *del;
    while (p) {
        q = p, del = p->next;
        while (q->next && del) {
            int flag = 0;
            if (p->val == del->val) {
                if (del->next == NULL) {
                    q->next = NULL;
                    break;
                }
                q->next = del->next;
                del->next->pre = q;
                flag = 1;
            }
            if (flag) {
                del = q->next;
            } else {
                q = q->next;
                del = q->next;
            }
        }
        p = p->next;
    }
    return head;
}