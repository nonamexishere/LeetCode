class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int length = words.size();
        vector<vector<int>> v(length, vector<int> (26));
        for (int i = 0; i < length; ++i) {
            for (auto& word : words[i]) {
                v[i][word - 'a']++;
            }
        }
        vector<string> ans;
        vector<int> m(26);
        for (int i = 0; i < 26; ++i) {
            int mn = 101;
            for (int j = 0; j < length; ++j) {
                mn = min(mn, v[j][i]);
            }
            for (int j = 0; j < mn; ++j) {
                ans.push_back(string(1,static_cast<char>(i + 'a')));
            }
        }
        return ans;
    }
};