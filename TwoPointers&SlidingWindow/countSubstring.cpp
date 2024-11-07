Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]


#include <bits/stdc++.h>
using namespace std;

int countSubstring(vector<int> &arr, int k){
    int l = 0, r = 0, cnt = 0;
    unordered_map <int,int> mp;
    while(r < arr.size()){
        mp[arr[r]]++;
        while(mp.size() > k){
            mp[arr[l]]--;
            if(mp[arr[l]]==0) mp.erase(arr[l]);
            l++;
        }
        cnt+=(r-l+1);
        r++;
    }
    return cnt;
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << countSubstring(arr,k) - countSubstring(arr,k-1);

    return 0;
}
