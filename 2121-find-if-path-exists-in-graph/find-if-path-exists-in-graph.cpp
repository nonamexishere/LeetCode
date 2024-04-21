class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        stack<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int top = q.top();
            q.pop();
            if (top == destination) return true;
            for (int node : adj[top]) {
                if (!visited[node]) {
                    q.push(node);
                    visited[node] = true;
                }
            }
        }
        return false;
    }
};