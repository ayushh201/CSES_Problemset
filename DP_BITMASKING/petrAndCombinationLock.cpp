#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    bool flag=false;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int mask=0;mask<(1<<n);mask++){
        int sum=0;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)) sum+=arr[i];
            else sum-=arr[i];
        }
        if(sum%360==0){
            flag=true;
            break;
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
