// With Memo: T.C = O(m*n), S.C = O(m*n)
// Without Memo: T.C = Exponential, because of two opportunities for each character, S.C = O(m+n) for recursion stack
class Solution {
public:

    int m,n;

    int t[1001][1001];

    int solve(int i, int j, string &s1, string &s2) {
        if(i >= m && j >= n) return 0;

        if(t[i][j] != -1) return t[i][j];

        if(i >= m) {
            return t[i][j] = s2[j] + solve(i, j+1, s1, s2);
        } else if(j >= n) {
            return t[i][j] = s1[i] + solve(i+1, j, s1, s2);
        }

        if(s1[i] == s2[j]) {
            return t[i][j] = solve(i+1, j+1, s1, s2);
        }

        int del_s1_i = s1[i] + solve(i+1, j, s1, s2);
        int del_s2_j = s2[j] + solve(i, j+1, s1, s2);

        return t[i][j] = min(del_s1_i, del_s2_j);
    }

    int minimumDeleteSum(string s1, string s2) {
        m = s1.size();
        n = s2.size();

        memset(t, -1, sizeof(t));

        return solve(0, 0, s1, s2);
    }
};