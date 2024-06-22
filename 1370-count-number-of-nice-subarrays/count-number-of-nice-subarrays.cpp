class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int l = 0, r = 1;
        int size = nums.size();
        int ans = 0;
        vector<int> odds;
        odds.push_back(-1);
        for (int i = 0; i < size; ++i) {
            if (nums[i] & 1) odds.push_back(i);
        }
        odds.push_back(size);
        size = odds.size();
        for (int i = 1; i < size - k; ++i) {
            ans += (odds[i] - odds[i - 1]) * (odds[i + k] - odds[i + k - 1]);
        }
        return ans;
    }
};