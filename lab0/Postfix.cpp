#include <iostream>
#include <string.h>
#include<string>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main(){
	stack<long long int> st;
	string str;
	while(cin>>str)
	{
		long long int tmp1=0,tmp2=0,num=0,sum=0;
		if(str=="+")
		{
			tmp1=st.top();
			st.pop();
			tmp2=st.top();
			st.pop();
			sum=((tmp1%mod)+(tmp2%mod))%mod;
			st.push(sum);
		}
		else if(str=="*")
		{
			tmp1=st.top();
			st.pop();
			tmp2=st.top();
			st.pop();
			sum=((tmp1%mod)*(tmp2%mod))%mod;
			st.push(sum);
		}
		else
		{
			num=stoi(str)%mod;
			st.push(num);
		}
	}
		cout<<st.top();
	return 0;
}