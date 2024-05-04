const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        int ans = 0;
        while (l < r) {
            if (people[r] + people[l] <= limit) {
                l++;
            }
            ans++;
            r--;
        }
        if (l == r) ans++;
        return ans;
    }
};