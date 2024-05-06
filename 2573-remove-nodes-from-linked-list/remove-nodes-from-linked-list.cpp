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
        vector<int> v;
        ListNode* tmp = head;
        while (tmp) {
            v.push_back(tmp->val);
            tmp = tmp->next;
        }
        stack<int> s;
        int val = 0;
        for (int i = v.size()-1; i >= 0; --i) {
            if (v[i] >= val) {
                s.push(v[i]);
                val = v[i];
            }
        }
        ListNode* par;
        bool isHead = false;
        while (s.size()) {
            if (s.top() != head->val && !isHead) {
                ListNode* t = head;
                head = head->next;
                delete t;
            }
            else if (s.top() == head->val && !isHead) {
                s.pop();
                tmp = head->next;
                par = head;
                isHead = true;
            }
            else if (s.top() != tmp->val) {
                ListNode* t = tmp;
                par->next = tmp->next;
                tmp = par->next;
                delete t;
            }
            else if (s.top() == tmp->val) {
                s.pop();
                par = tmp;
                tmp = tmp->next;
            }
        }
        return head;
    }
};