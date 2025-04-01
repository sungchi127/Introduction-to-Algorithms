#include<bits/stdc++.h>
#define int long long 
using namespace std;
int count1,count2;
int issmall(char str)
{
    if(str>='a' && str<='z')
    {
        return 1;
    }
    else
        return 0;
}

int isnum(char str)
{
    if(str>='0' && str<='9')
    {
        return 1;
    }
    else 
        return 0;
}
signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    map<string,int> m;
    vector<pair<string,int>> v;
    stack<pair<string,int>> sta; 
    string s;
    cin>>s;
    int size=s.size();
    int len1;
    len1=s.size();
    for(int i=0;i<len1;i++)
    {
        int len=0;
        if (s[i]=='(')
        {
            string tmp;
            tmp=s[i];
            sta.push(make_pair(tmp,1));
            // cout<<tmp<<'|'<<endl;
        }
        else if(s[i]==')')
        {
            int num=0,count=0;
            string tmp;
            tmp='(';
            if(i+1>=size)
            {
                num=1;
                count++;
            }
            else
            {
                for(int j=i+1;isnum(s[j])==1;j++)
                {
                    num=num*10+(s[j]-'0');
                    count++;
                }
            }
            while(sta.top().first!=tmp)
            {
                sta.top().second*=num;
                v.push_back(make_pair(sta.top().first,sta.top().second));
                sta.pop();
            }
            sta.pop();
            len=v.size();
            for(int j=0;j<len;j++)
            {
                sta.push(v[j]);
                // cout<<sta.top().first<<" "<<sta.top().second<<endl;
            }
            // for(auto &it : v)
            // {
            //     cout<<it.first<<" "<<it.second<<endl;
            // }
            v.clear();
            i+=count;
            // cout<<tmp<<'|'<<endl;
        }
        else if(issmall(s[i+1]) && i+1<size)
        {
            int num=0,count=1;
            string tmp="  ";
            tmp[0]=s[i];
            tmp[1]=s[i+1];
            if(isnum(s[i+2])==0 || i+2>=size){
                sta.push(make_pair(tmp,1));
                i+=1;
            }
            else{
                for(int j=i+2;isnum(s[j])==1;j++)
                {
                    num=num*10+(s[j]-'0');
                    count++;
                }
                sta.push(make_pair(tmp,num));
                i+=count;
            }
            // cout<<tmp<<'|'<<endl;
        }
        else
        {
            int num=0,count=0;
            string tmp;
            tmp=s[i];
            if(isnum(s[i+1])==0 || i+1>=size)
            {
                sta.push(make_pair(tmp,1));
            }
            else
            {
                for(int j=i+1;isnum(s[j])==1;j++)
                {
                    num=num*10+(s[j]-'0');
                    count++;
                }
                // cout<<tmp<<'|'<<endl;
                sta.push(make_pair(tmp,num));
                i+=count;
            }
            // cout<<i<<tmp<<endl;
        }
    }

    int len=sta.size();
    for (int i = 0; i <len; i++)
    {
        if(m[sta.top().first]==0)
        {
            m[sta.top().first]=sta.top().second;
        }
        else
        {
            m[sta.top().first]+=sta.top().second;
        }
        // cout<<'1'<<sta.top().first<<endl;
        // cout<<'2'<<sta.top().first<<endl;

        sta.pop();
    }
    for(auto &it : m)
    {
        if(it.first.size()==1)
        {
           count1++;
        }
    }
    for(auto &it : m)
    {
        if(it.first.size()==2)
        {
            count2++;
        }
    }
    cout<<count1<<"\n";
    for(auto &it : m)
    {
        if(it.first.size()==1)
        {
            cout<<it.first<<":"<<it.second<<"\n";
        }
    }
    cout<<count2<<"\n";
    for(auto &it : m)
    {
        if(it.first.size()==2)
        {
            cout<<it.first<<":"<<it.second<<"\n";
        }
    }
    return 0;
}
//(A(B23)2)2