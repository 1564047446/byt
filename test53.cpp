//24
struct ListNode *swap(struct ListNode *head)

{
	struct ListNode ret;
	ret.next = head;
	struct ListNode *p, *q;
	p = &ret, q = head;
	while (p->next && q->next) {
		
		p->next = q->next;
		q->next = p->next->next;
		p->next->next = q;
		p = q;
		q = q->next;	
	}
	
	return ret.next;
	
}



#define likely(x) __builtin_expect(!!(x), 1)
#define ulikely(x) __builtin_expect(!!(x), 0)    帮助cpu进行分支预测

//likely 表示x经常成立

__builin_popcount(x): x 中 1 的个数 //掌握面试主导权
