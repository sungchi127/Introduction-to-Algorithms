#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n,k,l,w,len=0,count=0,end=0,other=0;
    cin>>n>>l>>k;
    deque<long long int> d;
    for(int i=0;i<n;i++)
    {
        cin>>w;
        d.push_back(w);
    }
    sort(d.begin(),d.end());
    len=d.size();
    
    end=len-1;
    for(int i=0;i<len && count<=end-i;i++)
    {
        int flag=0;
        if(d[count]+d[end-i]<=l)
        {   
            // cout<<count<<" "<<end-i<<" ";
            flag=1;
            count++;
        }
        if(flag==0)
        {
            other++;
        }
    }
 
    
    cout<<(count+other)*2*k;
    return 0;
}