class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        for(auto &x : patterns) {
            if(word.find(x) != -1) ++ans;
        }
        
        return ans;
    }
};