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