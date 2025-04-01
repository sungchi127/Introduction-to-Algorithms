#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,t,num;

const int M[8]={0,1000,500,100,50,10,5,1};
signed main(){
    cin>>t;
    while(t--)
    {
        cin.tie(0);
        cin.sync_with_stdio(0);
        cin>>n;
        vector<int> v[n];
        int flag=0,c=0;
        int sum[n]={},less[n]={},count[8]={0};
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<8;i++)
            {
                cin>>num;
                v[j].push_back(num);
                sum[j]+=M[i]*num;
                count[i]+=num;
            }
            if(sum[j]-v[j].front()!=0)
            {
                less[c]=sum[j]-v[j].front();
                c++;
            }
        }
        sort(less,less+c,greater<int>());
        // for(int i=0;i<c;i++)
        // {
        //     cout<<less[i]<<" ";
        // }
        for(int i=0;i<c;i++)
        {
            for(int j=1;j<8;j++)
            {
                if(less[i]>=M[j] && count[j]>0){
                    int t=less[i]/M[j];
                    if(count[j]>=t){
                        less[i]-=M[j]*t;
                        count[j]-=t;
                    }
                    else if(count[j]<t ){
                        less[i]-=M[j]*count[j];
                        count[j]=0;
                    }
                }
            }
            if(less[i]<0 || less[i]>0)
            {
                // cout<<i<<":"<<less[i]<<endl;
                flag=1;
                break;
            }
        }
        if(flag==1)
            cout<<"No"<<"\n";
        else
            cout<<"Yes"<<"\n";
    }
    return 0;
}