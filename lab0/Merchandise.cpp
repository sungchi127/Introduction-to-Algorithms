#include<iostream>
#include<vector>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    int Q,choose;
    cin>>Q;
    vector<int> N[n];
    while(Q--)
    {
        cin>>choose;
        int a,x,y;
        if(choose==1)
        {
            cin>>a>>x;
            N[a].push_back(x);
            // cout<<count1[a]<<endl;
        }
        else if(choose==2)
        {
            cin>>a>>y;
            int num=N[a].size()-1;
            // cout<<'|'<<num<<'|'<<y<<endl;
            if(num>=y){
                cout<<N[a][y]<<"\n";
            }
            else
                cout<<"-1"<<"\n";
        }
    }
    return 0;
}