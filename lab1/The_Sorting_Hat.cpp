#include<bits/stdc++.h>
using namespace std;

struct aca {
    string name;
    int g,h,r,s;
};

string cmp_o;

bool cmp(aca &stud1, aca &stud2) {
    for(int i=0;i<4;i++)
    {   
        if (stud1.g != stud2.g && cmp_o[i]=='G')
            return stud1.g > stud2.g;
        else if(stud1.h != stud2.h && cmp_o[i]=='H')
            return stud1.h > stud2.h;
        else if(stud1.r != stud2.r && cmp_o[i]=='R')
            return stud1.r > stud2.r;
        else if (stud1.s != stud2.s && cmp_o[i]=='S')
            return stud1.s > stud2.s;
    }
        return stud1.name < stud2.name;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long int n;
    cin>>n;
    aca m[n];
    string o[4],sch[4]={"GRYFFINDOR:","HUFFLEPUFF:","RAVENCLAW:","SLYTHERIN:"};
    vector<aca> sv[4];
    for(int i=0;i<4;i++)
    {
        cin>>o[i];
    }
    for(int j=0;j<n;j++)
    {
        cin>>m[j].name>>m[j].g>>m[j].h>>m[j].r>>m[j].s;
    }
    for(int i=0;i<n;i++)
    {
        long long int most=max({m[i].g, m[i].h, m[i].r, m[i].s});
        if(most==m[i].g) sv[0].push_back(m[i]);
        else if(most==m[i].h) sv[1].push_back(m[i]);
        else if(most==m[i].r) sv[2].push_back(m[i]);
        else if(most==m[i].s) sv[3].push_back(m[i]);
    }
    for(int i=0;i<4;i++)
    {
        cmp_o=o[i];
        sort(sv[i].begin(),sv[i].end(), cmp);
    }
    for(int i=0;i<4;i++)
    {
        int l=sv[i].size();
        cout<<sch[i];
        if(l!=0)
        {
            cout<<"\n";
            for(int j=0;j<l;j++)
            {
                cout<<sv[i][j].name<<"\n";
            }
        }
        else
            cout<<" NO NEW STUDENTS"<<"\n";
    }
    return 0;
}
