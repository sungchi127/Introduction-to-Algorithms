#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,t,c;
int v[2005][2005]={0};
int dp[2005][2005]={0};

signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>t;
    for(int i=0;i<t;i++){
        for(int j=0;j<n;j++){
            cin>>c;
            if(i==t-1){
                dp[t-1][j]=c;
            }
            else{
                dp[i][j]=-1000000000005;
            }
            v[i][j]=c;
        }
    }
    //dp表
    for(int i=t-2;i>=0;i--){
        for(int j=0;j<n;j++){
            if(j==0 && n>1){
                dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+v[i][j];
                continue;
            }
            if(j==n-1 && n>1){
                dp[i][j]=max(dp[i+1][j-1],dp[i+1][j])+v[i][j];
                continue;
            }
            if(n<2){
                dp[i][j]=dp[i+1][j]+v[i][j];
            }
            else{
                dp[i][j]=max({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]})+v[i][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<dp[0][i]<<"\n";
    }

    return 0;
}
