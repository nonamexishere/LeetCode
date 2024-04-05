class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string ans = "";
        for (int i = s.size() - 1; i >= 0; --i) st.push(s[i]);
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            if (ans.length() > 0 && abs(top - ans[ans.length() - 1]) == 32) ans.erase(ans.length() - 1);
            else if (!st.empty() && abs(top - st.top()) == 32) st.pop();
            else ans += top;
        }
        return ans;
    } 
};