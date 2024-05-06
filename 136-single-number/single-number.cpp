class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        int s = nums.size();
        for (int i = 0; i < s; ++i) x ^= nums[i];
        return x;
    }
};