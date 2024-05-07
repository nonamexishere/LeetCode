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
        ListNode* tmp = head;
        bool addOne = false;
        if (head->val >= 5) addOne = 1;
        while (tmp) {
            tmp->val *= 2;
            tmp->val %= 10;
            if (tmp->next) {
                tmp->val += ((tmp->next->val * 2) / 10);
            }
            tmp = tmp->next;
        }
        if (addOne) {
            tmp = new ListNode(1);
            tmp->next = head;
        }
        else tmp = head;
        
        return tmp;
    }
};