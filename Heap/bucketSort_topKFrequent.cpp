class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int &num:nums){
            mp[num]++;
        }
        vector<vector<int>> bucket(n+1);
        for(auto &it:mp){
            int value=it.first;
            int frequency=it.second;
            bucket[frequency].push_back(value);
        }
        vector<int> ans;
        for(int i=n;i>=0;i--){
            if(bucket[i].size()==0) continue;
            while(bucket[i].size()>0 && k>0){
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return ans;//TC N
    }
};
