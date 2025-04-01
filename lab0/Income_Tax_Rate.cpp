#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
    int N,M;
    cin>>N;
    int a[N];
    double r[N];
    for(int i=0;i<N;i++)
    {
        cin>>a[i]>>r[i];
    }
    cin>>M;
    double money[M];
    double tax[N]={},sum[M]={};
    for(int i=1;i<N;i++){
        tax[i]=(a[i]-a[i-1])*r[i-1]+tax[i-1];
        // cout<<tax[i]<<"|"<<endl;
    }
    for(int i=0;i<M;i++)
    {
        cin>>money[i];
    }
    
    for(int i=0;i<M;i++){
        int count=0,flag=1;
        if(money[i]<a[0])
        {
            flag=0;
        }
        for(int j=1;j<N;j++)
        {
            if(money[i]>=a[j])
            {
                count++;
            }
        }
        // for(int j=0;j<=count;j++)
        // cout<<tax[count]<<"|"<<a[count]<<"|"<<r[count]<<endl;
        sum[i]=tax[count]+(money[i]-(a[count]-1))*r[count];
        // cout<<sum[i]<<"\n";
        if(flag==1)
            cout << setprecision(7) << sum[i] << "\n";
        else
            cout<<"0"<<"\n";
    }
    return 0;
}