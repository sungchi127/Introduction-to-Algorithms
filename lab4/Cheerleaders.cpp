//陳重諺
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int ans[maxn], arr[maxn];
vector<int> vec;
int n;

int solve() {
    vector<int> tmp;
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= n; i++) {
        auto it = lower_bound(begin(tmp), end(tmp), arr[i]);
        if(it == tmp.end()) tmp.push_back(arr[i]);
        else *it = arr[i]; 
        ans[i] += (int)tmp.size();
    }
    tmp.clear();
    for(int i = n; i > 0; i--) {
        auto it = lower_bound(begin(tmp), end(tmp), arr[i]);
        if(it == tmp.end()) tmp.push_back(arr[i]);
        else *it = arr[i]; 
        ans[i] += (int)tmp.size();
    }
    return *max_element(ans + 1, ans + n + 1) - 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int ans = solve();
    for(int i = 1; i <= n; i++) arr[i] = -arr[i];
    ans = max(ans, solve());
    cout << ans << '\n';
    return 0;
}

// 宋哲頤
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long 

// int n,h;
// vector<int> v1,v2,rv1,rv2,cmp1,cmp2,cmp3,cmp4;
// int dp[4][1000005]={0};
// int LIS(int pos,vector<int> &v,int flag,vector<int> &cmp)
// {
//     int size=pos+1;
//     if(size==1) return 1;

//     int x=v[pos];
//     if(x>cmp.back()){
//         cmp.push_back(x);
//     }
//     else{
//         *lower_bound(cmp.begin(),cmp.end(),x)=x;
//     }
//     if((int)cmp.size()>dp[flag][pos-1]){
//         return cmp.size();
//     }
//     else{
//         return dp[flag][pos-1];
//     }
// }
// int RLIS(int pos,vector<int> &v,int flag,vector<int> &cmp)
// {
//     int size=n-pos;
//     if(size==n) return 1;

//     int x=v[pos];
//     if(x>cmp.back()){
//         cmp.push_back(x);
//     }
//     else{
//         *lower_bound(cmp.begin(),cmp.end(),x)=x;
//     }

//     if((int)cmp.size()>dp[flag][pos-1]){
//         return cmp.size();
//     }
//     else{
//         return dp[flag][pos-1];
//     }
// }

// signed main(){
//     int ans=0;
//     cin.tie(0);
//     cin.sync_with_stdio(0);
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>h;
//         v1.push_back(h);
//     }
//     for(int i=n-1;i>=0;i--){
//         v2.push_back(v1[i]);
//     }
//     for(int i=0;i<n;i++){
//         rv1.push_back(-v1[i]);
//     }
//     for(int i=0;i<n;i++){
//         rv2.push_back(-v2[i]);
//     }
//     cmp1.push_back(v1[0]);
//     cmp2.push_back(v2[0]);
//     cmp3.push_back(rv1[0]);
//     cmp4.push_back(rv2[0]);
//     for(int i=0;i<n;i++){
//         dp[0][i]=LIS(i,v1,0,cmp1);
//         dp[1][i]=RLIS(i,v2,1,cmp2);
//         dp[2][i]=LIS(i,rv1,2,cmp3);
//         dp[3][i]=RLIS(i,rv2,3,cmp4);
//     }

//     for(int i=0,j=n-1;i<n;i++,j--)
//     {
//         if(ans<max(dp[0][i]+dp[1][j]-1,dp[2][i]+dp[3][j]-1))
//             ans=max(dp[0][i]+dp[1][j]-1,dp[2][i]+dp[3][j]-1);

//     }
//     cout<<ans;
//     return 0;
// }
