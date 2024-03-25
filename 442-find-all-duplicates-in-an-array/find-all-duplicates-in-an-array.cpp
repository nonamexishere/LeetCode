class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> m;
        for (int& i : nums) {
            m[i]++;
            if (m[i] == 2) ans.push_back(i);
        }
        return ans;
    }
};