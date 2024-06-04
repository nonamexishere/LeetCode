class Solution {
public:
    int longestPalindrome(string s) {
        map<int, int> m;
        for (int i = 0; i < s.length(); ++i) {
            m[s[i]]++;
        }
        int ans = 0;
        int biggestOdd = -1;
        bool is = false;
        for (auto& pair : m) {
            if (pair.second & 1) {
                ans += pair.second - 1;
                is = true;
            }
            else {
                ans += pair.second;
            }
        }
        if (is)
            ans++;
        return ans;
    }
};