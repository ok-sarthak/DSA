class Solution {
public:

    int m, n;

    int t[501][501];

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if(i == m || j == n) return -1e9;

        if(t[i][j] != -1e9) return t[i][j];

        int val = nums1[i] * nums2[j];

        int take_i_j = (nums1[i] * nums2[j]) + solve(nums1, nums2, i+1, j+1);

        int take_i = solve(nums1, nums2, i, j+1);

        int take_j = solve(nums1, nums2, i+1, j);

        return t[i][j] = max({val, take_i_j, take_i, take_j});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();

        //Without Memo -> T.C = (2^(m+n)), With Memo -> T.C = (m+1 * n+1) =(m*n)

        //memset(t, -1, sizeof(t)); -1 can't be set, because answer can be -1

        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                t[i][j] = -1e9;
            }
        }

        return solve(nums1, nums2, 0, 0);
    }
};