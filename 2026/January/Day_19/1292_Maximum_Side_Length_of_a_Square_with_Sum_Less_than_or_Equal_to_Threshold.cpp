//Approach 1 - Brute Force
//T.C: O(m^2 * n^2 * min(m, n))
//S.C: O(1)
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size(); //m
        int cols = mat[0].size(); //n 
        int bestSide = 0; //maximum side of square
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                for(int k = 0; k < min(rows - i, cols - j); k++) { //offset
                    int r2 = i + k;
                    int c2 = j + k;

                    int sum = 0;

                    for(int r = i; r <= r2; r++) {
                        for(int c = j; c <= c2; c++) {
                            sum += mat[r][c];
                        }
                    }

                    if(sum <= threshold) {
                        bestSide = max(bestSide, k+1);
                    } else {
                        break;
                    }
                }
            }
        }

        return bestSide;
    }
};


//Approach 2 - Prefix Sum + Brute Force
//T.C: O(m * n * min(m, n))
//S.C: O(m * n)
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size(); //m
        int cols = mat[0].size(); //n

        vector<vector<int>> prefix(rows, vector<int>(cols, 0));
        //prefix[i][j] = sum of all elements in mat from top_left to [i][j]

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                prefix[i][j] = (i > 0 ? prefix[i-1][j] : 0) + (j > 0 ? prefix[i][j-1] : 0) - (i > 0 && j > 0 ? prefix[i-1][j-1] : 0) + mat[i][j];
            }
        }

        auto sumSquare = [&](int i, int j, int r2, int c2) {
            int sum = prefix[r2][c2];

            if(i > 0)
                sum -= prefix[i-1][c2];
            
            if(j > 0)
                sum -= prefix[r2][j-1];

            if(i > 0 && j > 0)
                sum += prefix[i-1][j-1];
            
            return sum;
        };

        int bestSide = 0; //maximum side of square

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                for(int k = 0; k < min(rows - i, cols - j); k++) { //offset
                    int r2 = i + k;
                    int c2 = j + k;

                    int sum = sumSquare(i, j, r2, c2);

                    if(sum <= threshold) {
                        bestSide = max(bestSide, k+1);
                    } else {
                        break;
                    }
                }
            }
        }

        return bestSide;
    }
};

//Approach 3
//Small Optimize by setting the offset to bestSide instead of 0
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size(); //m
        int cols = mat[0].size(); //n

        vector<vector<int>> prefix(rows, vector<int>(cols, 0));
        //prefix[i][j] = sum of all elements in mat from top_left to [i][j]

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                prefix[i][j] = (i > 0 ? prefix[i-1][j] : 0) + (j > 0 ? prefix[i][j-1] : 0) - (i > 0 && j > 0 ? prefix[i-1][j-1] : 0) + mat[i][j];
            }
        }

        auto sumSquare = [&](int i, int j, int r2, int c2) {
            int sum = prefix[r2][c2];

            if(i > 0)
                sum -= prefix[i-1][c2];
            
            if(j > 0)
                sum -= prefix[r2][j-1];

            if(i > 0 && j > 0)
                sum += prefix[i-1][j-1];
            
            return sum;
        };

        int bestSide = 0; //maximum side of square

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                for(int k = bestSide; k < min(rows - i, cols - j); k++) { //offset
                    int r2 = i + k;
                    int c2 = j + k;

                    int sum = sumSquare(i, j, r2, c2);

                    if(sum <= threshold) {
                        bestSide = max(bestSide, k+1);
                    } else {
                        break;
                    }
                }
            }
        }

        return bestSide;
    }
};

//Approach 4 - Binary Search
//T.C: O(m * n * log(min(m, n)))
//S.C: O(m * n)
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size(); //m
        int cols = mat[0].size(); //n

        vector<vector<int>> prefix(rows, vector<int>(cols, 0));
        //prefix[i][j] = sum of all elements in mat from top_left to [i][j]

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                prefix[i][j] = (i > 0 ? prefix[i-1][j] : 0) + (j > 0 ? prefix[i][j-1] : 0) - (i > 0 && j > 0 ? prefix[i-1][j-1] : 0) + mat[i][j];
            }
        }

        auto sumSquare = [&](int i, int j, int r2, int c2) {
            int sum = prefix[r2][c2];

            if(i > 0)
                sum -= prefix[i-1][c2];
            
            if(j > 0)
                sum -= prefix[r2][j-1];

            if(i > 0 && j > 0)
                sum += prefix[i-1][j-1];
            
            return sum;
        };

        auto check = [&] (int side) {
            for(int i = 0; i + side - 1 < rows; i++) {
                for(int j = 0; j + side - 1 < cols; j++) {
                    int r2 = i + side - 1;
                    int c2 = j + side - 1;

                    if(sumSquare(i, j, r2, c2) <= threshold) {
                        return true;
                    }
                }
            }

            return false;
        };

        int low = 1;
        int high = min(rows, cols);

        int result = 0;

        while(low <= high) {
            int mid = low + (high-low)/2;
            if(check(mid)) {
                result = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return result;
    }
};
