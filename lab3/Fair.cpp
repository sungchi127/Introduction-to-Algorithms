#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int l[200005],r[200005],f[200005]={};
signed main(){
    int p,sum=0,R,L;
    cin>>n>>p>>L>>R;
    for(int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
    }
    int count=0;
    //過濾包起來的
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i==j)
            {
                continue;
            }
            if(l[i]<=l[j] && r[i]>=r[j])
            {
                l[j]=l[i];
                r[j]=r[i];
            }
        }
    }
    // for (int i = 0; i < n; i++){
    //     cout<<l[i]<<" "<<r[i]<<endl;
    // }
    for(int i=0;i<n;i++)
    { 
        //flag紀錄有沒有人來過
        //flag1判斷count可不可以加
        int flag=0,flag1=0,record=0;
        //1.左界在外，右界在內
        if(l[i]<L && r[i]>=L && r[i]<=R){
            for(int j=L;j<r[i];j++){
                // if(f[j]!=0){
                //     flag=1;
                // }
                f[j]=2;
            }
            if(f[r[i]]==1 || f[r[i]]==2){
                f[r[i]]=2;
            }
            else{
                f[r[i]]=1;
            }
            if(f[r[i]]==2){
                flag=1;
            }
            flag1=1;
            // cout<<"1"<<"~ ";
        }
        //2.左就在內，右界在外
        if(l[i]>=L && l[i]<=R && r[i]>R){
            for(int j=l[i]+1;j<=R;j++){
                // if(f[j]!=0){
                //     flag=1;
                // }
                f[j]=2;
            }
            if(f[l[i]]==1 || f[l[i]]==2){
                f[l[i]]=2;
            }
            else{
                f[l[i]]=1;
            }
            if(f[l[i]]==2){
                flag=1;
            }
            flag1=1;
            // cout<<"2"<<"~ ";
        }
        //3.左右界都在內
        if(l[i]>=L && r[i]<=R ){
            for(int j=l[i]+1;j<r[i];j++){
                // if(f[j]!=0){
                //     flag=1;
                // }
                f[j]=2;
            }

            if(f[r[i]]==1 || f[r[i]]==2){
                f[r[i]]=2;
            }
            else{
                f[r[i]]=1;
            }

            if(f[l[i]]==1 || f[l[i]]==2){
                f[l[i]]=2;
            }
            else{
                f[l[i]]=1;
            }
            flag1=1;
            // cout<<"3"<<"~ ";
        }
        //檢查邊界
        if(f[L]==1){
            f[L]=2;
        }
        if(f[R]==1){
            f[R]=2;
        }
        //檢查
        for(int j=L;j<=R;j++){
            if(f[j]!=2){
                record=1;
            }
            // cout<<f[j]<<" ";
        }
        // cout<<"|"<<flag<<" "<<flag1<<"\n";

        if(flag==0 && flag1==1){
            // cout<<l[i]<<" "<<r[i]<<"\n";
            count++;
        }

        if(record==0){
            sum=count*p;
            break;
        }
    }
    cout<<sum;
    return 0;
}