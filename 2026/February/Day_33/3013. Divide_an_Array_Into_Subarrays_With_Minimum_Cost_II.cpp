//T.C. : O(NlogK)
//S.C. : O(K)
class Solution {
public:

    typedef long long ll;
    typedef pair<int, int> P;

    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        set<P> kMin;
        set<P> rem;

        ll sum = 0;

        int i = 1;

        while(i - dist < 1) {
            kMin.insert({nums[i], i});
            
            sum += nums[i];

            if(kMin.size() > k - 1) {
                P temp = *kMin.rbegin();

                sum -= temp.first;

                rem.insert(temp);
                kMin.erase(temp);
            }

            i++;
        }

        ll result = LONG_MAX;

        while(i < n) {
            kMin.insert({nums[i], i});
            
            sum += nums[i];

            if(kMin.size() > k - 1) {
                P temp = *kMin.rbegin();

                sum -= temp.first;

                rem.insert(temp);
                kMin.erase(temp);
            }

            result = min(result, sum);

            P remove = {nums[i-dist], i-dist};

            if(kMin.count(remove)) {
                kMin.erase(remove);

                sum -= remove.first;

                if(!rem.empty()) {
                    P temp = *rem.begin();

                    kMin.insert(temp);

                    sum += temp.first;

                    rem.erase(temp);
                }
            } else {
                rem.erase(remove);
            }

            i++;
        }

        return nums[0] + result;        
    }
};