//Approach 1: Finding first and second minimum elements
//T.C. : O(N)
//S.C. : O(1)
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first_MIN = INT_MAX;
        int second_MIN = INT_MAX;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < first_MIN) {
                second_MIN = first_MIN;
                first_MIN = nums[i];
            } else if(nums[i] < second_MIN) {
                second_MIN = nums[i];
            }
        }

        return nums[0] + first_MIN + second_MIN;
    }
};

//Approach 2: Sorting
//T.C. : O(NlogN)
//S.C. : O(1)
class Solution {
public:
    int minimumCost(vector<int>& nums) {

        sort(nums.begin() + 1, nums.end());
        return nums[0] + nums[1] + nums[2];

    }
};