#include <bits/stdc++.h>
using namespace std;

void dfs(int row,int col,vector<vector<char>>&a,int n,int m){
    a[row][col]='0';
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    for(int i=0;i<4;i++){
        char nrow=row+delrow[i];
        char ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && a[nrow][ncol]=='.'){
            dfs(nrow,ncol,a,n,m);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='.'){
                c++;
                dfs(i,j,a,n,m);
            }
        }
    }
    cout<<c<<endl;
    return 0;
}
