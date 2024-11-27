class Solution {
public:
    #define P pair<int,int>
    unordered_map<int,vector<P>> adj;
    int dijkstra(int n){
        vector<int> result(n,1e9);
        result[0]=0;
        priority_queue<P,vector<P>,greater<P>> pq; //min heap
        pq.push({0,0}); //distance,node
        while(!pq.empty()){
            
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(node==n-1) return result[n-1];
            for(auto &p:adj[node]){
                int adjNode=p.first;
                int wt=p.second;
                if(d+wt<result[adjNode]){
                    result[adjNode]=d+wt;
                    pq.push({d+wt,adjNode});
                }
            }
        }
        return result[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n,vector<vector<int>>& queries){
        for(int i=0;i<=n-2;i++){
            adj[i].push_back({i+1,1});
        }
        int q=queries.size();
        vector<int> result;
        for(auto &query:queries){
            int u=query[0];
            int v=query[1];
            adj[u].push_back({v,1});
            int d=dijkstra(n);
            result.push_back(d);
        }
        return result;
    }
};
