class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        ios::sync_with_stdio(false);
        vector<int> v(1001);
        for (int& i : target) {
            v[i]++;
        }
        for (int& i : arr) {
            v[i]--;
            if (v[i] < 0) return false;
        }
        return true;
    }
};