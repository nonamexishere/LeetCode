class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int size = nums.size();
        int l = 0;
        int r = 0;
        map<int, int> m;
        int mx = 0;
        while (r < size || l > r) {
            if (m[nums[r]] < k) {
                m[nums[r++]]++;
            }
            else {
                mx = max(mx, r - l);
                while (nums[l] != nums[r]) {
                    m[nums[l++]]--;
                }
                m[nums[l++]]--;
            }
        }
        mx = max(mx, r - l);
        return mx;
    }
};