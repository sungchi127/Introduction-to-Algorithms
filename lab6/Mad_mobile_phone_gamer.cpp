#include<bits/stdc++.h>
using namespace std;
#define int long long
 
const int maxn=1e15;
int n,m,a,b,w,k,f,t,dp[501][501]={0},flag[501][501]={0};
vector<pair<int,int>> adj[501],query;

void floyd_warshall(){
    for(int i=0; i<n; i++){
        for(auto& it : adj[i]){
            dp[i][it.first] = min(it.second, dp[i][it.first]);
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][k]+dp[k][j]<dp[i][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                }
            }
        }
    }
    return ;
}

signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(b,w));
    }
    for(int i=0;i<501;i++){
        for(int j=0;j<501;j++){
            if(i==j){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=maxn;
            }
        }
    }
    floyd_warshall();
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>f>>t;
        if(dp[f][t] >= maxn){
            cout<<"-1"<<"\n";
        }
        else{
            cout<<dp[f][t]<<"\n";
        }
    }
    return 0;
}