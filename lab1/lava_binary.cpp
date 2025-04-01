#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> vc(n);
	vector<int> vp(n);
	for(int i=0;i<n;i++){
		cin>>vc[i]>>vp[i];
	}
	double left=0.0;
	double right=1000000000.0;
	while(fabs(right-left)>0.000001)
	{
		double mid=(left+right)/2;
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			long long int temp=(vc[i]/mid)-vp[i];
			if(temp<=0)
			{
				continue;
			}
			ans+=temp;
		}
		if(k<=ans)
		{
			left=mid;
		}
		else
		{
			right=mid;
		}
	}
	cout << setprecision(7) << (left+right)/2;
	return 0;
}