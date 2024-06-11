class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        ios::sync_with_stdio(false);
        map<int, int> m1;
        vector<int> ans;
        for (int i = 0; i < arr1.size(); ++i) {
            m1[arr1[i]]++;
        }
        for (int i = 0; i < arr2.size(); ++i) {
            int x = arr2[i];
            while(m1[x]) {
                m1[x]--;
                ans.push_back(x);
            }
        }
        for (auto& p : m1) {
            if (p.second != 0) {
                while (p.second--) {
                    ans.push_back(p.first);
                }
            }
        }
        return ans;
    }
};