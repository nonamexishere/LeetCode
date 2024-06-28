class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        map<int, int> m;
        for (vector<int>& v : roads) {
            m[v[0]]++;
            m[v[1]]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto& pair : m) {
            pq.push({pair.second, pair.first});
        }
        vector<int> coefficient(n);
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            coefficient[top.second] = n--;
        }
        long long ans = 0;
        for (auto& pair : m) {
            ans += (long long) coefficient[pair.first] * (long long) pair.second;
        }
        return ans;
    }
};