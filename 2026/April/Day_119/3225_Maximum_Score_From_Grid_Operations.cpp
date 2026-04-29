//Approach - 1: Brute Force -- TLE
//T.C: O((n+1)^n * n^2))
//S.C: O(n)
class Solution {
public:
    long long computeScore(vector<int>& h, vector<vector<int>>& grid, int n) {
        long long score = 0;

        for (int j = 0; j < n; j++) {
            
            for (int i = h[j] + 1; i < n; i++) {

                bool hasBlackNeighbor = false;

                if (j - 1 >= 0 && i <= h[j - 1])
                    hasBlackNeighbor = true;

                if (j + 1 < n && i <= h[j + 1])
                    hasBlackNeighbor = true;

                if (hasBlackNeighbor)
                    score += grid[i][j];
            }
        }

        return score;
    }

    void solve(int col, vector<int>& h, vector<vector<int>>& grid, int n, long long& result) {

        if (col == n) {
            result = max(result, computeScore(h, grid, n));

            return;
        }

        for (int height = -1; height < n; height++) {
            h[col] = height;

            solve(col + 1, h, grid, n, result);
        }
    }

    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> h(n);

        long long result = 0;

        solve(0, h, grid, n, result);

        return result;
    }
};


//Approach - 2: Brute Force with improved computeScore
//T.C: O((n+1)^n * n))
//S.C: O(n^2)
class Solution {
public:

    using ll = long long;

    ll computeScore(vector<int>& h, vector<vector<ll>>& colPrefSum, int n) {
        ll score = 0;

        for (int col = 0; col < n; col++) {

            int left = (col - 1 >= 0 ? h[col - 1] : -1);
            int right = (col + 1 < n ? h[col + 1] : -1);

            int upper = max(left, right);
            int lower = h[col];

            if (upper > lower) {
                score += colPrefSum[upper + 1][col + 1] - colPrefSum[lower + 1][col + 1];
            }
        }

        return score;
    }

    void solve(int col, vector<int>& h, vector<vector<ll>>& colPrefSum, int n, ll& result) {

        if (col == n) {
            result = max(result, computeScore(h, colPrefSum, n));

            return;
        }

        for (int height = -1; height < n; height++) {
            h[col] = height;

            solve(col + 1, h, colPrefSum, n, result);
        }
    }

    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
      
        vector<vector<ll>> colPrefSum(n + 1, vector<ll>(n + 1, 0));

        for (int col = 1; col <= n; col++) {

            for (int row = 1; row <= n; row++) {
                colPrefSum[row][col] = colPrefSum[row - 1][col] + grid[row - 1][col-1];
            }
        }

        vector<int> h(n);
        
        ll result = 0;

        solve(0, h, colPrefSum, n, result);

        return result;
    }
};


//Approach - 3: Most optimal
//T.C: O(n^3)
//S.C: O(n^2)
class Solution {
public:

    typedef long long ll;

    int n;
    
    ll t[2][101][101];

    ll solve(bool prevTaken, int prevHeight, int col, vector<vector<int>>& grid, vector<vector<ll>>& colPrefSum) {
        
        if(col == n) {
            return 0;
        }
        
        ll result = 0;

        if(t[prevTaken][prevHeight][col] != -1) {
            return t[prevTaken][prevHeight][col];
        } 

        for(int height = 0; height <= n; height++) {
            ll prevColScore = 0;
            ll currColScore = 0;

            if(!prevTaken && col-1 >= 0 && height > prevHeight) {
                prevColScore += colPrefSum[height][col] - colPrefSum[prevHeight][col];
            }

            if(prevHeight > height) {
                currColScore += colPrefSum[prevHeight][col+1] - colPrefSum[height][col+1];
            }


            ll currColScoreTaken    = currColScore + prevColScore + solve(true, height, col+1, grid, colPrefSum);
            ll currColScoreNotTaken = prevColScore + solve(false, height, col+1, grid, colPrefSum);

            result = max({result, currColScoreTaken, currColScoreNotTaken});
        }

        return t[prevTaken][prevHeight][col] = result;
    }

    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();

        memset(t, -1, sizeof(t));


        vector<vector<ll>> colPrefSum(n + 1, vector<ll>(n + 1, 0));

        for(int col = 1; col <= n; col++) {
            for(int row = 1; row <= n; row++) {
                colPrefSum[row][col] = colPrefSum[row-1][col] + grid[row-1][col-1];
            }
        }

        return solve(false, 0, 0, grid, colPrefSum);
    }
};