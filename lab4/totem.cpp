#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e7+5;
const int mod=1e9+7;

void chkmod(int &x)
{
    while(x>=mod) x-=mod; 
}

int t,n,dp[maxn];
signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>t;
    memset(dp,0,sizeof(dp));
    dp[1]=1,dp[2]=3,dp[3]=6;
    for(int i=4;i<maxn;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]*2+dp[i-3];
        chkmod(dp[i]);
    }
    for(int i=0;i<t;i++)
    {
        cin>>n;
        cout<<(dp[n]*4-3+mod)%mod<<"\n";
    }
    return 0;
}