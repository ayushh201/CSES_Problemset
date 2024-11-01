
#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7, n=2e5+10;
int r,g,h,ans,cnt[n];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin>>r>>g;
    for(h=cnt[0]=1;h*(h+1)/2<=r+g;h++){
        for(int i=n-1;i>=h;i--){
            (cnt[i]+=cnt[i-h])%=mod;
        }
    }
    h--;
    for(int i=0;i<=r;i++){
        if(h*(h+1)/2-i<=g) (ans+=cnt[i])%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
