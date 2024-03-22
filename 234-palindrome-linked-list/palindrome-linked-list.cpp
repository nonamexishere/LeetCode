class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* tmp1 = head;
        ListNode* tmp2 = head;
        stack<int> s;
        int counter = 0;
        while(tmp2) {
            counter++;
            tmp2 = tmp2->next;
            if (counter % 2 == 0) {
                s.push(tmp1->val);
                tmp1 = tmp1->next;
            }
        } 
        if (counter & 1) tmp1 = tmp1->next;
        while(tmp1) {
            if (tmp1->val == s.top()) s.pop();
            else return false;
            tmp1 = tmp1->next;
        }
        return true;
    }
};