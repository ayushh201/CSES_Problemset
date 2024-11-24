class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            //out of bound remove
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();
            //storing in decreasing faishon
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) ans.emplace_back(nums[dq.front()]);
        }
        return ans;
    }
};
