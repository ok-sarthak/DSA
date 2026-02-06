// T.C: O(n log n + 2 * n) = O(n log n)
// S.C: O(1)
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int maxElement = nums[0];
        int minElement = nums[0];

        int i = 0;
        int j = 0;

        int L = 1;

        while(j < n) {
            minElement = nums[i];
            maxElement = nums[j];

            while(i < j && maxElement > (long long)k * minElement) {
                i++;
                minElement = nums[i];
            }

            L = max(L, j-i+1);

            j++;
        }

        return n - L;
    }
};