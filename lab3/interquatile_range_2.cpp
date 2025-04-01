#pragma GCC optimize("Ofast", "unroll-loops")
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<queue>
#include<set>
using namespace std;
// #define int long long 
multiset<int> m1,m2,m3,m4;
int coun=0,l,r;
signed main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,tmp;
    long long int q1,q3;
    while(cin>>a && a!=0)
    {
        a *= 2;
        coun++;
        if(coun==1)
        {
            m2.insert(a);
            m3.insert(a);
            cout<<"0"<<'\n';
            continue;
        }
        l=coun/4;
        r=coun-l;
        //左邊
        if((int)m1.size()<l)
        {
            if(*m2.begin()>=a)
            {
                m1.insert(a);
            }
            else
            {
                tmp=*m2.begin();
                m2.erase(m2.begin());
                m2.insert(a);
                m1.insert(tmp);
            }
        }
        else if((int)m2.size() < r)
        {
            if((int)m1.size()==0)
            {
                m2.insert(a);
            }
            else if(*prev(m1.end())<=a)
            {
                m2.insert(a);
            }
            else
            {
                tmp=*prev(m1.end());
                m1.erase(prev(m1.end()));
                m1.insert(a);
                m2.insert(tmp);
            }
        }
        //右邊
        if((int)m4.size() < l)
        {
            if(*prev(m3.end()) <= a)
            {
                m4.insert(a);
            }
            else
            {
                tmp = *prev(m3.end());
                m3.erase(prev(m3.end()));
                m3.insert(a);
                m4.insert(tmp);
            }
        }
        else if((int)m3.size()<r)
        {
            if((int)m4.size()==0)
            {
                m3.insert(a);
            }
            else if(*m4.begin() >= a)
            {
                m3.insert(a);
            }
            else
            {
                tmp = *m4.begin();
                m4.erase(m4.begin());
                m4.insert(a);
                m3.insert(tmp);
            }
        }
        //答案
        if((coun/2)%2==0)
        {
            q1=*m2.begin()/2 + *prev(m1.end())/2;
            q3=*m4.begin()/2 + *prev(m3.end())/2;
            //cout<<q1<<" "<<q3<<" ";
        }
        else
        {
            q1=*m2.begin();
            q3=*prev(m3.end());
        }

        if((q3-q1)%2!=0)
        {
           
            cout<<(q3-q1)/2<<".5"<<'\n';
        }
        else
        {
            cout<<(q3-q1)/2<<'\n';
        }
    }
    return 0;
}