class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> q;
        string s = "0000";
        map<string, bool> visited;
        set<string> dead(deadends.begin(), deadends.end());
        q.push({s, 0});
        while (!q.empty()) {
            string ff = q.front().first;
            int fs = q.front().second;
            q.pop();
            if (dead.count(ff)) continue;
            if (visited[ff]) continue;
            visited[ff] = true;
            if (ff == target) return fs;
            for (int i = 0; i < 4; ++i) {
                string tmp = ff;
                if (ff[i] == '9') {
                    tmp[i] = '0';
                    q.push({tmp, fs + 1});
                    tmp[i] = '8';
                    q.push({tmp, fs + 1});
                }
                else if (ff[i] == '0') {
                    tmp[i] = '1';
                    q.push({tmp, fs + 1});
                    tmp[i] = '9';
                    q.push({tmp, fs + 1});
                }
                else {
                    tmp[i] = ff[i] + 1;
                    q.push({tmp, fs + 1});
                    tmp[i] = ff[i] - 1;
                    q.push({tmp, fs + 1});
                }
            }
        }
        return -1;
    }
};