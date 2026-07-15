class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int o = 0;

        int e = 0;

        int cnt = 0;

        for(int i = 1 ; cnt < n ; i += 2) {
            o += i;

            cnt++;
        }

        cnt = 0;

        for(int i = 2 ; cnt < n ; i += 2) {
            e += i;

            cnt++;
        } 
        
        return __gcd(o,e);
    }
};