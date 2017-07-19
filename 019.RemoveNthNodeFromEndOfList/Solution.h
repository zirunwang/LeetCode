/**
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        ListNode newHead(-1);
        newHead.next = head;
        ListNode *p1 = &newHead, *p2 = &newHead;
        for(int i = 0; i < n; ++i) {
            p1 = p1->next;
        }
        while(p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode* toDelete = p2->next;
        p2->next = p2->next->next;
        delete toDelete;
        return newHead.next;
    }
};