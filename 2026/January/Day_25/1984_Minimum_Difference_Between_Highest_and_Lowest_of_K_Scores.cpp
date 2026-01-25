// T.C: O(n log n)
// S.C: O(1), if sorting is not considered, if sorting is considered then it will become O(log n) because C++ uses introsort recursion which takes recursion stack space.
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        int minDiff = INT_MAX;

        sort(begin(nums), end(nums));

        int i = 0;
        int j = k-1;

        while(j < n) {
            int lowElement = nums[i];
            int highElement = nums[j];

            minDiff = min(minDiff, highElement - lowElement);

            i++;
            j++;
        }

        return minDiff;
    }
};

// Simplified version without two pointers:
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int minDiff = INT_MAX;

        for(int i = k-1; i < n; i++) {
            int minElement = nums[i - k + 1];
            int maxElement = nums[i];

            minDiff = min(minDiff, maxElement - minElement);
        }

        return minDiff;
    }
};