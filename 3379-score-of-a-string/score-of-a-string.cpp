class Solution {
public:
    int scoreOfString(string s) {
        int length = s.length();
        int ans = 0;
        for (int i = 0; i < length - 1; ++i) {
            int x = s[i];
            int y = s[i + 1];
            ans += abs(x - y);
        }
        return ans;
    }
};