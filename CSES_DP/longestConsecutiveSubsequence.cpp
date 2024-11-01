/**F. Consecutive Subsequence
time limit per test2 seconds
memory limit per test256 megabytes
You are given an integer array of length 𝑛
.

You have to choose some subsequence of this array of maximum length such that this subsequence forms a increasing sequence of consecutive integers. In other words the required sequence should be equal to [𝑥,𝑥+1,…,𝑥+𝑘−1]
 for some value 𝑥
 and length 𝑘
.

Subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. You can erase any elements, not necessarily going successively. The remaining elements preserve their order. For example, for the array [5,3,1,2,4]
 the following arrays are subsequences: [3]
, [5,3,1,2,4]
, [5,1,4]
, but the array [1,3]
 is not.

Input
The first line of the input containing integer number 𝑛
 (1≤𝑛≤2⋅105
) — the length of the array. The second line of the input containing 𝑛
 integer numbers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the array itself.

Output
On the first line print 𝑘
 — the maximum length of the subsequence of the given array that forms an increasing sequence of consecutive integers.

On the second line print the sequence of the indices of the any maximum length subsequence of the given array that forms an increasing sequence of consecutive integers.**/

#include <bits/stdc++.h>
using namespace std;
 
const int N=2e5+10;
int n,a[N];
int ans,curr;
map<int,int> dp;
std::vector<int> vec; 
 
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[a[i]]=max(dp[a[i]],dp[a[i]-1]+1);
        if(dp[a[i]]>ans){
            ans=dp[a[i]];
            curr=a[i];
        }
    }
    cout<<ans<<endl;
    for(int i=n-1;i>=0;i--){
        if(a[i]==curr){
            curr--;
            vec.push_back(i);
        }
    }
    sort(vec.begin(),vec.end());
    for(int it:vec) cout<<it+1<<" ";
    return 0;
}
