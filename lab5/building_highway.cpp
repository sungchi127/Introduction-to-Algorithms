#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int maxn=3e5+5;
int t,n,m,k,f,s,a,b,leftbound=0,rightbound=0,edgenum=0,shortedge=0,longedge=0;
char c;
struct edge{
    int a,b,c;
};
vector<edge> e;

//disjoint-sets forest
int p[maxn];
void init() {
    for(int i=0;i<=n+1;++i) 
        p[i]=i;
    return ;
}
int find(int x){
    return x==p[x] ? x:(p[x]=find(p[x]));
}
void merge(int x,int y){
    p[find(x)]=find(y);
    return;
}

bool operator< (edge& e1, edge& e2) {
    return e1.c < e2.c;
}

void kruskal(int num){
    init();
    edgenum=0;
    if(num==1){
        for(int i=0,j=0;i<n-1 && j<m;++j){
            if(find(e[j].a)==find(e[j].b)) continue;
            leftbound+=e[j].c;
            merge(e[j].a,e[j].b);
            i++;
            if(i==n-1) edgenum=1;
        }       
    }
    if(num==2){
        for(int i=n-2,j=m-1;i>=0 && j>=0;--j){
            if(find(e[j].a)==find(e[j].b)) continue;
            rightbound+=e[j].c;
            merge(e[j].a,e[j].b);
            i--;
            if(i < 0) edgenum=1;
        }       
    }
    return ;
}

signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>t;
    while(t--){
        leftbound=0,rightbound=0,longedge=0,shortedge=0;
        e.clear();
        cin>>n>>m>>k>>f>>s;
        for(int i=0;i<m;i++){
            cin>>a>>b>>c;
            if(c=='S'){
                e.push_back({a,b,s});
                shortedge++;
            }
            else{
                e.push_back({a,b,f});
                longedge++;
            }
        }
        sort(e.begin(),e.end());
        if(f==s){
            if((n-1)*f!=k) cout<<"No"<<"\n";
            else{
                kruskal(1);//最小生成樹
                if(edgenum==0){
                    cout<<"No"<<"\n";
                }
                else{
                    cout<<"Yes"<<"\n";   
                }
            }
        }
        else{
            kruskal(2);//最大生成樹
            kruskal(1);//最小生成樹
            if(edgenum==0){
                cout<<"No"<<"\n";
            }
            else{
                if(k<leftbound || k>rightbound){
                    cout<<"No"<<"\n";
                }
                else{
                    int nf = -1;
                    int ns = -1;
                    for(int i = 0; i < n; i ++) {
                        if(f * i + s * (n - 1 - i) == k) {
                            nf = i;
                            ns = n-1-i;
                        }
                    }
                    if(nf==-1 || ns==-1) cout<<"No"<<"\n";
                    else{
                        if(nf > longedge || ns > shortedge){
                            cout<<"No"<<"\n";
                        }
                        else{
                            cout<<"Yes"<<"\n";
                        }
                    }
                }   
            }
        }
    }
    return 0;
}