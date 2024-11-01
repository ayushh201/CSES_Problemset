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
