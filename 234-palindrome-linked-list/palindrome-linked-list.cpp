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
    bool isPalindrome(ListNode* head) {
        ListNode* tmp = head;
        vector<int> v;
        while (tmp) {
            v.emplace_back(tmp->val);
            tmp = tmp->next;
        }
        int size = v.size();
        for (int i = 0; i < size / 2; ++i) {
            if (v[i] != v[size - 1 - i]) return false;
        }
        return true;
    }
};