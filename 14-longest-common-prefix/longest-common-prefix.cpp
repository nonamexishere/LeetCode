class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        char letter;
        int counter = 0;
        string ans = "";
        while (true) {
            if (counter == strs[0].size()) return ans;
            letter = strs[0][counter];
            for (int i = 1; i < size; ++i) {
                if (counter == strs[i].size() || strs[i][counter] != letter) return ans;
            }
            ans += letter;
            counter++;
        }
    }
};