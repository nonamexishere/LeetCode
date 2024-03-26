class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        vector<bool> v(size + 1, false);
        for (int i = 0; i < size; ++i) {
            if (nums[i] > 0 && nums[i] < size + 1)
                v[nums[i]] = true;
        }

        for (int i = 1; i <= size; ++i) {
            if (!v[i]) return i;
        }
        return size + 1;
    }
};