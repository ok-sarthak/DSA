//Approach - 1: Using simple conversion
//T.C : O(n^2) - Iterating on each string and converting each character to integer
//S.C : O(n) - Using set
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        unordered_set<int> st;

        for(string &num : nums) {
            st.insert(stoi(num, 0, 2));
        }

        string result = "";

        for(int i = 0; i <= 65536; i++) {
            if(st.find(i) == st.end(i)) {
                result = bitset<16>(i).to_string();

                return result.substr(16-n, n);
            }
        }

        return "";
    }
};


//Approach - 2: (Improving Approach - 1 code) - We no need to check from 0 to 65536. Only need to check from 0 to n
//T.C : O(n^2) - Iterating on each string and converting each character to integer
//S.C : O(n) - Using set
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        unordered_set<int> st;

        for(string &num : nums) {
            st.insert(stoi(num, 0, 2));
        }

        string result = "";

        for(int i = 0; i <= n; i++) {
            if(st.find(i) == st.end(i)) {
                result = bitset<16>(i).to_string();

                return result.substr(16-n, n);
            }
        }

        return "";
    }
};


//Approach - 3: By discarding matching characters in each position
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        string result = "";

        for(int i = 0; i < n; i++) {
            char ch = nums[i][i];

            result += (ch == '0') ? "1" : "0";
        }

        return result;
    }
};