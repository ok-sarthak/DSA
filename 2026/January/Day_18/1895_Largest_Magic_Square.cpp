//S.C: O(m*n) for prefix sum arrays
//T.C: O(m*n*min(m,n)^2)
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size(); //m
        int cols = grid[0].size(); //n

        //Row wise prefix sum
        vector<vector<int>> rowCumSum(rows, vector<int>(cols));

        for(int i = 0; i < rows; i++) {
            rowCumSum[i][0] = grid[i][0];
            for(int j = 1; j < cols; j++) {
                rowCumSum[i][j] = rowCumSum[i][j-1] + grid[i][j];
            }
        }

        //Column wise prefix sum
        vector<vector<int>> colCumSum(rows, vector<int>(cols));

        for(int j = 0; j < cols; j++) {
            colCumSum[0][j] = grid[0][j];
            for(int i = 1; i < rows; i++) {
                colCumSum[i][j] = colCumSum[i-1][j] + grid[i][j];
            }
        }

        //try all possible side squares from each cell
        for(int side = min(rows, cols); side >= 2; side--) {

            for(int i = 0; i + side - 1 < rows; i++) {
                for(int j = 0; j + side - 1 < cols; j++) {

                    int targetSum = rowCumSum[i][j+side-1] - (j > 0 ? rowCumSum[i][j-1] : 0);

                    bool allSame = true;

                    //check remaining rows
                    for(int r = i+1; r < i + side; r++) {
                        int rowSum = rowCumSum[r][j+side-1] - (j > 0 ? rowCumSum[r][j-1] : 0);

                        if(rowSum != targetSum) {
                            allSame = false;
                            break;
                        }
                    }

                    if(!allSame)
                        continue;
                    
                    //check all columns
                    for(int c = j; c < j + side; c++) {
                        int colSum = colCumSum[i+side-1][c] - (i > 0 ? colCumSum[i-1][c] : 0);

                        if(colSum != targetSum) {
                            allSame=false;
                            break;
                        }
                    }

                    if(!allSame)
                        continue;

                    //check both diagonal and antidiagonal
                    int diagSum = 0;
                    int antiDiagSum = 0;

                    for(int k = 0; k < side; k++) {
                        diagSum += grid[i+k][j+k];
                        antiDiagSum += grid[i+k][j+side-1-k];
                    }

                    if(diagSum == targetSum && antiDiagSum == targetSum) {
                        return side;
                    } 
                }
            }
        }

        return 1;
    }
};