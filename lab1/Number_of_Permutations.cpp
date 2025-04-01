#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main(){
    long long int n,c,pum=1,count=0;
    cin>>n;
    vector<long long int> v;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        if(c>n)
        {
            c=n;
        }
        v.push_back(c);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        pum=(((v[i]-count)%mod)*(pum%mod))%mod;
        count++;
    }
    cout<<pum;
    return 0;
}