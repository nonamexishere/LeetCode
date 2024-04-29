class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int p = 0;
        for (int i = 0; i < nums.size(); ++i) {
            p ^= nums[i];
        }
        int ans = 0;
        p ^= k;
        while (p) {
            ans += (p & 1);
            p >>= 1;
        }
        return ans;
    }
};