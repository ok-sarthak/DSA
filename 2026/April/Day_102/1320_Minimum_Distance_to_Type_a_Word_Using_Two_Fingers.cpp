//Approach - 1: Recursion + Memo with 5-D Memoization DP
//T.C: O(n*27*27) ~= O(n)
//S.C: O(n*27*27) ~= O(n)
class Solution {
public:

    int dp[301][7][7][7][7];

    pair<int, int> getCoordinate(char ch) {
        int pos = ch - 'A';

        return {pos / 6, pos % 6};
    }

    int getDistance(int x1, int y1, int x2, int y2) {

        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string &word, int i, int x1, int y1, int x2, int y2) {
        if (i == word.size()) 
            return 0;

        if (dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] != -1)
            return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1];

        auto [x, y] = getCoordinate(word[i]);

        if (x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1) {

            return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = solve(word, i + 1, x, y, x2, y2);
        }

        if (x2 == -1 && y2 == -1) {
            int moveF2 = solve(word, i + 1, x1, y1, x, y);

            int moveF1 = solve(word, i + 1, x, y, x2, y2) + getDistance(x1, y1, x, y);

            return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = min(moveF1, moveF2);
        }

        int moveF1 = solve(word, i + 1, x, y, x2, y2) + getDistance(x1, y1, x, y);

        int moveF2 = solve(word, i + 1, x1, y1, x, y) + getDistance(x2, y2, x, y);

        return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = min(moveF1, moveF2);
    }

    int minimumDistance(string word) {

        memset(dp, -1, sizeof(dp));

        return solve(word, 0, -1, -1, -1, -1);
    }
};


//Approach - 2: Recursion + Memo with 3-D Memoization DP
//T.C: O(n*27*27) ~= O(n)
//S.C: O(n*27*27) ~= O(n)
class Solution {
public:
    int dp[301][27][27];

    pair<int, int> getCoord(int pos) {
        return {pos/6, pos%6};
    }

    int getDistance(int pos1, int pos2) {
        auto[x1, y1] = getCoord(pos1);
        auto[x2, y2] = getCoord(pos2);
        
        return abs(x1 - x2) + abs(y1-y2);
    }

    int solve(string &word, int i, int f1, int f2) {
        if(i >= word.length())
            return 0;
        
        int curr = word[i] - 'A';

        if(dp[i][f1][f2] != -1) {
            return dp[i][f1][f2];
        }

        if(f1 == 26 && f2 == 26) {
            return dp[i][f1][f2] = solve(word, i+1, curr, f2);
        }

        if(f2 == 26) {
            int moveF2 = solve(word, i+1, f1, curr);
            
            int moveF1 = getDistance(f1, curr) + solve(word, i+1, curr, f2);

            return dp[i][f1][f2] = min(moveF1, moveF2);
        }

        int moveF1 = getDistance(f1, curr) + solve(word, i+1, curr, f2);

        int moveF2 = getDistance(f2, curr) + solve(word, i+1, f1, curr);

        return dp[i][f1][f2] = min(moveF1, moveF2);
    }
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));

        return solve(word, 0, 26, 26);
    }
};



//Approach - 3: Bottom Up
//T.C: O(n)
//S.C: O(n)
class Solution {
public:
    int dp[301][27][27];

    pair<int, int> getCoord(int pos) {
        return {pos/6, pos%6};
    }

    int getDistance(int pos1, int pos2) {
        if (pos1 == 26 || pos2 == 26) return 0;

        auto [x1, y1] = getCoord(pos1);
        auto [x2, y2] = getCoord(pos2);

        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.length();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(27, vector<int>(27, 0)));

        for (int i = n - 1; i >= 0; i--) {
            int curr = word[i] - 'A';

            for (int f1 = 0; f1 < 27; f1++) {
                for (int f2 = 0; f2 < 27; f2++) {

                    if (f1 == 26 && f2 == 26) {
                        dp[i][f1][f2] = dp[i+1][curr][f2];

                        continue;
                    }

                    if (f2 == 26) {
                        int moveF2 = dp[i+1][f1][curr];

                        int moveF1 = getDistance(f1, curr) + dp[i+1][curr][f2];

                        dp[i][f1][f2] = min(moveF1, moveF2);

                        continue;
                    }

                    int moveF1 = getDistance(f1, curr) + dp[i+1][curr][f2];
                    
                    int moveF2 = getDistance(f2, curr) + dp[i+1][f1][curr];

                    dp[i][f1][f2] = min(moveF1, moveF2);
                }
            }
        }

        return dp[0][26][26];
    }
};