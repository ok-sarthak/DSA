class Solution {
public:

    int n;

    vector<int> t;

    int solve(vector<int>& arr, int d, int i) {
        if (t[i] != -1)
            return t[i];

        int result = 1;

        for (int j = i - 1; j >= max(0, i - d); j--) {

            if (arr[j] >= arr[i])
                break;
            result = max(result, 1 + solve(arr, d, j));
        }

        for (int j = i + 1; j <= min(n - 1, i + d); j++) {

            if (arr[j] >= arr[i])
                break;
            result = max(result, 1 + solve(arr, d, j));
        }

        return t[i] = result;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();

        t.resize(n, -1);

        int maxJump = 1;

        for (int i = 0; i < n; i++) {
            maxJump = max(maxJump, solve(arr, d, i));
        }

        return maxJump;
    }
};