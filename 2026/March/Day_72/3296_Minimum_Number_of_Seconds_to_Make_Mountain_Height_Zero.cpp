// T.C: O(n * log(Tmax * mountainHeight^2)  ~= O(nlogH) , where Tmax = maximum time among all workers in the input, n = length of workerTimes
// S.C: O(1)
class Solution {
public:

    typedef long long ll;

    bool check_answer(ll mid, vector<int>& wT, int mH) {
        ll h = 0;

        for(int &t : wT) {
            h += (ll)(sqrt(2.0 * mid/t + 0.25) - 0.5);

            if(h >= mH) return true;
        }

        return h >= mH;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime = *max_element(begin(workerTimes), end(workerTimes));

        ll l = 1;
        ll r = (ll)maxTime * mountainHeight * (mountainHeight+1)/2;

        ll result = 0;

        while(l <= r) {
            ll mid = l + (r-l)/2;

            if(check_answer(mid, workerTimes, mountainHeight)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};