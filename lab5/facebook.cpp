#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int maxn=1e5+5;
char c;
int n,m,q,x,y,a,b,flag=0,visited[maxn]={0};
vector<int> v[maxn];

void dfs(int num,int find){
    visited[num]=1;
    for(int i=0;i<(int)v[num].size();i++){
        if(visited[v[num][i]]==1 || v[num][i]==-1) continue;
        if(find==v[num][i]){
            flag=1;
            return;
        }
        dfs(v[num][i],find);
    }
    return;
}

signed main(){
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=0;i<q;i++){
        cin>>c>>a>>b;
        if(c=='A'){
            memset(visited,0,sizeof(visited));
            flag=0;
            dfs(a,b);
            if(flag==1) cout<<"YES"<<endl;
            if(flag==0) cout<<"NO"<<endl;
        }
        if(c=='U'){
            for(auto& it : v[a]){
                if(it==b){
                    it=-1;
                }
            }
            for(auto& it : v[b]){
                if(it==a){
                    it=-1;
                }
            }
        }

    }
    return 0;
}
