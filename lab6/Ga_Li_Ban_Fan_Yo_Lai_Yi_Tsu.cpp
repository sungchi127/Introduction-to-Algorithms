#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5;
int f,n,m,L,P,S,C,T,x,y,cx,K,cnt=0,a[500005]={0},ans=0,res[maxn]={0};
struct edge{
    int to ,cap, rev;
    edge(int _to ,int _cap,int _rev): to(_to),cap(_cap),rev(_rev){}
};
vector<edge> e[maxn];
vector<pair<int,int>> l,p,ss;
unordered_map<int ,pair<int,int>> pre;

void bfs(int s,int t){
    memset(a,0,sizeof(a));
    queue<int> que;
    que.push(s);
    a[s]=1e10+5;
    while(!que.empty()){
        int x=que.front();
        que.pop();
        for(int i=0; i < (int)e[x].size(); i++){
            edge& g = e[x][i];
            if(!a[g.to] && g.cap>0){
                pre[g.to] = make_pair(x,i);
                a[g.to] = min(g.cap,a[x]);
                que.push(g.to);
            }
        }
        if(a[t]) break;
    }
}

int Edmonds_Karp(int s,int t){
    int ret = 0;
    while(1){
        bfs(s,t);
        if(a[t] == 0) break;
        int u=t;
        while(u!=s){
            int p = pre[u].first, edge_index=pre[u].second;
            edge& forward_edge = e[p][edge_index];
            edge& reverse_edge = e[forward_edge.to][forward_edge.rev];
            forward_edge.cap -= a[t];
            reverse_edge.cap += a[t];
            u = reverse_edge.to;
            //cout<<u<<" "<<p<<endl;
        }
        //cout<<a[t]<<endl;
        ret += a[t];
    }
    return ret;
}

signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>f>>n>>m;
    //建flow圖
    cnt++;
    for(int i=0;i<f;i++){
        cin>>L;
        cnt+=2;
        int from=cnt-2,to=cnt-1;
        //源頭
        //cout<<from<<" "<<to<<endl;
        e[0].push_back(edge(from,1e12,(int)e[from].size()));
        e[from].push_back(edge(0,0,(int)e[0].size()-1));
        //farmer
        e[from].push_back(edge(to,L,(int)e[to].size()));
        e[to].push_back(edge(from,0,(int)e[from].size()-1));
        l.push_back(make_pair(from,to));
    }
    for(int i=0;i<n;i++){
        cin>>P;
        cnt+=2;
        int from=cnt-2,to=cnt-1;
        //factory
        e[from].push_back(edge(to,P,(int)e[to].size()));
        e[to].push_back(edge(from,0,(int)e[from].size()-1));
        p.push_back(make_pair(from,to));
    }
    for(int i=0;i<m;i++){
        cin>>S;
        cnt+=2;
        int from=cnt-2, to=cnt-1;
        //store
        e[from].push_back(edge(to,S,(int)e[to].size()));
        e[to].push_back(edge(from,0,(int)e[from].size()-1));
        ss.push_back(make_pair(from,to));
    }
    cin>>C;
    for(int i=0;i<C;i++){
        cin>>x>>y>>cx;
        //farmer->factory
        int from=l[x-1].second, to=p[y-1].first;
        e[from].push_back(edge(to,cx,(int)e[to].size()));
        e[to].push_back(edge(from,0,(int)e[from].size()-1));
    }
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>x>>y>>cx;
        //factory->store
        int from=p[x-1].second, to=ss[y-1].first;
        e[from].push_back(edge(to,cx,(int)e[to].size()));
        e[to].push_back(edge(from,0,(int)e[from].size()-1));
    }
    cin>>K;
    cnt++;
    for(int i=0;i<m;i++){
        int from=ss[i].second, to=cnt-1;
        e[from].push_back(edge(to,K,(int)e[to].size()));
        e[to].push_back(edge(from,0,(int)e[from].size()-1));
    }

    ans=Edmonds_Karp(0,cnt-1);
    ans=min(K,ans);
    cout<<ans;

    return 0;
}
