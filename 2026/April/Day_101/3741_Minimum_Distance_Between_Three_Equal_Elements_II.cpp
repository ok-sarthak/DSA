//Approach: Optimal - Using map for storing indices and checking for 3 indices for a number
//T.C: O(n)
//S.C: O(n)
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        int result = INT_MAX;

        for(int k = 0; k < n; k++) {
            mp[nums[k]].push_back(k);

            if(mp[nums[k]].size() >= 3) {
                vector<int> &vec = mp[nums[k]];

                int size = vec.size();

                int i = vec[size - 3];

                result = min(result, k - i);
            }
        }

        return result >= INT_MAX ? -1 : 2*result;
    }
};