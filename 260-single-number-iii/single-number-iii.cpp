class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        map<long long, int> m;
        for (int& i : nums) {
            m[i]++;
        }
        for (auto& p : m) {
            if (p.second == 1) ans.push_back(p.first);
        }
        return ans;
    }
};