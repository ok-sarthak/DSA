class Solution {
public:
    int M = 1e9 + 7;
    //Memoize
    vector<vector<int>> t; //2D vector, because n & prev parameters are changing
    //12 possible rows
    string states[12] = {"RYG", "RGY", "RYR", "RGR", "YGR", "YRG", "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"};
    
    int solve(int n, int prev) {
        if(n == 0) return 1; //Base case

        if(t[n][prev] != -1) return t[n][prev];

        int result = 0;
        string last = states[prev];

        for(int curr = 0; curr < 12; curr++) {
            if(curr == prev) continue;

            string currPat = states[curr];
            bool conflict = false;

            for(int col = 0; col < 3; col++) {
                if(currPat[col] == last[col]) {
                    conflict = true;
                    break;
                }
            }

            if(!conflict) {
                result = (result + solve(n-1, curr)) % M;
            }
        }
        return t[n][prev] = result;
    }

    int numOfWays(int n) {
        t.resize(n, vector<int>(12, -1)); //O(N * 12 * 12 * 3), O(N * 12)

        int result = 0;

        for (int i = 0; i < 12; i++) { //choosing 1st row
            //now remaining n-1 rows
            result = (result + solve(n-1, i)) % M; // T.C = O(N), S.C = O(N)
        }

        return result;
    }
};