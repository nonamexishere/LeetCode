class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> p(size + 1, 0);
        for (int i = 1; i <= size; ++i) {
            p[i] = p[i - 1] ^ nums[i - 1];
        }
        int x = 32;
        int ans = 0;
        p[size] = p[size] ^ k;
        while (x--) {
            ans += (p[size] % 2);
            p[size] /= 2;
        }
        return ans;
    }
};