class Solution {
public:
    vector<int>dx = {0,0,1,-1};
    vector<int>dy = {1,-1,0,0};

    bool findSafeWalk(vector<vector<int>>& a, int health) {
        int n = (int)a.size();
        int m = (int)a[0].size();

        vector<vector<int>>h(n,vector<int>(m,-1e7));
        
        queue<vector<int>>q;
        
        if(!a[0][0]) {
         q.push({0,0,health});

         h[0][0] = health;
        } else {
         q.push({0,0,health-1});

         h[0][0] = health-1;
        }
        while(!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            int H = q.front()[2];

            q.pop();

            for(int k = 0 ; k < 4 ; k++) {
                int ii = i + dx[k];
                int jj = j + dy[k];

                if(ii < n && ii >= 0 && jj < m && jj >= 0) {
                    int hN = H;

                    if(a[ii][jj]) hN--;

                    if(hN > h[ii][jj]) {
                        h[ii][jj] = hN;

                        q.push({ii,jj,hN});
                    }
                }
            }
        }

        return h[n-1][m-1] >= 1;
    }
};