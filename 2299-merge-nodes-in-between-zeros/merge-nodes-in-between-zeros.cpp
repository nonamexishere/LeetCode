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
static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout.tie(nullptr);
    return 0;
}();

int init = [] {
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string str; getline(cin, str);) {
        istringstream ss(str); ss.ignore(3);
        ostringstream os;
        int sum = 0;
        bool first = true;
        cout << '[';
        for (int i; ss >> i; ss.ignore()) {
            if (!i) {
                os << (first ? "" : ",") << sum;
                sum = 0;
                first = false;
            } else {
                sum += i;
            }
        }
        os << ']';
        cout << os.str() << '\n';
    }
    exit(0);
    return 0;
}();
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