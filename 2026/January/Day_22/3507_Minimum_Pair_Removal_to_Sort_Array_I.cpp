//T.C: O(n^2)
//S.C: O(1)
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        int minSum = INT_MAX;

        for(int i = 0; i < n-1; i++){
            int sum = nums[i] + nums[i+1];
            if(sum < minSum) {
                index = i;
                minSum = sum;
            }
        }

        return index;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int opt = 0;

        while(!is_sorted(begin(nums), end(nums))) {
            int index = minPairSum(nums);

            nums[index] = nums[index] + nums[index+1];

            nums.erase(begin(nums) + index + 1);

            opt++;
        }

        return opt;
    }
};