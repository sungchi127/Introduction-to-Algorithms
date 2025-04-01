#include<iostream>
#include<vector>
#include <queue>
#include <string>
#include <map>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int Q,choose;
    map<int,priority_queue<int,vector<int>,greater<int>>> m;
    cin>>Q;
    while(Q--)
    {
        cin>>choose;
        int a,x;
        if(choose==1)
        {
            cin>>a>>x;
            m[a].push(x);
        }
        else
        {
            cin>>a;
            if(m[a].size()==0)
            {
                cout<<"-1"<<"\n";
            }
            else
            {
                cout<<m[a].top()<<"\n";
                m[a].pop();
            }
        }
    }
    return 0;
}