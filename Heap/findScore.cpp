class Solution {
public:
    #define P pair<int,int>
    long long findScore(vector<int>& nums) {
        priority_queue<P,vector<P>,greater<P>> pq;
        
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        long long totalScore=0;
        vector<bool> visited(nums.size(),false);
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int element=it.first;
            int idx=it.second;
            if(!visited[idx]){
                visited[idx]=true;
                totalScore+=element;
                if(idx-1>=0 && !visited[idx-1]) visited[idx-1]=true;
                if(idx+1<nums.size() && !visited[idx+1]) visited[idx+1]=true;
            }
        }
        return totalScore;
    }
};
