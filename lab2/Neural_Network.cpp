#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e6 + 5;
const int mod = 1e9 + 7;

vector<int> vec[maxn];
int c[maxn];
int n;

int DFS(int start)
{
    if(vec[start].empty())
    {
        return c[start];
    }
    int ret=0;
    for(int itr : vec[start])
    {
        ret+=DFS(itr);
    }
    return (ret*c[start])%mod;
}

signed main(){
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(int i=0;i<n-1;i++)
    {
        int x; cin >> x;
        vec[x-1].push_back(i+1);
    }
    int ans = DFS(0);
    cout<<ans;
    return 0;
}

// int DFS(int start,vector<int> vec[])
// {
//     if(vec[start].empty()) return c[start];
//     int ret = 0;
//     for(int y : vec[start]) {
//         ret += DFS(y, vec);
//     }
//     return ret * c[start] % mod;
// }
