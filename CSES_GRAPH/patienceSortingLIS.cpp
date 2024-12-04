class Solution {
    public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sorted;
        for(int i=0;i<nums.size();i++){
            auto it=lower_bound(sorted.begin(),sorted.end(),nums[i]);
            if(it==sorted.end()){
                sorted.push_back(nums[i]);
            }else{
                *it=nums[i];
            }
        }
        return sorted.size();
    }
};

//TC -> NLOGN
