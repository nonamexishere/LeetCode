class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int mx = 0;
        for (char l : s) {
            if (l == '(') {
                st.push(l);
                if (mx < st.size()) mx = st.size(); 
            }
            if (l == ')') st.pop();
        }
        return mx;
    }
};