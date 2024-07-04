/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ansh = new ListNode;
        ListNode* tmp1 = ansh;   
        ListNode* tmp = head->next;
        int i = 0;
        while (tmp) {
            i += tmp->val;
            if (tmp->val == 0) {
                tmp1->val = i;
                if (tmp->next)
                    tmp1->next = new ListNode;
                tmp1 = tmp1->next;
                i = 0;
            }
            tmp = tmp->next;
        }
        return ansh;
    }
};