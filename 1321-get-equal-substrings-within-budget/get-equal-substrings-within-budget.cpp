class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int length = s.length();
        int mx = 0;
        vector<int> v(length);
        vector<int> prefixs(length + 1);
        for (int i = 0; i < length; ++i) {
            v[i] = abs(s[i] - t[i]);
        }
        for (int i = 1; i <= length; ++i) {
            prefixs[i] = prefixs[i - 1] + v[i - 1]; 
        }
        int l = 0; 
        int r = 0;
        while (l <= r && r <= length) {
            if (prefixs[r] - prefixs[l] > maxCost) {
                l++;
            }
            else {
                mx = max(mx, r - l);
                r++;
            }
        }
        return mx;
    }
};