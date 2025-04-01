#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	long long int n,k,q,s,x,l;
	vector<long long int>spag;
	cin>>n>>k;
	for(long long int i=0;i<n;i++){
		cin>>s;
		spag.push_back(s);
	}
	sort(spag.begin(),spag.end());
	cin>>q;
	for(long long int i=0;i<q;i++){
		long long int ans=0;
		cin>>x>>l;
		vector<long long int>::iterator start=lower_bound(spag.begin(),spag.end(),x);
		long long int target=min(x*k,l);
		vector<long long int>::iterator end=upper_bound(spag.begin(),spag.end(),target);
		for(long long int t=1;t<=k&&x*t<=l;t++){
			vector<long long int>::iterator low=lower_bound(start,end,x*t);
			vector<long long int>::iterator up=upper_bound(start,end,x*(t+1)-1);
			ans+=t*(up-low);
		}
		cout<<ans<<'\n';
	}
	return 0;
}