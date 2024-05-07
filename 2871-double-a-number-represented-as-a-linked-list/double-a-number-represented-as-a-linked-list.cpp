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
    ListNode* doubleIt(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode* tmp = head;
        if (head->val > 4) {
            tmp = new ListNode(1);
            tmp->next = head;
            head = tmp;
            tmp = tmp->next;
        }
        while (tmp->next) {
            tmp->val <<= 1;
            tmp->val %= 10;
            if (tmp->next->val > 4) tmp->val++;
            tmp = tmp->next;
        }
        tmp->val <<= 1;
        tmp->val %= 10;
        return head;
    }
};