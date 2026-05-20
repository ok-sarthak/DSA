class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int>mp1;
        map<int,int>mp2;

        int n = (int)A.size();
        vector<int>ans;

        for(int i = 0 ; i < n ; i++) {
            mp1[A[i]]++;
            mp2[B[i]]++;
            
            int res = 0;

            for(auto x : mp1) {
             res += min(x.second,mp2[x.first]);
            }

            ans.push_back(res);
        }

        return ans;
    }
};