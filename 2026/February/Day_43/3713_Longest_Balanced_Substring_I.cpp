// T.C: O(n^2)
// S.C: O(1)
class Solution {
public:

    bool checkBalanced(vector<int>& cFreq) {
        int common = 0;
        for(int i = 0; i < 26; i++) {
            if(cFreq[i] == 0) continue;

            if(common == 0) {
                common = cFreq[i];
            } else if(common != cFreq[i]) {
                return false;
            }
        }

        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();

        int maxL = 0;
        
        for(int i = 0; i < n; i++) {
            vector<int> cFreq(26, 0);

            for(int j = i; j < n; j++) {
                cFreq[s[j] - 'a']++;

                if(checkBalanced(cFreq)) {
                    maxL = max(maxL, j-i+1);
                }
            }
        }

        return maxL;
    }
};