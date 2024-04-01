class Solution {
public:
    int lengthOfLastWord(string s) {
        int counter = 0;
        int last = 0;
        for (char& l : s) {
            if (l == ' ') {counter > 0 ? last = counter : last = last; counter = 0;}
            else counter++;
        }
        return counter != 0 ? counter : last;
    }
};