#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> dp(x+1,0);
    dp[0]=1;
    for(int i=0;i<=x;i++){
        for(int j=0;j<n;j++){
            if(a[j]<=i){
                dp[i]=(dp[i]+dp[i-a[j]])%mod;
            }
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}
