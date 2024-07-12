class Solution {
public:
    string reverseParentheses(string s) {
        vector<pair<int, int>> p;
        stack<int> open;
        int x = 0;
        for (char& c : s) {
            if (c == '(') open.push(x);
            if (c == ')') {
                int top = open.top();
                open.pop();
                p.push_back({top, x});
            }
            x++;
        } 
        int size = p.size();
        for (int i = 0; i < size; ++i) {
            int first = p[i].first + 1;
            int second = p[i].second - 1;
            int sc = p[i].second - 1;
            for (int j = first; j <= (first - 1 + sc + 1) / 2; ++j) {
                swap(s[j], s[second--]);
            }
        }
        string ans = "";
        for (char& c : s) {
            if (c == '(' || c == ')') continue;
            else {
                ans += c;
            }
        }
        return ans;
    }
};