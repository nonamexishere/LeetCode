class Solution {
public:
    int appendCharacters(string s, string t) {
        int p = 0;
        int lengthS = s.length();
        int lengthT = t.length();
        for (int i = 0; i < lengthS; ++i) {
            if (t[p] == '\0') return 0;
            if (s[i] == t[p]) p++;
        }
        return lengthT - p;
    }
};