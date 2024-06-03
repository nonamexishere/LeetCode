class Solution {
public:
    int appendCharacters(string s, string t) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
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