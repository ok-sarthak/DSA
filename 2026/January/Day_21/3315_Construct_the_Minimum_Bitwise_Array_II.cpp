//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> result;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 2) {
                result.push_back(-1);
                continue;
            } 

            bool found = true;

            for(int j = 1; j < 32; j++) { // starting it from 1 because every odd number lsb is 1
                if((nums[i] & (1 << j)) > 0) { //jth bit is set
                    continue;
                }

                int prev = j - 1;
                
                //set it to 0
                int x = (nums[i] ^ (1 << prev));

                result.push_back(x);

                found = true;
                break;
            }

            if(found == false) {
                result.push_back(-1);
            }
        }

        return result;
    }
};