class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int first = 0;
        int last = nums.size() - 1;
        while (true) {
            if (first == last || nums[first] >> 31 == 0) break;
            if (abs(nums[first]) > nums[last]) first++;
            else if (abs(nums[first]) < nums[last]) last--;
            else return nums[last];
        }
        return -1;
    }
};