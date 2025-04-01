#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
map<string,int> dic;
class node {
    public:
        string val;
        int freq;
        node* lchild;
        node* rchild;

        node(){}
        node(string _val, int _freq, node* _lchild, node* _rchild){
            val=_val;
            freq = _freq;
            lchild= _lchild;
            rchild= _rchild;
        }
};

struct cmp{
    bool operator()(const node *child,const node *parent) const{
        if(child->freq != parent->freq)
            return child->freq > parent->freq;
        return child->val > parent->val;
    }
};
unordered_map<string,int> m;
priority_queue<node*, vector<node*>, cmp> q;
const int MAXN = 1e6+5;
node memory[MAXN];
node* ppptttrrr = memory;
vector<string> inp[MAXN];

int binarybit(int x)
{
    int count=0,sum=1;
    while(x>sum)
    {
        sum*=2;
        count++;
    }
    return count;
}

void plancode(node *ptr, int num){
    if(ptr->lchild == nullptr || ptr->rchild == nullptr){
        dic[ptr->val] = num;
        return ;
    }
    if(ptr->lchild) plancode(ptr->lchild, num+1);
    if(ptr->rchild) plancode(ptr->rchild, num+1);
}

signed main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        string str,c;
        getline(cin,str);
        stringstream ss;
        ss.str(str);
        while(ss >> c){
            if(m.count(c)) m[c]++;
            else m[c]=1;
            inp[i].emplace_back(c);
        }
    }

    int strcount=m.size(),bits=0;
    bits=binarybit(strcount);
    //cout<<strcount<<" "<<bits<<endl;

    for(auto it = m.begin();it != m.end();it++)
    {
        *ppptttrrr = node((*it).first,(*it).second,nullptr,nullptr);
        q.emplace(ppptttrrr++);
    }
    for(int i=0;i<(int)m.size()-1;i++)
    {
        node *ptr1= q.top();q.pop();
        node *ptr2= q.top();q.pop();
        string mi=min(ptr1->val,ptr2->val);
        //node *parentnode = new node (mi,ptr1->freq+ptr2->freq,ptr1,ptr2);
        //cout<< ptr1->val << ":" << ptr1->freq<<" "<< ptr2->val << ":" << ptr2->freq<<" "<< "parentnode" << ":" << parentnode->freq<<endl;
        *ppptttrrr = node(mi,ptr1->freq+ptr2->freq,ptr1,ptr2);
        q.emplace(ppptttrrr++);
        //q.push(parentnode);
    }

    plancode(q.top(),0);
    // for(auto &it:dic)
    // {
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    for(int i=0;i<n;i++)
    {
        double mother=0,son=0;
        mother=bits*(int)inp[i].size();
        for(auto &it:inp[i])
        {
            //cout<<it<<" ";
            son+=dic[it];
        }
        //cout<<endl;
        cout<<fixed<<setprecision(10)<<son/mother<<endl; 
    }
    return 0;
}
    // for(auto &it:dic)
    // {
    //     cout<<it.first<<" "<<it.second<<endl;
    // }