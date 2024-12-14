class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count=0;
        int i=0,j=0;
        map<int,int> mp;
        while(j<nums.size()){
            mp[nums[j]]++;
            while(abs((mp.rbegin()->first)-(mp.begin()->first))>2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
};
