#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[2000006]={};

int compare(int l,int r)
{
    int len=r-l+1,tmp[len];
    for(int i=l,j=0;i<=r;i++,j++)
    {
        tmp[j]=a[i];
    }
    // sort(tmp,tmp+len);
    nth_element(tmp, tmp+len/2, tmp+len);
    int x=tmp[len/2],num=0;
    for(int i=0;i<len;i++)
    {
        num += abs(x - tmp[i]);
 
    }
    return num;
}

int good(int l,int r)
{
    if(r-l+1<=2) return 0;
    int mid=(l+r)/2;
    int nl=compare(l,mid);
    int nr=compare(mid+1,r);
    int cmpl=good(l,mid)+nr;
    int cmpr=nl+good(mid+1,r);
    // cout<<l<<" "<<r<<" "<<"nl:"<<nl<<" "<<"nr:"<<nr<<" "<<"cmpl:"<<cmpl<<" "<<"cmpr:"<<cmpr<<"\n";
    return min(cmpl, cmpr);
}

signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ans=good(0,n-1);
    cout<<ans;
    return 0;

}