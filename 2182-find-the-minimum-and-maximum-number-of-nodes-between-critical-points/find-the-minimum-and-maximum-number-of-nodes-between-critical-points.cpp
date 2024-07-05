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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> c;
        ListNode* tmp = head->next;
        int prev = head->val;
        int i = 0;
        while (tmp->next) {
            if ((prev > tmp->val && tmp->next->val > tmp->val) || (prev < tmp->val && tmp->next->val < tmp->val)) c.push_back(i);
            i++;
            prev = tmp->val;
            tmp = tmp->next; 
        }
        if (c.size() < 2) {
            vector<int> ans(2);
            ans[0] = ans[1] = -1;
            return ans;
        }
        vector<int> ans(2);
        ans[1] = c.back() - c[0];
        int mn = INT_MAX;
        for (int j = 0; j < c.size() - 1; ++j) {
            mn = min(mn, c[j + 1] - c[j]);
        }
        ans[0] = mn;
        return ans;
    }
};