class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> indegree,outdegree; //node,value
        for(auto &edge:pairs){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }
        int startNode=pairs[0][0];
        for(auto &it:adj){
            int node=it.first;
            if(outdegree[node]-indegree[node]==1){
                startNode=node;
                break;
            }
        }
        vector<int> eularPath;
        stack<int> st;
        st.push(startNode);
        while(!st.empty()){
            int curr=st.top();
            if(!adj[curr].empty()){
                int ngbr=adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            }else{
                eularPath.push_back(curr);
                st.pop();
            }
        }
        reverse(begin(eularPath),end(eularPath));
        vector<vector<int>> result;
        for(int i=0;i<eularPath.size()-1;i++){
            result.push_back({eularPath[i],eularPath[i+1]});
        }
        return result;
    }
};
