#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=3e5+5;
int t,n,m,s,x,y,u,v,vis[maxn]={0};
vector<int> adj[maxn],a,b;
int person[maxn],police[maxn],hideout[maxn]={0};


void bfs(int num,int people[]){
    queue<pair<int,int>> que;
    memset(vis,0,sizeof(vis));
    //人或警察做bfs
    if(num==-1){
        for(auto& it : a){
            vis[it]=1;
            que.push(make_pair(it,0));
        }
    }
    else{
        vis[num]=1;
        que.push(make_pair(num,0));
    }
    //bfs
    while(!que.empty()){
        int k=que.front().first, foot=que.front().second;
        que.pop();
        // cout<<k<<" "<<foot<<endl;
        for(int j=0;j<(int)adj[k].size();j++){
            if(adj[k][j] && !vis[adj[k][j]]){
                que.push(make_pair(adj[k][j],foot+1));
                vis[adj[k][j]]=1;
                //找有沒有到hideout
                if(hideout[adj[k][j]]==1){
                    if(people[adj[k][j]]>foot+1){
                        people[adj[k][j]]=foot+1;
                        
                    }
                }    
            }
        }
    }
    return ;
}

signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>s;
        //初始化
        for(int i=0;i<=n;i++){
            person[i]=maxn;
            police[i]=maxn;
        }
        for(int i=0;i<m;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int tmp=0;
        cin>>x;
        a.clear();
        for(int i=0;i<x;i++){
            cin>>tmp;
            a.push_back(tmp);
        }
        cin>>y;
        b.clear();
        memset(hideout,0,sizeof(hideout));
        for(int i=0;i<y;i++){
            cin>>tmp;
            hideout[tmp]=1;
            b.push_back(tmp);
        }

        bfs(s,person);
        bfs(-1,police);
        
        int flag=0;
        for(int i=0;i<y;i++){
            if(police[b[i]]>person[b[i]])
            {
                flag=1;
            }
            //cout<<person[b[i]]<<" "<<police[b[i]]<<endl;
        }
        for(int i=0;i<=n;i++){
            if((int)adj[i].size()!=0){
                adj[i].clear();
            }
        }

        if(flag==0){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}
// 2 0
// 3 1
// 1 1
// 5 2
// 4 2
// 3 0
// 5 1
// 2 1
// 4 2
// 1 2
// 2 0
// 3 1
// 1 1
// 5 2
// 4 2
// 3 0
// 5 1
// 2 1
// 1 2
// 4 3