//Approach - 1: Brute Force Check all rotations
//T.C: O(n^2)
//S.C: O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        if (m != n) 
            return false;

        for (int rotationCount = 1; rotationCount <= m; ++rotationCount) {

            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal) 
                return true;
        }
        
        return false;
    }
};


//Approach - 2: Concatenation with itself contains all possible rotations
//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();
        
        if(m == n && (s+s).find(goal) != string::npos)
            return true;
        
        return false;
    }
};