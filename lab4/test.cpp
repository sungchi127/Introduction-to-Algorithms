#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<long long int> a(n);
	for(long long int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<vector<long long int> > sum(n,vector<long long int>(n,0));
	for(long long int i=0;i<n;i++){
		for(long long int j=i;j<n;j++){
			if(j==i){
				sum[i][j]=a[i];
			}
			else{
				sum[i][j]=sum[i][j-1]+a[j];
			}
		}
	}
	vector<vector<long long int> > dp(n,vector<long long int>(n,0));
	long long int f=0;
	long long int temp;
	for(long long int i=2;i<n;i++){	//最後 
		for(long long int j=i-2;j>=0;j--){	//開始 
			for(long long int k=i-2;k>=j;k--){	//中間分段
				if(i==2&&j==0){
					temp=a[0]*a[2]-a[1];
					f=temp;
				}
				else{
					temp=dp[j][k]+sum[j][k]*sum[k+2][i]-a[k+1]+dp[k+2][i];
					if(i==j+2){
						f=temp;
					}
					else{
						f=max(f,temp);
					}
				}
				k--;
			}
			if(i-j!=2){
				temp=sum[j][j]*sum[i][i]-sum[j+1][i-1]+dp[j+1][i-1];
				f=max(f,temp);
			}
			dp[j][i]=f;
			j--;
		}
	}
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
	cout<<dp[0][n-1];
}

