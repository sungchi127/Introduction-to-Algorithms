#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
long long t = 0;
long long com_num = 0;

void traverse(vector<long long> *adjlist , vector<long long>& dp ,vector<long long>& used , long long cur_com , vector<long long>& component , vector<long long>&num_com)
{
    used[cur_com]=1;
    for(int i=0 ; i<adjlist[cur_com].size() ; i++)
    {
        long long nxt_node = adjlist[cur_com][i];
        long long nxt_com = component[nxt_node];
        if(nxt_com == cur_com)
        {
            continue;
        }
        if(used[component[nxt_node]] == 0)
        {
            traverse(adjlist,dp,used,component[nxt_node],component,num_com);
        }
        dp[cur_com] = max(dp[nxt_com] + num_com[cur_com] , dp[cur_com]);
    }
}


void Tarjan(long long u ,vector<long long> *adjlist , vector<long long> &discnt , vector<long long> &low , vector<bool> &stackMember , stack<long long> &st , vector<long long> *new_adjlist , vector<long long> &component,vector<long long> &num_com)
{
    discnt[u] = low[u] = ++t;
    stackMember[u] = true;
    st.push(u);
    for(int i=0 ; i<adjlist[u].size() ; i++)
    {
        long long t = adjlist[u][i];
        if(discnt[t] == 0 )
        {
            Tarjan(t,adjlist,discnt,low,stackMember,st,new_adjlist,component,num_com);
            if(low[t]<low[u])
            {
                low[u] = low[t];
            }
        }
        else if(stackMember[t]==true && discnt[t] <= low[u])
        {
            low[u] = discnt[t];
        }
    }

    if(discnt[u] == low[u])
    {
        com_num++;
        while(st.top() != u)
        {
            component[st.top()] = com_num;
            num_com[com_num]+=1;
            for(int i=0 ; i<adjlist[st.top()].size() ; i++)
            {
                new_adjlist[com_num].push_back(adjlist[st.top()][i]);
            }
            stackMember[st.top()]=false;
            st.pop();
        }
        component[st.top()] = com_num;
        num_com[com_num]+=1;
        for(int i=0 ; i<adjlist[st.top()].size() ; i++)
        {
            new_adjlist[com_num].push_back(adjlist[st.top()][i]);
        }
        stackMember[st.top()]=false;
        st.pop();
    }
}

void FindStongeComponent(vector<long long> *adjlist ,vector<long long> *new_adjlist,vector<long long> &num_com,  long long ver_num ,vector<long long> &component)
{
    vector<long long> discnt(ver_num,0);
    vector<long long> low(ver_num,0);

    vector<bool> stackMember(ver_num,false);
    stack<long long> st ;

    for(int i=0 ; i<ver_num ; i++)
    {

        if(discnt[i] ==  0)
        {
            Tarjan(i,adjlist,discnt,low,stackMember,st,new_adjlist,component,num_com);
        }
    }
}


int main()
{
    long long  ver_num , edge_num , a , b ,mx=0;
    cin>>ver_num>>edge_num;

    vector<long long> adjlist [ver_num];
    vector<long long> new_adjlist[ver_num+1];
    vector<long long> num_com(ver_num+1,0);
    vector<long long> component(ver_num,0);

    for(int i=0 ; i<edge_num ; i++)
    {
        cin>>a>>b;
        adjlist[a].push_back(b);
    }
    FindStongeComponent(adjlist,new_adjlist,num_com,ver_num,component);

    vector<long long> dp (com_num+1,1);
    vector<long long> used (com_num+1,0);
    for(int i=1 ; i<=com_num ; i++)
    {
        dp[i] = num_com[i];
    }

    for(int i=0 ; i<com_num ; i++)
    {
        if(used[i+1]==0)
        {
            traverse(new_adjlist,dp,used,i+1,component,num_com);
        }
    }

    for(int i=0 ; i<com_num ; i++)
    {
        if(dp[i+1]>mx)
        {
            mx = dp[i+1];
        }
    }
    cout<<mx;
    return 0 ;
}