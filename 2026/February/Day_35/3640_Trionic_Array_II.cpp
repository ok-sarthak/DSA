// T.C: O(n)
// S.C: O(n)
class Solution {
public:

    typedef long long ll;
    int n;

    vector<vector<ll>> result_memo;

    ll solve(int i, int trend, vector<int>& nums) {

        if(i == n) {
            if(trend == 3) {
                return 0;
            } else {
                return LLONG_MIN/2;
            }
        }

        if(result_memo[i][trend] != LLONG_MIN) {
            return result_memo[i][trend];
        }

        ll skip = LLONG_MIN/2;
        ll take = LLONG_MIN/2;

        if(trend == 0) {
            skip = solve(i+1, 0, nums);
        }

        if(trend == 3){
            take = nums[i];
        }

        if(i+1 < n) {
            int curr = nums[i];
            int next = nums[i+1];

            if(trend == 0 && next > curr) {
                take = max(take, curr + solve(i+1, 1, nums));
            } else if(trend == 1) {
                if(next > curr) {
                    take = max(take, curr + solve(i+1, 1, nums));
                } else if(next < curr) {
                    take = max(take, curr + solve(i+1, 2, nums));
                }
            } else if(trend == 2) {
                if(next < curr) {
                    take = max(take, curr + solve(i+1, 2, nums));
                } else if(next > curr) {
                    take = max(take, curr + solve(i+1, 3, nums));
                }
            } else if(trend == 3 && next > curr) {
                take = max(take, curr + solve(i+1, 3, nums));
            }
        }


        return result_memo[i][trend] = max(take, skip);
    }

    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();

        result_memo.assign(n+1, vector<ll>(4, LLONG_MIN));

        return solve(0, 0 , nums);
    }
};