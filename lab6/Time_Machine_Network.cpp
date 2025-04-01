#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e3+5;
int n,m,s,t,d,dis[maxn]={0},k=-1e9-5,flag=0;
vector<pair<int,int>> adj[maxn];
vector<int> neg;

void bellman_ford(){
    fill(dis,dis+maxn,0);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            for(int h=0;h<(int)adj[j].size();h++){
                int next=adj[j][h].first;
                int edge=adj[j][h].second;
                //cout << "chk " << edge << " " << k << "\n";
                if(dis[next] > dis[j]+edge && edge >= k){
                    dis[next]=dis[j]+edge;
                }
            }
        }
    }
    //for (int i = 0; i < n; ++i) cout << dis[i] << " \n"[i == n-1];
}

int negative_circle(){
    for(int i=0;i<n;i++){
        for(int j=0;j<(int)adj[i].size();j++){
            int next=adj[i][j].first;
            int edge=adj[i][j].second;
            //cout<<next<<" "<<edge<<endl;
            //cout<<dis[i]<<" "<<dis[next]<<" "<<dis[i]+edge<<" "<<k<<endl;
            if(dis[next] > dis[i]+edge && edge >= k){
                flag=1;
                return 1;
            }
        }
    }
    //for (int i = 0; i < n; ++i) cout << dis[i] << " \n"[i == n-1];
    return 0;
}

int bisearch(){
    int down=0,up=(int)neg.size()-1,mid=0;
    while(down<up){
        mid=(up+down+1)/2;
        k=neg[mid];
        //cout<<"k:"<<k<<" mid:"<<mid<<" up:"<<up<<" down:"<<down<<endl;
        bellman_ford();
        if(negative_circle()){
            down=mid;
        }
        else{
            up=mid-1;
        }
        //cout<<negative_circle()<<endl;
    }
    return neg[down];
}

signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>s>>t>>d;
        adj[s].push_back(make_pair(t,d));
        if(d<0){
            neg.push_back(d);
        }
    }
    sort(neg.begin(),neg.end());
    bellman_ford();
    negative_circle();
    if(flag==0){
        cout<<"GO AHEAD"<<"\n";
    }
    else{
        int ans=bisearch();
        if(ans==*(prev(neg.end()))){
            cout<<"NO WAY BACK"<<"\n";
        }
        else{
            cout<<ans<<"\n";
        }
    }
    return 0;
}