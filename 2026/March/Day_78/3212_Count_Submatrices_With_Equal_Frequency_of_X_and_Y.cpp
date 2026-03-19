class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> xCount(m, vector<int>(n, 0));
        vector<vector<int>> yCount(m, vector<int>(n, 0));
        
        int count = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
  
                xCount[i][j] = (grid[i][j] == 'X');
                yCount[i][j] = (grid[i][j] == 'Y');
                
                if(i > 0) {
                    xCount[i][j] += xCount[i-1][j];
                    yCount[i][j] += yCount[i-1][j];
                }
                if(j > 0) {
                    xCount[i][j] += xCount[i][j-1];
                    yCount[i][j] += yCount[i][j-1];
                }
                if(i > 0 && j > 0) {
                    xCount[i][j] -= xCount[i-1][j-1];
                    yCount[i][j] -= yCount[i-1][j-1];
                }

                if(xCount[i][j] == yCount[i][j] && xCount[i][j] > 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
};