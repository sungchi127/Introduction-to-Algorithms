#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=5e5+5;
int n,c,q,K,count;
priority_queue<pair<int,int>> q;
vector<int> k;
signed main(){
    cin>>n>>c>>q;
    int rn[n]={maxn};
    for(int i=0;i<q;i++)
    {
        cin>>K;
        k.push_back(K);
    }
    for(int i=n-1;i>=n;i--)
    {
        if(i<rn[k[i]])
            rn[k[i]]=i;
    }
    for(int i=0;i<q;i++)
    {
        
    }

}