//Approach - 1: Simple traverse and check
//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();

        int count = 0;

        int i = 0;

        while(i < n) {
            if(s[i] == '1') {
                count++;

                while(i < n && s[i] =='1') {
                    i++;
                }
            } else {
                i++;
            }

            if(count > 1) return false;
        }

        return true;
    }
};


//Approach - 2: Simply look for "01"
//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};