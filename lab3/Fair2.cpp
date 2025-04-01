#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int l,r;
vector<pair<int,int>> v;
signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int p,sum=0,L,R;
    cin>>n>>p>>L>>R;
    for(int i=0;i<n;i++)
    {
        cin>>l>>r;
        if(l>=R)
        {
            continue;
        }
        else
        {
            v.push_back(make_pair(l,r));
        }
    }
    int count=0,count1=0;
    l=0,r=L;
    sort(v.begin(),v.end());
    // for(auto &it : v)
    // {
    //     cout<<it.first<<" ";
    // }
    for(int i=0;i<v.size();i++)
    {
        count1++;
        // cout << v[i].first << ' ' << v[i].second << ' ' << r << endl;
        if(v[i].first>r)
        {
            break;
        }
        int tmp=r;
        for(int j=i;j<v.size();j++)
        {
            int flag=0;
            //左邊在右界內
            if(v[j].first<=r && v[j].second>tmp)
            {
                tmp=v[j].second;
            }
            if(v[j].first<=r)
            {
                flag=1;
            }
            if(flag==0)
            {
                i=j-1;
                l=L;
                r=tmp;
                break;
            }
            if(j==v.size()-1)
            {
                i=j;
                r=tmp;
                break;
            }
        }
        // cout<<i<<":"<<l<<" "<<r<<endl;
        count++;
        if(r>=R)
        {
            // cout << count << endl;
            sum=p*count;
            break;
        }
    }
    // cout<<count1<<" "<<l<<" "<<r<<" "<<sum;
    cout<<sum;
    return 0;
}