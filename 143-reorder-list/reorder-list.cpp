class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* tmp = head;
        deque<ListNode*> dq;
        while(tmp) {
            tmp = tmp->next;
            dq.push_back(tmp);
        }
        dq.pop_back();
        int size = dq.size();
        tmp = head;
        for (int i = 1; i <= size; ++i) {
            if (i & 1) {
                ListNode* back = dq.back();
                dq.pop_back();
                tmp->next = back;
                tmp = back;
            }
            else {
                ListNode* front = dq.front();
                dq.pop_front();
                tmp->next = front;
                tmp = front;
            }
            tmp->next = nullptr;
        }
    }
};