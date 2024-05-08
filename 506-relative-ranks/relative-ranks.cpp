class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int, int> m;
        int size = score.size();
        int tmp_size = size;
        for (int i = 0; i < size; ++i) m[score[i]] = i;
        vector<string> vs(size);
        for (auto& p : m) {
            if (tmp_size == 3) vs[p.second] = "Bronze Medal";
            else if (tmp_size == 2) vs[p.second] = "Silver Medal";
            else if (tmp_size == 1) vs[p.second] = "Gold Medal";
            else vs[p.second] = to_string(tmp_size);
            tmp_size--;
        }
        return vs;
    }
};