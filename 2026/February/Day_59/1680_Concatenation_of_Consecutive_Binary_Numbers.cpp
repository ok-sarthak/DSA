//Approach-1 (Using lo2(n) to find bits count)
//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    int M = 1e9+7;
    int concatenatedBinary(int n) {
        long result = 0;

        for(int num = 1; num <= n; num++) {
            int digits = log2(num) + 1;
            
            result = ((result<<digits)%M + num)%M;
        }

        return result;
    }
};


//Approach-2 (Using power of 2 property to find bits count)
//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    int M = 1e9+7;
    int concatenatedBinary(int n) {
        long result = 0;
        int digits = 0;

        for(int num = 1; num <= n; num++) {
            if((num & (num-1)) == 0) //checking num is power of 2
                digits++;
            
            result = ((result<<digits)%M + num)%M;
        }

        return result;
    }
};