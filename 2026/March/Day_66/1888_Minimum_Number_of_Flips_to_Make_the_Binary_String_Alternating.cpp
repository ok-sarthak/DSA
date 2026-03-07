//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        int f1 = 0, f2 = 0;

        int result = INT_MAX;

        int i = 0, j = 0;

        while(j < 2*n) {
            char expectedS1 = (j%2 == 0) ? '0' : '1';
            char expectedS2 = (j%2 == 0) ? '1' : '0';

            if(s[j%n] != expectedS1) f1++;
            if(s[j%n] != expectedS2) f2++;

            while(j-i+1 > n) {
                char expectedS1 = (i%2 == 0) ? '0' : '1';
                char expectedS2 = (i%2 == 0) ? '1' : '0';

                if(s[i%n] != expectedS1) f1--;
                if(s[i%n] != expectedS2) f2--;

                i++;
            }

            if(j-i+1 == n) result = min({result, f1, f2});

            j++;
        }

        return result;
    }
};