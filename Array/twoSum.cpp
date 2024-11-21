// using hashmap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(target-nums[i])!=mp.end()){
                ans.emplace_back(mp[target-nums[i]]);
                ans.emplace_back(i);
                return ans;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};

//two pointer
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            pair<int,int> pr={nums[i],i};
            temp.emplace_back(pr);
        }
        sort(temp.begin(),temp.end());
        int l=0,r=n-1;
        while(l<r){
            int sum=temp[l].first+temp[r].first;
            if(sum==target){
                ans.emplace_back(temp[l].second);
                ans.emplace_back(temp[r].second);
                break;
            }else if(sum<target) l++;
            else r--;
        }
        return ans;
    }
};
