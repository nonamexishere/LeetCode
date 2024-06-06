class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> m;
        for (int& h : hand) {m[h]++;}
        int size = hand.size();
        if (size % groupSize) return false;
        while (!m.empty() && m.size() >= groupSize) {
            auto it = m.begin();
            int prev = it->first;
            it->second--;
            for (auto iter = next(it); iter != next(it, groupSize); ++iter) {
                if (iter->first - prev == 1) {
                    prev = iter->first;
                    iter->second--;
                }
                else return false;
            }
            vector<map<int, int>::iterator> werase;
            for (auto iter = it; iter != next(it, groupSize); ++iter) {
                if (iter->second == 0) werase.push_back(iter);
            }
            for (auto& e : werase) {
                m.erase(e);
            }
        }
        return m.empty();
    }
};