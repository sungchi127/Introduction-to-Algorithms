#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<long long int> &data,int key)
{
    int low=0,high=data.size()-1;
    while(low<=high)
    {
        int mid=((low+high)/2);
        if(data[mid]==key)
        {
            return mid;
        }
        else if (data[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    vector<long long int> v;
    long long int n,t,count=0,x,ans=0;
    cin>>n>>t;

    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());
    
    for(int i = 0; i < n; i++)
    {   
        if(v[i]==v[i-1] && i-1>=0) continue;
        for (int j = i+1; j < n; j++)
        {
            int loc=0;
            if(j!=i+1 && v[j]==v[j-1]) continue;
            ans=t-v[i]-v[j];
            
            loc=binary_search(v,ans);
            if(j<loc)
            {
                // cout<<v[i]<<" "<<v[j]<<" "<<ans<<"\n";
                count++;
                // cout<<"|"<<flag<<"|";
            }
        }
            
    }
    if(count==0)
    {
        cout<<"FeiDooDoo_Zuo_Wei_Men";
    }
    else
        cout<<count;
    return 0;
}