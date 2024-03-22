class Solution {
public:
    bool isPalindrome(ListNode* head) {
       ListNode* tmp = head;
       int counter = 0;
       while(tmp) {
        tmp = tmp->next;
        counter++;
       } 
       tmp = head;
       vector<int> first_half;
       int tmp_counter = counter / 2;
       while (tmp_counter--) {
        first_half.emplace_back(tmp->val);
        tmp = tmp->next;
       }
       if (counter & 1) tmp = tmp->next;
        int i = counter / 2;
       while (tmp) {
        if(tmp->val != first_half[--i]) return false;
        tmp = tmp->next;
       }
       return true;
    }
};