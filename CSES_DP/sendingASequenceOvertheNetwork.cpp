
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
	cin >> n;
	int b[n+1];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	bool dp[n+1];
	memset(dp, false, sizeof(dp));
	dp[0] = true;
	for (int i = 1; i <= n; i++) {
		if (i + b[i] <= n && dp[i-1])
			dp[i+b[i]] = true;
		if (i - b[i] - 1 >= 0 && dp[i-b[i]-1])
			dp[i] = true;
	}
    cout<<(dp[n]? "YES":"NO")<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
