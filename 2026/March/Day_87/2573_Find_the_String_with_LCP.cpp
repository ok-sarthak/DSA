//Approach - 1: Using Greedy Allocation + Finding LCP and comparing
//T.C: O(n^2)
//S.C: O(n^2)
class Solution {

    vector<vector<int>> LongestCommonPrefixMatrix (string s) {
        int n = s.length();

        vector<vector<int>> result(n, vector<int>(n, 0));
        
        for (int j = 0; j < n; j ++) {
            result[n-1][j] = result[j][n-1] = (s[j] == s[n-1])? 1 : 0; 
        }
        for (int i = n-2; i >= 0; i --) {
            for (int j = n-2; j >= 0; j --) {
                result[i][j] = (s[i] == s[j])? 1 + result[i+1][j+1] : 0;
            }
        }
        
        return result;
    }
    
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        
        string result (n, 'a');
        
        for (int i = 1; i < n; i ++) {
            vector<bool> not_equal(26, false);

            bool matched = false;
            
            for (int j = 0; j < i; j ++) {
                if (lcp[j][i] == 0) {
                    not_equal[result[j] - 'a'] = true;

                    continue;
                }
                
                matched = true;

                result[i] = result[j];

                break;
            }
        
            if (matched) continue;

            for (int j = 0; j < 26; j ++) {
                if (not_equal[j]) continue;
                
                result[i] = (char)('a' + j);

                break;
            }
        }
        
        if (LongestCommonPrefixMatrix(result) == lcp) return result;
        
        return "";
    }
};

//Approach - 2: Using Greedy Allocation + Without finding LCP
//T.C: O(n^2)
//S.C: O(n) , for word
class Solution {
public:

    bool checkLCP(string &word, vector<vector<int>>& lcp) {
        int n = word.length();

        for(int i = 0; i < n; i++) {

            if(word[i] != word[n-1]) {
                if(lcp[i][n-1] != 0) return false;
            } else {
                if(lcp[i][n-1] != 1) return false;
            }
        }

        for(int j = 0; j < n; j++) {

            if(word[n-1] != word[j]) {
                if(lcp[n-1][j] != 0) return false;
            } else {
                if(lcp[n-1][j] != 1) return false;
            }
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {

                if(word[i] == word[j]) {
                    if(lcp[i][j] != 1 + lcp[i+1][j+1]) return false;
                } else {
                    if(lcp[i][j] != 0) return false;
                }
            }
        }

        return true;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        string word(n, '$');

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(lcp[j][i] != 0) {
                    word[i] = word[j];
                    
                    break;
                }
            }


            if(word[i] == '$') {
                vector<bool> forbidden(26, false);

                for(int j = 0; j < i; j++) {

                    if(lcp[j][i] == 0) {
                        forbidden[word[j] - 'a'] = true;
                    }
                }

                for(int idx = 0; idx < 26; idx++) {

                    if(forbidden[idx] == false) {
                        word[i] = idx + 'a';
                        break;
                    }
                }

                if(word[i] == '$') return "";
            }
        }

        return checkLCP(word, lcp) == true ? word : "";
    }
};