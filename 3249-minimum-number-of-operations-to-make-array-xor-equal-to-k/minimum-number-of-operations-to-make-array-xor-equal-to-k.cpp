class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> p(size + 1, 0);
        for (int i = 1; i <= size; ++i) {
            p[i] = p[i - 1] ^ nums[i - 1];
        }
        int ans = 0;
        p[size] = p[size] ^ k;
        while (p[size]) {
            ans += (p[size] & 1);
            p[size] >>= 1;
        }
        return ans;
    }
};