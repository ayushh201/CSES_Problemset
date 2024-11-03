
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n+1,0);
        set<int> st;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        
        for(int i=n;i>=1;i--){
            int y=arr[i];
            auto itr=st.upper_bound(y);
            if(itr==st.end()){
                st.insert(y);
            }else{
                vector<int> vec;
                while(itr!=st.end()){
                    vec.push_back(*itr);
                    itr++;
                }
                for(int j=0;j<vec.size();j++){
                    st.erase(st.find(vec[j]));
                }
                int size=vec.size();
                st.insert(vec[size-1]);
            }
        }
        
        int elementLeft=st.size();
        if(elementLeft==1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
