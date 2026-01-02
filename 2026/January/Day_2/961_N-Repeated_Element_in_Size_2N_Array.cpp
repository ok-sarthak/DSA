class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int> mp;
        int ans = 0;
        for(int i: nums){
            mp[i]++;
            if(mp[i] > 1){
                ans = i;
                break;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int repeatedNTimes(vector<int>& nums) {
//         unordered_map<int,int> freq;
//         for(int i: nums){
//             freq[i]++;
//             if(freq[i] > 1){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };