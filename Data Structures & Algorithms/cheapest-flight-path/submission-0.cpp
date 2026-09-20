class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &edge : flights){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            auto [stops, nodeInfo] = q.front();
            q.pop();

            int u = nodeInfo.first;
            int cost = nodeInfo.second;

            for(auto &edge : adj[u]){
                int v = edge.first;
                int wt = edge.second;

                if(dist[v] > cost + wt && stops <= k){
                    dist[v] = cost + wt;
                    q.push({stops+1, {v, cost + wt}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
