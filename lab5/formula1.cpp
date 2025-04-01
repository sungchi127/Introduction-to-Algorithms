#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int INF=1e18;
const int maxn=211000;
const int mod=1e9+7;
int n,m,start,des,wei,sum=0;
int visited[maxn]={0},dis=0;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
vector<pair<int,int>> v[maxn],mst[maxn];
vector<int> pre,key,vis,sz;

void dfs(int num,int x){
    visited[num]=1,sz[num] = 1;
    for(int i=0;i<(int)mst[num].size();i++){
        int y = mst[num][i].first;
        if(visited[y]==1) continue;
        dfs(y,mst[num][i].second);
        sz[num] += sz[y];
    }
    dis = (dis + (((sz[num] * (n - sz[num])) % mod) * x) % mod) % mod;
    return ;
}

signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>start>>des>>wei;
        v[start].push_back(make_pair(des,wei));
        v[des].push_back(make_pair(start,wei));
    }
    for(int i=0;i<=n;i++){
        pre.push_back(-1);
        key.push_back(INF);
        vis.push_back(0);
        sz.push_back(0);
    }
    key[1]=0;
    q.push(make_pair(0,1));
    //prim
    while(q.size()) {
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int j=0;j<(int)v[u].size();j++){
            if(vis[v[u][j].first]==0 && v[u][j].second<key[v[u][j].first]){
                pre[v[u][j].first]=u;
                key[v[u][j].first]=v[u][j].second;
                q.push(make_pair(v[u][j].second,v[u][j].first));
                //cout<<v[u][j].first<<" "<<v[u][j].second<<" ";
            }
        }
    }

    //計算問題1跟建最小生成樹
    for(int i=1;i<=n;i++){
        if(pre[i]!=-1){
            for(int j=0;j<(int)v[i].size();j++){
                if(v[i][j].first==pre[i] ){
                    sum=(sum+(v[i][j].second*2) % mod) % mod;
                    mst[i].push_back(make_pair(v[i][j].first,v[i][j].second));
                    mst[v[i][j].first].push_back(make_pair(i,v[i][j].second));
                    break;
                }
            }
        }
    }
    int flag=0;
    //確認有沒有全部點相連2
    for(int i=1;i<=n;i++){
        if((int)mst[i].size()==0){
            flag=1;
        }
    }
    //dfs全點對
    memset(visited,0,sizeof(visited));
    dfs(1,0);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<key[i]<<" ";
    // }
    // for(int i=1;i<=n;i++){
    //     cout<<i<<":";
    //     for(auto& it : mst[i]){
    //         cout<<it.first<<" ";
    //     }
    //     cout<<endl;
    // }
    if(flag==1){
        cout<<"-1";
    }
    else{
        cout<<sum<<" "<<(dis*2)%mod;
    }
    return 0;
}
// 7 11
// 1 2 5
// 1 6 3
// 2 3 10
// 2 5 1
// 2 7 4
// 3 4 5
// 3 7 8
// 4 5 7
// 4 7 9
// 5 6 6 
// 5 7 2
