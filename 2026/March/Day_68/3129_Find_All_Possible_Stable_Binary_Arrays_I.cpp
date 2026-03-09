//Approach - 1: Recursion + Memoization
// T.C : O(zero * one * limit)
// S.C : O(zero * one)
class Solution {
public:

    int M = 1e9 + 7;

    int t[201][201][2];

    int solve(int zerosLeft, int onesLeft, bool lastWasOne, int limit) {
        if(zerosLeft == 0 && onesLeft == 0) return 1;

        if(t[zerosLeft][onesLeft][lastWasOne] != -1) {
            return t[zerosLeft][onesLeft][lastWasOne];
        }

        int result = 0;

        if(lastWasOne == false) {
            for(int len = 1; len <= min(onesLeft, limit); len++) {
                result = (result + solve(zerosLeft, onesLeft - len, true, limit)) % M;
            }
        } else {
            for(int len = 1; len <= min(zerosLeft, limit); len++) {
                result = (result + solve(zerosLeft - len, onesLeft, false, limit)) % M;
            }
        }

        return t[zerosLeft][onesLeft][lastWasOne] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));

        int startWithZero = solve(zero, one, true, limit);
        int startWithOne = solve(zero, one, false, limit);

        return (startWithZero + startWithOne) % M;
    }
};


//Approach - 2: Bottom Up
// T.C : O(zero * one * limit)
// S.C : O(zero * one)
class Solution {
public:

    int M = 1e9 + 7;

    int t[201][201][2];

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, 0, sizeof(t));

        t[0][0][0] = 1;
        t[0][0][1] = 1;

        for(int zerosLeft = 0; zerosLeft <= zero; zerosLeft++) {
            for(int onesLeft = 0; onesLeft <= one; onesLeft++) {
                if(zerosLeft == 0 && onesLeft == 0) continue;

                int result = 0;

                for(int len = 1; len <= min(onesLeft, limit); len++) {
                    result = (result + t[zerosLeft][onesLeft - len][1]) % M;
                }
                t[zerosLeft][onesLeft][0] = result;

                result = 0;

                for(int len = 1; len <= min(zerosLeft, limit); len++) {
                    result = (result + t[zerosLeft - len][onesLeft][0]) % M;
                }
                t[zerosLeft][onesLeft][1] = result;
            }
        }

        int startWithZero = t[zero][one][true];
        int startWithOne = t[zero][one][false];

        return (startWithZero + startWithOne) % M;
    }
};