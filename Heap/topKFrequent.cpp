class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int &num:nums){
            mp[num]++;
        }
        priority_queue<p,vector<p>,greater<p>> pq;
        for(auto &it:mp){
            int value=it.first;
            int frequency=it.second;
            pq.push({frequency,value});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;//TC NLOGK
    }
};
