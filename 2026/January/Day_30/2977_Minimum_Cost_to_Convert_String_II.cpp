//T.C: O(V² * (V + E) * log V)
//S.C: O(V² + E )
class Solution {
public:

    typedef long long ll;
    typedef pair<ll, string> P;

    ll BIG_VALUE = 1e10;

    unordered_map<string, vector<pair<string, ll>>> adj;

    unordered_map<string, unordered_map<string, ll>> dijkstraMemo;

    vector<ll> dpMemo;

    string sourceStr;
    string targetStr;

    set<int> validLengths;

    ll dijkstra(string& start, string& end) {

        if(dijkstraMemo[start].count(end))
            return dijkstraMemo[start][end];

        priority_queue<P, vector<P>, greater<P>> pq; //{Cost, String}

        // vector<ll> result(n, INT_MAX);
        unordered_map<string, ll> result;

        result[start] = 0;

        pq.push({0, start});

        while(!pq.empty()) {
            ll currCost = pq.top().first;
            string currNode = pq.top().second;

            if(currNode == end)
                break;

            pq.pop();

            if(currCost > result[currNode])
                continue;
            
            for(auto &e : adj[currNode]) {
                string adjNode = e.first;
                ll eCost = e.second;

                if(!result.count(adjNode) || currCost + eCost < result[adjNode]) {
                    result[adjNode] = currCost + eCost;
                    pq.push({currCost + eCost, adjNode});
                }
            }
        }

        return dijkstraMemo[start][end] = result.count(end) ? result[end] : BIG_VALUE;
    }

    ll solve(int idx) {

        if(idx >= sourceStr.length())
            return 0;

        if(dpMemo[idx] != -1)
            return dpMemo[idx];

        ll minCost = BIG_VALUE;

        if(sourceStr[idx] == targetStr[idx])
            minCost = solve(idx+1);
        
        for(auto &len : validLengths) {
            if(idx + len > sourceStr.length()) 
                break;
            
            string strSub = sourceStr.substr(idx, len);
            string tarSub = targetStr.substr(idx, len);

            if(!adj.count(strSub))
                continue;

            ll minPathCost = dijkstra(strSub, tarSub);

            if(minPathCost == BIG_VALUE)
                continue;
            
            minCost = min(minCost, minPathCost + solve(idx + len));
        }

        return dpMemo[idx] = minCost;
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {

        sourceStr = source;
        targetStr = target;

        dpMemo.assign(source.length(), -1);

        for(int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        for(auto &s : original) {
            validLengths.insert(s.length());
        }

        ll result = solve(0);

        return result == BIG_VALUE ? -1 : result;
    }
};