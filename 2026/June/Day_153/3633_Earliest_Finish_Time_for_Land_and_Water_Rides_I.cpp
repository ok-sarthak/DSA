class Solution {
public:

    int timeReq(int x , int xD , int y , int yD) {
        int tt = x + xD;
        
        y = max(y,tt);

        return y + yD;
    }
    
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = (int)landStartTime.size();
        int m = (int)waterStartTime.size();

        int ans = 2e9;

        for(int i = 0 ; i < n ; i++) {

            for(int j = 0 ; j < m ; j++) {

                int x = landStartTime[i];
                int xD = landDuration[i];
                int y = waterStartTime[j];
                int yD = waterDuration[j];

                ans = min(ans,timeReq(x,xD,y,yD));
                ans = min(ans,timeReq(y,yD,x,xD));
            }
        }

        return ans;
    }
};