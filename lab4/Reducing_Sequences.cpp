#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,a,tmp=0,l,r,maxtmp=0;
vector<int> v;
int dp[105][105],sum[105][105];

signed main(){
    memset(dp,0,sizeof(dp));
    memset(sum,0,sizeof(sum));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }

    for(int i=0;i<n;i++){
        sum[i][i]=v[i];
        for(int j=i+1;j<n;j++)
        {
            sum[i][j]=v[j]+sum[i][j-1];
        }
    }
    for(int j=2;j<n;j++){
        for(int i=j-2;i>=0;i-=2){
            for(int k=j-2;k>=i;k-=2){
                if(j-i==2){
                    tmp=v[j]*v[i]-v[i+1];
                    maxtmp=tmp;    
                }
                tmp=dp[i][k]+sum[i][k]*sum[k+2][j]-v[k+1]+dp[k+2][j];
                if(maxtmp<tmp) maxtmp=tmp;
            }
            if(j-i!=2){
                tmp=sum[i][i]*sum[j][j]-sum[i+1][j-1]+dp[i+1][j-1];
                if(maxtmp<tmp) maxtmp=tmp;
            }   
            dp[i][j]=maxtmp;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<dp[0][n-1];
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 105;

int arr[maxn], dp[maxn][maxn];
int n;

int cal(int a, int b, int c) {
    return c * a - b;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n; 
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    for(int len = 3; len <= n; len += 2) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            dp[l][r] = -1e18;
            for(int i = l + 1; i <= r; i += 2) {
                for(int j = i; j < r; j += 2) {
                    dp[l][r] = max(dp[l][r], dp[l][i - 1] + dp[i][j] + dp[j + 1][r] + cal(arr[i - 1] - arr[l - 1], arr[j] - arr[i - 1], arr[r] - arr[j]));
                }
            }
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}