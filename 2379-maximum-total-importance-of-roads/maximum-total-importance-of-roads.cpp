class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> v(n);
        for (vector<int>& s : roads) {
            v[s[0]]++;
            v[s[1]]++;
        }
        sort(v.begin(), v.end());
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += (long long) v[i - 1] * i;
        }
        return ans;
    }
};