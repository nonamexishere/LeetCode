class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        int size = nums.size();
        for (int i = 1; i < size; ++i) {
            if (prev == nums[i]) return prev;
            prev = nums[i];
        }
        return prev;
    }
};