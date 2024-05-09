class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            if (i > happiness[i]) break;
            ans += happiness[i] - i;
        }
        return ans;
    }
};