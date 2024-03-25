class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        vector<int> b(100001, 0);
        for (int& num : nums) {
            if (b[num] == 1) {ans.push_back(num);}
            b[num]++;
        }
        return ans;
    }
};