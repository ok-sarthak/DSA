//Approach - 1: Backtracking template - storing all possible strings
//T.C: O(n * 3 * 2^(n-1)) ~= O(n*2^n)
//S.C: O(n * 2^n) , total 2^n strings eaching having length n
class Solution {
public:

    void solve(int n, string &curr, vector<string>& result) {
        if(curr.length() == n) {
            result.push_back(curr);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++) {
            if(!curr.empty() && curr.back() == ch) continue;

            curr.push_back(ch);

            solve(n, curr, result);

            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";

        vector<string> result;

        solve(n, curr, result);

        if(result.size() < k) return "";

        return result[k-1];
    }
};


//Approach - 2: Khandani Backtracking template - Without storing all possible strings
//T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
//S.C : O(n) , by recursion system 
class Solution {
public:

    void solve(int n, string &curr, int &count, int k, string &result) {
        if(curr.length() == n) {
            count++;

            if(count == k) {
                result = curr;
            }
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++) {
            if(!curr.empty() && curr.back() == ch) continue;

            curr.push_back(ch);

            solve(n, curr, count, k, result);

            if(!result.empty()) return;

            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        string result = "";
        int count = 0;

        solve(n, curr, count, k, result);

        return result;
    }
};