#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,s,y,b,e,v;
int dp[10000005];
vector<int> year,val,w; 
vector<pair<int,int>> bd;
signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int sum=0;
    cin>>n>>m>>s;
    for(int i=0;i<n;i++){
        cin>>y;
        year.push_back(y);
    }
    sort(year.begin(),year.end());
    for(int i=0;i<m;i++){
        cin>>b>>e>>v;
        bd.push_back(make_pair(b,e));
        w.push_back(v);
    }
    for(int i=0;i<m;i++){
        int tmp=0;
        tmp=upper_bound(year.begin(),year.end(),bd[i].second)-lower_bound(year.begin(),year.end(),bd[i].first);
        sum+=tmp;
        val.push_back(tmp);
    }
    //for(auto it : val) cout<<it<<" ";
    sum=n-sum;
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<m;i++){
        for(int j=s;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+val[i]);
        }
    }
    // for(int i=0;i<s;i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    //cout<<"\n";
    cout<<dp[s]+sum;
    return 0;
}