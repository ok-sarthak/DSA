class Solution {
public:

    vector<int>a;
    int n;

    int solve(int mv , int l , int r, int s1 , int s2) {
        if(l > r) {
            if(s1 >= s2) return 1;

            return 0;
        }

        int ans = 0;

        if(mv%2) {  
            ans = min(solve(mv^1,l+1,r,s1,s2+a[l]),solve(mv^1,l,r-1,s1,s2+a[r]));
        } else {
            ans = max(solve(mv^1,l+1,r,s1+a[l],s2),solve(mv^1,l,r-1,s1 + a[r],s2));
        }

        return ans;
    }

    bool predictTheWinner(vector<int>& nums) {
        a = nums;
        
        n = (int)a.size();

        return solve(0,0,n-1,0,0);
    }
};