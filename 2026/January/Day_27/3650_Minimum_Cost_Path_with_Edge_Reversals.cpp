//Approach - 1 - Using Set
//T.C. - O(E log V)
//S.C. - O(V + E)
class Solution {
public:

    typedef pair<int, int> P;

    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<P>> adj;

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }

        set<P> st;

        vector<int> result (n, INT_MAX);

        result[0] = 0;

        st.insert({0, 0});

        while(!st.empty()) {
            auto &it = *st.begin();
            int d = it.first;
            int node = it.second;

            if(node == n-1) {
                return result[n-1];
            }

            st.erase(it);

            if(d > result[node]) continue;

            for(auto &p : adj[node]) {
                int adjNode = p.first;
                int wt = p.second;

                if( d + wt < result[adjNode]) {
                    if(result[adjNode] != INT_MAX) {
                        st.erase({result[adjNode], adjNode});
                    }

                    result[adjNode] = d + wt;
                    st.insert({d+wt, adjNode});
                }
            }
        }

        return -1;

    }
};

//Approach - 2 - Using Priority Queue
//T.C. - O(E log V)
//S.C. - O(V + E)
class Solution {
public:

    typedef pair<int, int> P;

    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<P>> adj;

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int> result (n, INT_MAX);

        result[0] = 0;

        pq.push({0, 0});

        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;

            if(node == n-1) {
                return result[n-1];
            }

            pq.pop();

            if(d > result[node]) continue;

            for(auto &p : adj[node]) {
                int adjNode = p.first;
                int wt = p.second;

                if( d + wt < result[adjNode]) {
                    result[adjNode] = d + wt;
                    pq.push({d+wt, adjNode});
                }
            }
        }

        return -1;

    }
};