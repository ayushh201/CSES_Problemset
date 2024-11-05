#include<bits/stdc++.h>
using namespace std;
 
 
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int> book(n);
    vector<int> numberOfPages(n);
    for(int i=0;i<n;i++){
        cin>>book[i];
    }
    for(int i=0;i<n;i++){
        cin>>numberOfPages[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    //dp[0][anything]=0 till index 0 nothing included
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            int price=book[i-1];
            int pages=numberOfPages[i-1];
 
            int pick=(j>=price? pages+dp[i-1][j-price]:0);
            int skip=dp[i-1][j];
            dp[i][j]=max(pick,skip);
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
