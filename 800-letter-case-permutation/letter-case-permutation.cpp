class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        set<string> t;
        int length = s.length();
        int bm = 1 << length;
        for (int i = 0; i < bm; ++i) {
            string tmpS = s;
            for (int j = 0; j < length; ++j) {
                if (i & (1 << j)) if (isalpha(tmpS[j])) isupper(tmpS[j]) ? tmpS[j] = tolower(tmpS[j]) : tmpS[j] = toupper(tmpS[j]);        
            }
            t.insert(tmpS);
        }
        for (auto& l : t) {
            ans.push_back(l);
        }
        return ans;
    }
};