#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,c,p;
vector<int> val;
int dp[31][100007]={0};
signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        val.push_back(c);
    }
    cin>>q;
    vector<int> money[q];
    int sum[q]={0};
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cin>>p;
            money[i].push_back(p);
            if(j==0) continue;
            sum[i]+=val[j-1]*money[i][j];
        }
        sum[i]=sum[i]-*(money[i].begin());
    }
    memset(dp, 0x3f, sizeof(dp));
    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int k=1;k<=100005;k++)
        {
            if(k>=val[i]){
                dp[i][k]=min(dp[i+1][k],dp[i][k-val[i]]+1);
            }
            else{
                dp[i][k]=dp[i+1][k];
            }
        }
    }
    for(int i=0;i<q;i++)
        cout<<dp[0][sum[i]]<<"\n";
    
    return 0;
}
