class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int> m;
        int i = 0; int j = 0;
        int ans = 0;
        if (s.size() == 0) {
            return 0;
        }
        while (i <= j && j < s.size()) {
            if (m[s[j]] > 0) {
                ans = max(ans, j - i);
                m[s[i]]--;
                i++;
            }
            else {
                m[s[j]]++;
                j++;
            }
        }
        ans = max(ans, j - i);
        return ans;
    }
};