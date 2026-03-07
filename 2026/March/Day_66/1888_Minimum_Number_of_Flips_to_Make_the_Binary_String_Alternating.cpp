//Approach - 1: Sliding Window + modifying input s = s+s
//T.C : O(2*n) ~= O(n)
//S.C : O(2*n) for s1 and s2 and s+=s
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        s += s;

        string s1, s2;

        for(int i = 0; i < 2*n; i++) {
            s1 += (i%2 == 0) ? '0' : '1';
            s2 += (i%2 == 0) ? '1' : '0';
        }

        int f1 = 0, f2 = 0;

        int result = INT_MAX;

        int i = 0, j = 0;

        while(j < 2*n) {
            if(s[j] != s1[j]) f1++;
            if(s[j] != s2[j]) f2++;

            while(j-i+1 > n) {
                if(s[i] != s1[i]) f1--;
                if(s[i] != s2[i]) f2--;

                i++;
            }

            if(j-i+1 == n) result = min({result, f1, f2});

            j++;
        }

        return result;
    }
};


//Approach - 2:Sliding Window + without modifying input
//T.C : O(2*n) ~= O(n)
//S.C : O(2*n) for s1 and s2
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        string s1, s2;

        for(int i = 0; i < 2*n; i++) {
            s1 += (i%2 == 0) ? '0' : '1';
            s2 += (i%2 == 0) ? '1' : '0';
        }

        int f1 = 0, f2 = 0;

        int result = INT_MAX;

        int i = 0, j = 0;

        while(j < 2*n) {
            if(s[j%n] != s1[j]) f1++;
            if(s[j%n] != s2[j]) f2++;

            while(j-i+1 > n) {
                if(s[i%n] != s1[i]) f1--;
                if(s[i%n] != s2[i]) f2--;

                i++;
            }

            if(j-i+1 == n) result = min({result, f1, f2});

            j++;
        }

        return result;
    }
};


//Approach - 3: Sliding Window + without modifying input
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