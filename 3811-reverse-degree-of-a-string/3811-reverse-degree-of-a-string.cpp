class Solution {
public:
    int reverseDegree(string s) {
        int totalSum = 0;
        for (int i = 0; i < s.length(); ++i) {
            int reversedAlphabetPos = 26 - (s[i] - 'a');
            totalSum += reversedAlphabetPos * (i + 1);
        }
        return totalSum;
    }
};