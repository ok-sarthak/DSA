class Solution {
public:

    vector<int> getNSR(vector<int>& height) {
        stack<int> st;

        int n = height.size();

        vector<int> NSR(n);

        for(int i = n-1; i >= 0; i--) {
            if(st.empty()) {
                NSR[i] = n;
            } else {
                while(!st.empty() && height[st.top()] >= height[i]) {
                    st.pop();
                }

                if(st.empty()) {
                    NSR[i] = n;
                } else {
                    NSR[i] = st.top();
                }
            }

            st.push(i);
        }

        return NSR;
    }

    vector<int> getNSL(vector<int>& height) {
        stack<int> st;

        int n = height.size();

        vector<int> NSL(n);

        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                NSL[i] = -1; //out of bound index
            } else {
                while(!st.empty() && height[st.top()] >= height[i]) {
                    st.pop();
                }

                if(st.empty()) {
                    NSL[i] = -1;
                } else {
                    NSL[i] = st.top();
                }
            }
            
            st.push(i);
        }

        return NSL;
    }

    int findMaxArea(vector<int>& height) {
        //max(width[i] * height[i])
        //height = height[i]
        //width = width[i] = NSR[i] - NSL[i] - 1

        vector<int> NSR = getNSR(height);
        vector<int> NSL = getNSL(height);

        int n = height.size();

        vector<int> width(n);
        
        for(int i = 0; i < n; i++) {
            width[i] = NSR[i] - NSL[i] - 1;
        }

        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int area = width[i] * height[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
         int m = matrix.size();
         int n = matrix[0].size();

         vector<int> height(n);

         //Add the first row in the height - 1D
         for(int i = 0; i < n; i++) {
            height[i] = (matrix[0][i] == '1') ? 1 : 0;
         }

         int maxArea = findMaxArea(height);

         //Add other rows
         for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '0') {
                    height[j] = 0;
                } else {
                    height[j] += 1;
                }
            }
            maxArea = max(maxArea, findMaxArea(height));
         }

         return maxArea;
    }
};