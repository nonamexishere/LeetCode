class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int length = skill.size();
        vector<pair<long long, long long>> v(length / 2);
        long long ans = 0;
        long long last = skill[0] + skill[length - 1];
        v[0] = {skill[0], skill[length - 1]};
        ans += (skill[0] * skill[length - 1]);
        for (long long i = 1; i < length / 2; i++) {
            long long first = skill[i];
            long long sec = skill[length - 1 - i];
            v[i] = {first, sec};
            if (last != first + sec) {
                return - 1;
            }
            ans += (first * sec);
        }
        return ans;
    }
};