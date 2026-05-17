//Approach - 1: DFS with in-place visited marking
//T.C: O(n)
//S.C: O(n) , recursion stack space
class Solution {
public:

    int n;

    bool dfs(vector<int>& arr, int i) {
        if(i < 0 || i >= n || arr[i] < 0) {
            return false;
        }

        if(arr[i] == 0)
            return true;

        arr[i] *= -1;

        int left  = dfs(arr, i - arr[i]);
        int right = dfs(arr, i + arr[i]);

        return left || right;
    }

    bool canReach(vector<int>& arr, int start) {
        n = arr.size();

        return dfs(arr, start);
    }
};


//Approach - 2: BFS with in-place visited marking
//T.C: O(n)
//S.C: O(n) , queue space
class Solution {
public:
    bool bfs(vector<int>& arr, int start, int n) {
        queue<int> que;

        que.push(start);

        while(!que.empty()) {
            int curr = que.front();
            
            que.pop();

            if(arr[curr] == 0)
                return true;

            if(arr[curr] < 0)
                continue;

            int left  = curr + arr[curr];
            int right = curr - arr[curr];

            if(left >= 0 && left < n)
                que.push(left);

            if(right >= 0 && right < n)
                que.push(right);

            arr[curr] = -arr[curr];
        }

        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        int n = (int) arr.size();

        return bfs(arr, start, n);
    }
};