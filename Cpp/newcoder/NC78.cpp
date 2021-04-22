/**
 * 反转链表
 *
 * 个人评价：【简单】
 * 主要考察对链表的理解、使用指针对节点进行链接的操作
 */

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        // 非法输入检查
        if (pHead == NULL)
            return NULL;
        if (pHead->next == NULL)
            return pHead;

        // 借助 3 个指针变量反转链表
        ListNode *p1 = NULL;
        ListNode *p2 = pHead;
        ListNode *p3 = p2->next;
        while (p3) {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        p2->next = p1;
        return p2;
    }
};