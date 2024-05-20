class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int size = nums.size();
        int bm = 1 << size;
        int ans = 0;
        for (int i = 0; i < bm; ++i) {
            int x = 0;
            for (int j = 0; j < size; ++j) {
                if (i >> j & 1) x ^= nums[j];
            }
            ans += x;
        }
        return ans;
    }
};