class Solution {
public:
    #define P pair<int,int>
    unordered_map<int,vector<int>> adj;
    int bfs(int n){
        queue<int> q;
        q.push(0);
        vector<bool> visited(n,false);
        visited[0]=true;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int node=q.front();
                q.pop();
                if(node==n-1) return level;
                for(int &nbr:adj[node]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr]=true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n,vector<vector<int>>& queries){
        for(int i=0;i<=n-2;i++){
            adj[i].push_back(i+1);
        }
        int q=queries.size();
        vector<int> result;
        for(auto &query:queries){
            int u=query[0];
            int v=query[1];
            adj[u].push_back(v);
            int d=bfs(n);
            result.push_back(d);
        }
        return result;
    }
};
