//T.C: O(log n)
//S.C: O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto p = upper_bound(letters.begin(),letters.end(),target);
        return p != letters.end() ? *p : letters[0];
    }
};