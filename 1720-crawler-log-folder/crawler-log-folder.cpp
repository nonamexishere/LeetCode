class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (string& l : logs) {
            if (l == "../" && ans > 0) {
                ans--;
            }
            else if (l == "../" || l == "./") {
                continue;
            }
            else {
                ans++;
            }
        }
        return ans;
    }
};