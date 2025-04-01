#include<bits/stdc++.h>
using namespace std;
#define int long long 
int coun=0;
multiset<int> m1,m2,m3,m4;

signed main(){
    // cin.tie(0);
    // cin.sync_with_stdio(0);
    int a;
    while(cin>>a && a!=0)
    {
        int tmp=0,tmp1=0,tmp2=0,tmp3=0,tmp4=0,tmp5=0;
        double q3=0,q1=0;
        // if(a==0) break;
        coun++;

        if(coun==1){
            m3.insert(a),cout<<'0'<<"\n";
            //cout<<'|'<<m1.size()<<" "<<m2.size()<<" "<<m3.size()<<" "<<m4.size()<<endl;
            continue;
        }
        //cout<<'|'<<m1.size()<<" "<<m2.size()<<" "<<m3.size()<<" "<<m4.size()<<endl;
        if(a>=*m4.begin() && coun!=2) m4.insert(a);
        else if((int)m3.size()==0 || a>=*m3.begin()) m3.insert(a);
        else if((int)m2.size()==0 || a>=*m2.begin()) m2.insert(a);
        else m1.insert(a);
        //cout<<'|'<<m1.size()<<" "<<m2.size()<<" "<<m3.size()<<" "<<m4.size()<<endl;
        //m1m2 v.s. m3m4
        if(((int)m3.size()+(int)m4.size())-((int)m1.size()+(int)m2.size())>=2) tmp=*m3.begin(), m3.erase(m3.begin()), m2.insert(tmp);// cout<<'a'<<" "<<tmp<<endl;
        if(((int)m3.size()+(int)m4.size())-((int)m1.size()+(int)m2.size())<0)  tmp1=*prev(m2.end()),m2.erase(prev(m2.end())),m2.insert(tmp1);// cout<<'b'<<" "<<tmp1<<endl;
        //m1 v.s. m2
        if(((int)m2.size()-(int)m1.size())>=2) tmp2=*m2.begin(), m2.erase(m2.begin()),m1.insert(tmp2);// cout<<'c'<<" "<<m2.size()<<" "<<*m2.begin()<<" "<<m1.size()<<" "<<*m1.begin()<<" "<<tmp2<<endl;
        if(((int)m2.size()-(int)m1.size())<0)  tmp3=*prev(m1.end()), m1.erase(prev(m1.end())), m2.insert(tmp3);// cout<<'d'<<" "<<tmp3<<endl;
        //m3 v.s. m4
        if(((int)m4.size()-(int)m3.size())>=2) tmp4=*m4.begin(), m4.erase(m4.begin()), m3.insert(tmp4);// cout<<'e'<<" "<<tmp4<<endl;
        if(((int)m4.size()-(int)m3.size())<0)  tmp5=*prev(m3.end()), m3.erase(prev(m3.end())), m4.insert(tmp5); //cout<<'f'<<" "<<tmp5<<endl;
        //判斷中位數
        int m3num=0,flag=0;
        if(((int)m2.size()+(int)m1.size()+((int)m4.size()+(int)m3.size()))%2==1)
        {
            m3num=*m3.begin();
            flag=1;
            m3.erase(m3.begin());
        }
        //findQ3
        if((int)m3.size()==0 && (int)m4.size()==2)
        {
            int z=(*m4.begin()+*next(m4.begin()));
            if(z%2==0)
                q3=(*m4.begin()+*next(m4.begin()))/2;
            else
                q3=(*m4.begin()+*next(m4.begin()))/2+0.5;
        }
        else if((int)m3.size()==0 && (int)m4.size()==1)
        {
            q3=*m4.begin();
        }
        else if(((int)m4.size()+(int)m3.size())%2==0 && (int)m4.size()-(int)m3.size()==2){
            int x=(*m4.begin()+*next(m4.begin()));
            if(x%2==0)
                q3=(*m4.begin()+*next(m4.begin()))/2;
            else
                q3=(*m4.begin()+*next(m4.begin()))/2+0.5;
        }
        else if(((int)m4.size()+(int)m3.size())%2==0){
            int x=(*m4.begin()+*prev(m3.end()));
            if(x%2==0)
                q3=(*m4.begin()+*prev(m3.end()))/2;
            else
                q3=(*m4.begin()+*prev(m3.end()))/2+0.5;
        }
        else q3=*m4.begin();
        //findQ1
        if(((int)m2.size()+(int)m1.size())%2==0){
            int y=(*m2.begin()+*prev(m1.end()));
            if(y%2==0)
                q1=(*m2.begin()+*prev(m1.end()))/2;
            else
                q1=(*m2.begin()+*prev(m1.end()))/2+0.5;
        }
        else q1=*m2.begin();
        //cout<<"||"<<m1.size()<<" "<<m2.size()<<" "<<m3.size()<<" "<<m4.size()<<endl;
        //cout<<q3<<" "<<q1<<" "<<q3-q1<<endl;
        cout<<q3-q1<<endl;
        if(flag==1)
        {
            m3.insert(m3num);
        }
    }
    return 0;
}