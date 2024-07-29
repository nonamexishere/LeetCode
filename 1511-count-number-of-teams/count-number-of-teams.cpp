class Solution {
public:
    int numTeams(vector<int>& r) {
        int n = r.size();
        int ans = 0;
        map<int, int> mp;

        int c = 0;
        for (int i = 0; i < n; ++i) {
            mp[r[i]] = 1;
        }
        for (auto [x, a] : mp) {
            mp[x] = ++c;
        }
        for (int i = 0; i < n; ++i) {
            r[i] = mp[r[i]];
        }
        for (int i = 0; i < n - 1; ++i) {
            int smaller = 0;
            for (int j = 0; j < i; ++j) {
                if (r[j] < r[i]) smaller++;
            }
            ans += (smaller * ((n - r[i]) - (i - smaller)));
            ans += ((i - smaller) * (r[i] - 1 - smaller));
        }
        return ans;
    }
};