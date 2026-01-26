//T.C: O(N log N) due to sorting
//S.C: O(1) ignoring the output space
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();

        sort(begin(arr), end(arr));

        int minAbsDiff = INT_MAX;

        vector<vector<int>> result;

        for(int i = 1; i < n; i++) {
            minAbsDiff = min(minAbsDiff, arr[i] - arr[i-1]);
        }

        for(int i = 1; i < n; i++){
            if(arr[i] - arr[i-1] == minAbsDiff) {
                result.push_back({arr[i-1], arr[i]});
            }
        }

        return result;
    }
};