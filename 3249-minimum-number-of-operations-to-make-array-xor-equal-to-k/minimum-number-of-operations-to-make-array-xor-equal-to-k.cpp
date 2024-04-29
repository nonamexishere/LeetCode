class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        for (int i = 0; i < nums.size(); ++i) {
            k ^= nums[i];
        }
        int ans = 0;
        while (k) {
            ans += (k & 1);
            k >>= 1;
        }
        return ans;
    }
};