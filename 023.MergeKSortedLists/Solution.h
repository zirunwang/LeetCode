/**
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        
        while(lists.size() > 1) {
            int n = lists.size();
            //megerTwo [n/2, n/2 + 1)
            vector<ListNode*> newLists;
            newLists.reserve(n);
            int i = 0;
            while(i < n / 2 * 2 - 1){
                newLists.push_back(mergeTwo(lists[i], lists[i + 1]));
                i += 2;
            }
            if(n % 2) newLists.push_back(lists.back());
            swap(lists, newLists);
        }
        return lists.front();
    }
    ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        if(l1->val > l2->val) {
            l2->next = mergeTwo(l1, l2->next);
            return l2;
        }
        else {
            l1->next = mergeTwo(l1->next, l2);
            return l1;
        }
    }
};