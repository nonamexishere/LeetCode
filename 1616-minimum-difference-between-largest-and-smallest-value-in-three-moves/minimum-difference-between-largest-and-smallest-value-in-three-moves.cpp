class Solution {
public:
    int minDifference(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if (nums.size() < 5) return 0;
        sort(nums.begin(), nums.end());
        int mn = min(abs(nums[r] - nums[l + 3]), abs(nums[r - 3] - nums[l]));
        mn = min(abs(nums[r - 1] - nums[l + 2]), mn);
        mn = min(abs(nums[r - 2] - nums[l + 1]), mn);
        return mn;
    }
};