class Solution {
public:
    int smallestNumber(int n, int t) {
        while(1) {
            int d = 1;
            int x = n;
            
            while(x > 0) {
                d *= x % 10;
                
                x/=10;
            }
            
            if(d % t == 0) {
                return n;
            }
            
            ++n;
        }
        
        return n;
    }
};
