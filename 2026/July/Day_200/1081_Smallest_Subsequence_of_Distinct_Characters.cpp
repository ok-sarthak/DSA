class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>cnt(26,0);

        for(auto &x : s) {
            cnt[x-'a']++;
        }

        string ans = "";

        int n = (int)s.size();

        vector<int>have(26,0);

        for(int i = 0 ; i < n ; i++) {
            cnt[s[i]-'a']--;

            if(have[s[i]-'a']) continue;

            while(!ans.empty() && s[i] <= ans.back() && cnt[ans.back()-'a'] > 0) {
                have[ans.back()-'a']--;

                ans.pop_back();
            }

            have[s[i]-'a'] = 1;

            ans.push_back(s[i]);
        }
        
        return ans;
    }
};