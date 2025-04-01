#include<iostream>
#include <map>
#include<queue>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    long long int N,id,p;
    cin>>N;
    queue<int> idq,pq;
    for(int i=0;i<N;i++)
    {
        cin>>id>>p;
        idq.push(id);
        pq.push(p);
    }
    while(idq.size())
    {
        int ptmp=0,idtmp=0;
        cout<<idq.front()<<"\n";
        ptmp=pq.front()-1;
        if(ptmp!=0)
        {
            idtmp=idq.front();
            pq.pop();
            idq.pop();
            pq.push(ptmp);
            idq.push(idtmp);
        }
        else
        {
            pq.pop();
            idq.pop();
        }
    }
    return 0;
}