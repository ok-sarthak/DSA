//Approach: Brute Force - Using three nested loops
//T.C: O(n^3) , where n is the size of the input array
//S.C: O(1)
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        int result = INT_MAX;

        for(int i = 0; i < n; i++) {

            for(int j = i+1; j < n; j++) {

                if(nums[i] != nums[j]) continue;

                for(int k = j+1; k < n; k++) {

                    if(nums[j] == nums[k]) {
                        result = min(result, k - i);
                    }
                }
            }
        }

        return result == INT_MAX ? -1 : 2 * result;
    }
};