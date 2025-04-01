#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,u,v,w;
const int maxn=5e5+5;
int sta[maxn],des[maxn],vis[maxn]={0};
vector<pair<int,int>> adj1[maxn],adj2[maxn];
struct edge{
    int a,b,w;
};
vector<edge> e;

void dijkstra(vector<pair<int,int>> adj[],int dis[],int source){
    memset(vis,0,sizeof(vis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
    dis[source]=0;
    vis[source]=1;
    que.push(make_pair(0,source));
    while(!que.empty()){
        int u=que.top().second;
        que.pop();
        vis[u]=1;
        for(int i=0;i<(int)adj[u].size();i++){
            int x=adj[u][i].first;
            int w=adj[u][i].second;
            if(dis[x] > dis[u]+w && vis[x]==0){
                dis[x]=dis[u]+w;
                que.push(make_pair(dis[x],x));
            }
        }
    }
}

signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        adj1[u].push_back(make_pair(v,w));
        adj2[v].push_back(make_pair(u,w));
        e.push_back({u,v,w});
    }
    for(int i=0;i<=n;i++){
        sta[i]=1e15;
        des[i]=1e15;
    }
    dijkstra(adj1,sta,1);
    dijkstra(adj2,des,n);
    int shortpath=sta[n];
    for(int i=0;i<m;i++){
        int left=sta[e[i].a];
        int right=des[e[i].b];
        int least=shortpath-left-right;
        if(least < 0){
            cout<<"-1"<<"\n";
        }
        else{
            cout<<e[i].w-least<<"\n";    
        }
    }
    return 0;
}

