//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();

        int result = 0;

        int prevCount = 0;
        int currCount = 1;

        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                currCount++;
            } else {
                result += min(prevCount, currCount);
                prevCount = currCount;
                currCount = 1;
            }
        }

        return result + min(prevCount, currCount);
    }
};