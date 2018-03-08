ListNode* linkedListUnique(ListNode *head) {
    if (head == NULL) return NULL;
    ListNode *now, *next;
    now = head, next = head->next;
    while (next) {
        if (next->val != now->val) {
            now = next;
            next = next->next;
        } else {
            now->next = next->next;
            next = now->next;
        }
    }
    return head;
}