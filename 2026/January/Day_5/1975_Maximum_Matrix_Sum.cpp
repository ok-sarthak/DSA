class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); //n*n matrix

        long long sum = 0;
        int countNegative = 0;
        int smallestAbsoluteValue = INT_MAX;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                sum += abs(matrix[i][j]);

                if(matrix[i][j] < 0) {
                    countNegative++;
                }

                smallestAbsoluteValue = min(smallestAbsoluteValue, abs(matrix[i][j]));
            }
        }

        if(countNegative % 2 == 0) { //even number of negative elements
            return sum;
        }

        return sum - 2*smallestAbsoluteValue;
    }
};