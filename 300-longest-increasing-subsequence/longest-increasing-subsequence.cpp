class Solution {
public:
    int helper(vector<int>&nums, vector<int>&m) {
        int mx = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    m[i] = max(m[i], m[j] + 1);
                    mx = max(m[i], mx);
                }
            } 
        }
        return mx;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> m(nums.size(), 1);
        return helper(nums, m);
    }
};