//T.C: O(n log n)
//S.C: O(1)
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int result = 0;

        int i = 0;
        int j = n-1;

        while(i < j) {
            int sum = nums[i] + nums[j];
            
            result = max(result, sum);

            i++;
            j--;
        }

        return result;
    }
};