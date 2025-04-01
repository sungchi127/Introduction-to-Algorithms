#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s[2000005]={},in[2000005]={},post[2000005]={},pin[2000005]={};
int ans=0;
void f(int x,int il,int ir,int pl,int pr)
{
    // cout<<s[in[x]-1]<<" "<<x<<" "<<il<<" "<<ir<<" "<<pl<<" "<<pr<<endl;
    int rnum=0;
    if(il>=ir || pl>=pr) return ;
    rnum=ir-x;

    if(ir-x>0)
    {
        if(s[in[x]-1]<s[post[pr-1]-1]) ans++;
        f(pin[post[pr-1]], x+1, ir, pr-rnum, pr-1);
    }

    if(x-il>0)
    {
        if(s[in[x]-1]<s[post[pr-rnum-1]-1]) ans++;
        f(pin[post[pr-rnum-1]], il, x-1, pl, pr-rnum-1);
    }
}

signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);    
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>in[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>post[i];
    }
    for(int i=0;i<n;i++)
    {
        pin[in[i]]=i;
    }

    f(pin[post[n-1]],0,n-1,0,n-1);
    cout<<ans;
    return 0;
}