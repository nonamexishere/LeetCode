class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i, j;
        int ss = s.length(), tt = t.length();
        for (i = 0, j = 0; i < ss, j < tt; ++j) {
            if (s[i] == t[j]) i++;
        }
        return i == ss;
    }
};