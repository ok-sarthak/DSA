class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int curr = nums[0];
        
        vector<int> result;

        for (int i = 0; i < nums.size();) {
            if (curr < nums[i]) {
                result.push_back(curr);
            } else {
                i++;
            }
            
            curr++;
        }

        return result;
    }
};
