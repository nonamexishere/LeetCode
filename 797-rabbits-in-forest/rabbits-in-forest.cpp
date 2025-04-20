class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> m(1001);
        int size = answers.size();
        for (int i = 0; i < size; ++i) {
            m[answers[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < 1001; ++i) {
            int div = m[i] / (i + 1);
            ans += (div * (i + 1));
            if (m[i] % (i + 1)) {
                ans += (i + 1);
            }
        }
        return ans;
    }
};