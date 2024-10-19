#include<bits/stdc++.h>
using namespace std;

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
    vector<int> dp(x+1,1e9);
    dp[0]=0;
    for(int i=0;i<=x;i++){
        for(int j=0;j<n;j++){
            if(a[j]<=i){
                dp[i]=min(dp[i],dp[i-a[j]]+1);
            }
        }
    }
    cout<<(dp[x]<1e9? dp[x]:-1)<<endl;
    return 0;
}
