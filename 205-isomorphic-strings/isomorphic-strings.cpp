class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();
        if (t_size != s_size) return false;
        unordered_map<char, char> ms;
        unordered_map<char, char> mt;
        for (int i = 0; i < s_size; ++i) {
            if (ms.find(s[i]) == ms.end() && mt.find(t[i]) == mt.end()) {
                ms[s[i]] = t[i];
                mt[t[i]] = s[i];
            }
            else if (ms[s[i]] != t[i] || mt[t[i]] != s[i])
                return false;
        }
        return true;
    }
};