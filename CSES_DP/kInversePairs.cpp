class Solution {
public:
    int kInversePairs(int n, int k) {
        const int M=1e9+7;
        vector<vector<int>> t(n+1,vector<int>(k+1,0));
        for(int i=0;i<=n;i++) t[i][0]=1;
        for(int i=1;i<=n;i++){
            long long cumulativeSum=1;
            for(int j=1;j<=k;j++){
                cumulativeSum+=t[i-1][j];
                if(j>=i) cumulativeSum-=t[i-1][j-i];
                t[i][j]=cumulativeSum%M;
            }
        }
        return t[n][k];
    }
};
