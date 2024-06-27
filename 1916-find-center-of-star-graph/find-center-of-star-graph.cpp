class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> m;
        for (vector<int>& v : edges) {
            for (int& i : v) {
                m[i]++;
                if (m[i] > 1) return i;
            }
        }
        return 1;
    }
};