class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> v;
        v.push_back({0, 0});
        for (int i = 0; i < difficulty.size(); ++i) {
            v.push_back({difficulty[i], profit[i]});
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); ++i) {
            if (v[i - 1].second > v[i].second) v[i].second = v[i - 1].second;
        }
        int ans = 0;
        for (int& work : worker) {
            int left = 0;
            int right = v.size() - 1;
            int tmp = 0;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (v[mid].first <= work) {
                    left = mid + 1;
                    tmp = max(tmp, v[mid].second);
                }
                else {
                    right = mid - 1;
                }
            }
            ans += tmp;
        }
        return ans;
    }
};