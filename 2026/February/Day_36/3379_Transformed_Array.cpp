//T.C. : O(n)
//S.C. : O(1) (excluding the space for the result array)
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n, 0);

        for(int i = 0; i < n; i++) {
            int shift = nums[i] % n;

            int newIndex = (i + shift) % n;

            if(newIndex < 0) {
                newIndex += n;
            }

            result[i] = nums[newIndex];
        }

        return result;
    }
};