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
    ListNode* removeNodes(ListNode* head) {
        ListNode* tmp = head;
        stack<int> s;
        int val = 0;
        while (tmp) {
            s.push(tmp->val);
            tmp = tmp->next;
        }
        ListNode* ans = nullptr;
        while (s.size()) {
            if (s.top() >= val) {
                tmp = ans;
                ans = new ListNode(s.top());
                ans->next = tmp;
                val = s.top();
            }
            s.pop();
        }
        return ans;
    }
};