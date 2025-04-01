#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int maxn=1e5+5;
char c;
int n,m,q,u,l,a,b,flag=0,visited[maxn]={0},siz[maxn];
int v[maxn];
vector<pair<int,int>> p,pa,pu;
vector<char> pc;
set<pair<int,int>> s;
vector<string> ans;

int find(int x)
{
    // 當 x 不是頭目，就繼續追本溯源，直到找到頭目。
    if(x == v[x]) return x;
    else return v[x] = find(v[x]);
    // while (x != v[x]){
    //     x = v[x];
    // }
    // return x;
}

signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>m>>q;
    for(int i=0;i<n;i++){
        v[i]=i;       // 每團只有一個人，頭目是自己
        siz[i] = 1;    // 每個頭目都只帶領一個人，那個人是自己。
    }
    for(int i=0;i<m;i++){
        cin>>u>>l;
        int tmp=0;
        if(u > l){
            tmp=u,u=l,l=tmp;
        }
        s.insert(make_pair(u,l));
    }
    for(int i=0;i<q;i++){
        cin>>c>>a>>b;
        pc.push_back(c);
        int tmp=0;
        if(a > b){
            tmp=a,a=b,b=tmp;
        }
        p.push_back(make_pair(a,b));
        if(c=='U'){
            s.erase(make_pair(a,b));
        }
    }
    for(auto it : s){
        u = find(it.first);
        l = find(it.second);
        if (siz[u] < siz[l]){
            v[u] = l;           // x的頭目帶領旗下小弟投靠y的頭目
            siz[l] += siz[u]; // y的頭目增加人數
        }
        else{
            v[l] = u;
            siz[u] += siz[l];
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<v[i]<<" ";
    // }
    //     cout<<endl;
    for(int i = (int)pc.size()-1; i >= 0; i--){
        if(pc[i]=='A'){
            a=find(p[i].first);
            b=find(p[i].second);
            if(a==b){
                ans.push_back("YES");
            }
            else{
                ans.push_back("NO");
            }
        }
        if(pc[i]=='U'){
            u = find(p[i].first);
            l = find(p[i].second);
            if (siz[u] < siz[l]){
                v[u] = l;           // x的頭目帶領旗下小弟投靠y的頭目
                siz[l] += siz[u]; // y的頭目增加人數
            }
            else{
                v[l] = u;
                siz[u] += siz[l];
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
    }
    for(int i=(int)ans.size()-1;i>=0;i--){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
