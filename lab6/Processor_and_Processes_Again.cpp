#include<bits/stdc++.h> 
using namespace std;
#define int long long 

int n,m,a,b,c,an[205]={0};
struct edge{
    int to ,cap, rev;
    edge(int _to ,int _cap,int _rev): to(_to),cap(_cap),rev(_rev){}
};
vector<edge> adj[205];
unordered_map<int ,pair<int,int>> pre;

void bfs(int s,int t){
    memset(an,0,sizeof(an));
    queue<int> que;
    que.push(s);
    an[s]=1e10+5;
    while(!que.empty()){
        int x=que.front();
        que.pop();
        for(int i=0; i < (int)adj[x].size(); i++){
            edge& g = adj[x][i];
            if(!an[g.to] && g.cap>0){
                pre[g.to] = make_pair(x,i);
                an[g.to] = min(g.cap,an[x]);
                que.push(g.to);
            }
        }
        if(an[t]) break;
    }
}

int Edmonds_Karp(int s,int t){
    int ret = 0;
    while(1){
        bfs(s,t);
        if(an[t] == 0) break;
        int u=t;
        while(u!=s){
            int p = pre[u].first, edge_index=pre[u].second;
            edge& forward_edge = adj[p][edge_index];
            edge& reverse_edge = adj[forward_edge.to][forward_edge.rev];
            forward_edge.cap -= an[t];
            reverse_edge.cap += an[t];
            u = reverse_edge.to;
            //cout<<u<<" "<<p<<endl;
        }
        //cout<<a[t]<<endl;
        ret += an[t];
    }
    return ret;
}

signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        adj[0].push_back({i,a,(int)adj[i].size()});
        adj[i].push_back({0,0,(int)adj[0].size()-1});
    }
    for(int i=1;i<=n;i++){
        cin>>b;
        adj[i].push_back({n+1,b,(int)adj[n+1].size()});
        adj[n+1].push_back({i,0,(int)adj[i].size()-1});
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c,(int)adj[b].size()});
        adj[b].push_back({a,0,(int)adj[a].size()-1});
        adj[b].push_back({a,c,(int)adj[a].size()});
        adj[a].push_back({b,0,(int)adj[b].size()-1});
    }
    int ans=Edmonds_Karp(0,n+1);
    cout<<ans<<"\n";
    return 0;
}