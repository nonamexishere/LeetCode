class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int size = arr.size();
        vector<int> pref(size + 1);
        for (int i = 1; i <= size; ++i) {
            pref[i] = pref[i - 1] ^ arr[i - 1];
        }
        map<int, vector<int>> m;
        for (int i = 0; i <= size; ++i) {
            m[pref[i]].push_back(i);
        }
        int ans = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second.size() > 1) {
                vector<int> v = it->second;
                for (int i = 0; i < v.size(); ++i) {
                    for (int j = i + 1; j < v.size(); ++j) {
                        ans += v[j] - v[i] - 1;
                    }
                }
            }
        }
        return ans;
    }
};