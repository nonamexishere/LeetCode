class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        vector<int> prefix_all(n + 1);
        vector<int> prefix_normal(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (!grumpy[i - 1]) prefix_normal[i] = prefix_normal[i - 1] + customers[i - 1];
            else prefix_normal[i] = prefix_normal[i - 1];
            prefix_all[i] = prefix_all[i - 1] + customers[i - 1];
        }
        int mx = 0;
        for (int i = 1; i <= n - minutes + 1; ++i) {
            int tmp = prefix_normal[n] - (prefix_normal[i + minutes - 1] - prefix_normal[i - 1]) + (prefix_all[i + minutes - 1] - prefix_all[i - 1]);
            mx = max(mx, tmp);
        }
        return mx;
    }
};