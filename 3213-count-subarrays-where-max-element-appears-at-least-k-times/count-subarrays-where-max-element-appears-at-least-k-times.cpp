class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        auto it = max_element(nums.begin(), nums.end());
        int mx = *it;
        vector<int> v;
        long long ans  = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == mx) {
               v.push_back(i);
            }
            int size = v.size();
            if (size >= k) {
                ans +=v[size - k] + 1;
            }
        }

        return ans;
    }
};