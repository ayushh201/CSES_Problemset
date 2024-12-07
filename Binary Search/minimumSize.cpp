https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag

class Solution {
public:
    bool isPossible(vector<int>& nums, int maxOperations,int mid){
        int totalOperations=0;
        for(int num:nums){
            int total=num/mid;
            if(num%mid==0) total--;
            totalOperations+=total;
        }
        if(totalOperations<=maxOperations) return true;
        return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,maxOperations,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
