class Solution {
public:
    int helper(vector<int>& nums,int op,int mask,vector<int> &dp){
        int n=nums.size()/2;int m=nums.size();
        if(op>n) return 0;
        if(dp[mask]!=-1) return dp[mask];
        for(int i=0;i<m;i++){
            if((mask & (1<<i))) continue;
            for(int j=i+1;j<m;j++){
                if((mask & (1<<j))) continue;
                int newMask=(1<<i)|(1<<j)|mask;
                int score=op*__gcd(nums[i],nums[j])+helper(nums,op+1,newMask,dp);
                dp[mask]=max(dp[mask],score);
            }
        }
        return dp[mask];
    }
    int maxScore(vector<int>& nums) {
        vector<int> dp(1<<14,-1);
        return helper(nums,1,0,dp); //nums,operation=1,mask=initially zero,dp
    }
};
