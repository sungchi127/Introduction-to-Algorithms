#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG 1 
using namespace std;
#define int long long 

const int maxn=4e5+1000;
int n,m,a,b,vis[maxn]={0},t,low[maxn]={0},stk[maxn]={0},top=0;
int instack[maxn]={0},sccroot[maxn]={0},cnt=0,group[maxn]={0};
vector<int> adj[maxn],contract[maxn],scc[maxn];
int dp[maxn]={0},ans=0;
stack<int> s;

void tarjan_dfs(int num){
    vis[num]=low[num]=++t;
    //stk[top++]=num;
    s.push(num);
    instack[num]=1;
    for(int i=0;i<(int)adj[num].size();i++){
        int next=adj[num][i];
        if(!vis[next]){
            tarjan_dfs(next);
        }
        if(instack[next]){
            low[num]=min(low[num],low[next]);
        }
    }
    if(vis[num]==low[num]){
        int x;
        sccroot[cnt++]=num;
        do{
            //x=stk[--top];
            x=s.top();
            s.pop();
            instack[x]=0;
            contract[num].push_back(x);
            group[x]=num;
        }while(x!=num);
    }
    return ;
}

void tarjan(){
    memset(vis,0,sizeof(vis));
    t=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            tarjan_dfs(i);
        }
    }
}

void scc_dfs(int num){
    vis[num]=1;
    int tmp=0;
    for(int i=0;i<(int)scc[num].size();i++){
        int x=group[scc[num][i]];
        if(vis[x]==0){
            scc_dfs(x);
        }
        if(i==0){
            tmp=x;
        }
        else if(dp[tmp]<dp[x] && i>0){
            tmp=x;
        }
    }
    if((int)scc[num].size()>0){
        dp[num]+=dp[tmp];
     
    }
    if(ans<dp[num]){
        ans=dp[num];
    }
    return ;
}

signed main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    tarjan();
    //建scc樹
    for(int i=0;i<cnt;i++){
        int x=sccroot[i];
        for(int j=0;j<(int)contract[x].size();j++){
            int y=contract[x][j];
            for(auto& it : adj[y]){
                if(group[it]!=group[y]){
                    scc[x].push_back(it);
                }
            }
        }
    }
    //dp初始化
    for(int i=0;i<cnt;i++){
        dp[sccroot[i]]=(int)contract[sccroot[i]].size();
        //cout<<dp[sccroot[i]]<<" ";
    }
    //dp最大值
    memset(vis,0,sizeof(vis));
    for(int i=0;i<cnt;i++){
        if(vis[sccroot[i]]==0){
            scc_dfs(sccroot[i]);
        }
    }
    cout<<ans;
    return 0;
}

// vector<int> e[MAXN], re[MAXN], dag[MAXN];
// vector<int> tp;
// bitset<MAXN> vis;
// int scc[MAXN];
// void dfs1(int x) {
//     vis[x] = true;
//     for (auto i : e[x]) {
//         if (vis[i]) continue;
//         dfs1(i);
//     }
//     tp.emplace_back(x);
// }
// void dfs2(int x, int id) {
//     vis[x] = true;
//     scc[x] = id;
//     for (auto i : re[x]) {
//         if (vis[i]) continue;
//         dfs2(i, id);
//     }
// }

// void kosaraju() {
//     for (int i=0;i<m;++i) {
//         int u,v;
//         cin >> u >> v;
//         e[u].emplace_back(v);
//         re[v].emplace_back(u);
//     }
//     vis.reset();
//     for (int i=0;i<n;++i) {
//         if (!vis[i]) dfs1(i);
//     }
//     int id = 0;
//     for (int i=n-1;i>=0;--i) {
//         int cur = tp[i];
//         if (!vis[cur]) dfs2(cur, id++);
//     }
//     cout << id << endl;
//     for (int i=0;i<n;++i) {
//         for (auto to : e[i]) {
//             if (scc[i] != scc[to]) {
//                 dag[scc[i]].emplace_back(scc[to]);
//             }
//         }
//     }

//     DPPP();
//     cout << ans << endl;
// }